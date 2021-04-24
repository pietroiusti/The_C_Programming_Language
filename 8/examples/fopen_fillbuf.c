#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// #define NULL     0
#define EOF      (-1)
#define BUFSIZ  1024
#define OPEN_MAX 20  /* max #files open at once */

typedef struct _iobuf {
    int  cnt;   /* characters left */
    char *ptr;  /* next character position */
    char *base; /* location of the buffer */
    int flag;   /* mode of file access */
    int fd;     /* file descriptor */
} FILE;

enum _flags {
    _READ    = 01,    /* file open for reading */
    _WRITE   = 02,    /* file open for writing */
    _UNBUF   = 04,    /* file is ubuffered */
    _EOF     = 010,   /* EOF has occurred on this file */
    _ERR     = 020    /* error occurred on this file */
};

//extern FILE _iob[OPEN_MAX];
FILE _iob[OPEN_MAX] = { /* stdin, stdout, stderr */
    { 0, (char *) 0, (char *) 0, _READ, 0 },
    { 0, (char *) 0, (char *) 0, _WRITE, 1 },
    { 0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 }
};

#define stdin    (&_iob[0])
#define stdout   (&_iob[1])
#define stderr   (&_iob[2])

int _fillbuf(FILE *);
int _fllushbuf(int , FILE *);

#define feof(p)    (((p)->flag & _EOF) != 0)
#define ferror(p)  (((p)->flag & _ERR) != 0)
#define fileno(p)  ((p)->fd)

#define getc(p)    (--(p)->cnt >= 0					\
		    ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x, p) (--(p)->cnt >= 0		\
		    ? *(p)->ptr++ = (x) : _flushbuf((x),p))

#define getchar()  getc(stdin)
#define putchar()  putc((x), stdout)


#define PERMS 0666 /* RW for owner, group, others */

FILE *fopen(char *name, char *mode);

int main(void)
{
    FILE *fp1, *fp2;

    char buf[10000];

    fp1 = fopen("./test.c", "r");

    int c;
    while ((c = getc(fp1)) != EOF)
	write(1, &c, 1);
    
    return 0;
}

/* fopen: open file, return file ptr */
FILE *fopen(char *name, char *mode)
{
    int fd;
    FILE *fp;

    if (*mode != 'r' && *mode != 'w' && *mode != 'a')
	return NULL;
    for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
	if ((fp->flag & (_READ | _WRITE)) == 0)
	    break; /* found free slot */
    /* atm only the first FILEs in the _iob array have been
     * initialized. Isn't it problem that fp points to garbage? */

    if (fp >= _iob + OPEN_MAX) /* no free slots */
	return NULL;
    /* Why do we need to test for greater than? Wouldn't fp == _iob +
     * OPEN_MAX suffice? How could fp point beyond _iob+OPEN_MAX? */
    
    if (*mode == 'w')
	fd = creat(name, PERMS);
    else if (*mode == 'a') {
	if ((fd = open(name, O_WRONLY, 0)) == -1) // this opens for
						  // writing a file
						  // that already
						  // exists
	    fd = creat(name, PERMS); // this opens for writing a file
				     // that does not already exist
	lseek(fd, 0L, 2);
    } else
	fd = open(name, O_RDONLY, 0);
    if (fd == -1) // couldn't access name
	return NULL;
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag = (*mode == 'r') ? _READ : _WRITE;
    return fp;
}

/* _fillbuf: allocate and fill input buffer */
int _fillbuf(FILE *fp)
{
    int bufsize;
    if ((fp->flag&(_READ|_EOF|_ERR)) != _READ)
	return EOF;
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    if (fp->base == NULL) /* no buffer yet */
	if ((fp->base = (char *) malloc(bufsize)) == NULL)
	    return EOF; /* can't get buffer */
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0) {
	if (fp->cnt == -1)
	    fp->flag |= _EOF;
	else
	    fp->flag |= _ERR;
	fp->cnt = 0;
	return EOF;
    }
    return (unsigned char) *fp->ptr++;
}
