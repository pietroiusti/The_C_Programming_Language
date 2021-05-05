#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/* p. 179. 

The standard library function int fseek(FILE *fp, long offset, int
origin) is identical to lseek except that fp is a file pointer instead
of a file descriptor and return value is an int status, not a
position. Write fseek. Make sure that your fseek coordinates properly
with the buffering done for the other functions of the library. */

// #define NULL     0
#define EOF      (-1)
#define BUFSIZ  4 //1024
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
int _flushbuf(int , FILE *);
int fflush(FILE *);
int fclose(FILE *fp);
int gp_fseek(FILE *fp, long offset, int origin);

#define feof(p)    (((p)->flag & _EOF) != 0)
#define ferror(p)  (((p)->flag & _ERR) != 0)
#define fileno(p)  ((p)->fd)

#define getc(p)    (--(p)->cnt >= 0					\
		    ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x, p) (--(p)->cnt >= 0				\
		    ? *(p)->ptr++ = (x) : _flushbuf((x),p))

#define getchar()  getc(stdin)
#define putchar(x)  putc((x), stdout)


#define PERMS 0666 /* RW for owner, group, others */

FILE *fopen(char *name, char *mode);

int main(void)
{
    /* FILE *fp1; */
    FILE *fp2;

    /* fp1 = fopen("./cat.c", "r"); */

    /* int c; */

    /* while ((c = getc(fp1)) != EOF) */
    /* 	write(1, &c, 1); */

    fp2 = fopen("./hello-world.txt", "w");

    char *s = "hello world!";
    for (int i = 0; s[i] != '\0'; i++) {
	putc(s[i], fp2);
    }

    fflush(fp2);

    gp_fseek(fp2, 0L, 0);
    
    putc('!', fp2);

    fflush(fp2);

    //fflush(NULL);

    //fclose(fp1);
    //fclose(fp2);

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
    /* Answer: everything is automatically set to 0*/
    
    if (fp >= _iob + OPEN_MAX) /* no free slots */
	return NULL;
    /* Why do we need to test for greater than? Wouldn't fp == _iob +
     * OPEN_MAX suffice? How could fp point beyond _iob+OPEN_MAX? */
    /* Answer: ``defensive programming''... */

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

/* _flushbuf: flush buffer or allocate one if not allocated yet */
int _flushbuf(int x, FILE *fp)
{
    // _flushbuf is called only when no charater has been written into
    // the output file yet, or when we need to flush because the base
    // buffer is full. In both cases, fp->cnt is supposed to be -1.
    int bufsize;
    if ((fp->flag&(_WRITE|_ERR) != _WRITE))
	return EOF;
    bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;

    if (fp->base == NULL)
	if ((fp->base = (char *) malloc(bufsize)) == NULL)
	    return EOF;

    if (fp->ptr == fp->base + bufsize)
	write(fp->fd, fp->base, bufsize);

    fp->cnt = bufsize;
    fp->ptr = fp->base;

    if (--fp->cnt < 0) {
	fp->flag |= _ERR;
	fp->cnt = 0; //perhaps unnecessary.. but it doesn't hurt
	return EOF;
    }

    return (unsigned char) (*fp->ptr++ = x);
}

/* Write any buffered data for fp. Return EOF for a write error, 0
 * otherwise. fflush(NULL) flushes all output streams. */
int fflush(FILE *fp)
{
    int flush(FILE *fp) {
	int bytestowrite = BUFSIZ - fp->cnt;
	if (write(fp->fd, fp->base, bytestowrite) != bytestowrite)
	    return EOF;
	fp->cnt = 0;
	fp->ptr = fp->base;
    }

    if (fp == NULL) {
	// Loop over FILE structs in _iob, skipping stdin, stdout and
	// stderr
	for (fp = _iob+3; fp < _iob + OPEN_MAX; fp++)
	    if ((fp->flag & (_WRITE|_ERR)) != _WRITE)
		if (flush(fp)==EOF)
		    return EOF;
    } else
	return flush(fp);

    return 0;
}

/* fclose: flush unwritten data, discard unread buffered input, free
 * any automatically allocated buffer, and close the stream. Return
 * EOF if error, zero otherwise. */
int fclose(FILE *fp)
{
    if (fp->flag & _WRITE)
	if (fflush(fp) == EOF) {
	    fp->flag |= _ERR;
	    return EOF;
	}

    free(fp->base);

    return close(fp->fd) == -1 ? EOF : 0;
}

int gp_fseek(FILE *fp, long offset, int origin) {
    if ((fp->flag&_ERR) || (fp->flag&(_READ|_WRITE) == 0))
	return -1;

    int bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
    lseek(fp->fd, offset, origin);

    if (fp->flag & _READ) {
	fp->ptr = fp->base;
	read(fp->fd, fp->ptr, bufsize);
	fp->cnt = bufsize;
    } else if (fp->flag & _WRITE) {
	fp->cnt = BUFSIZ;    
	fp->ptr = fp->base;
    }

    return 0;
}
