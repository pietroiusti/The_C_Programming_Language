#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/* p. 179. Design and write _flushbuf, fflush, and fclose */

// #define NULL     0
#define EOF      (-1)
#define BUFSIZ  1024
#define OPEN_MAX 20  /* max #files open at once */

struct flags {
    unsigned int read  :1;
    unsigned int write :1;
    unsigned int unbuf :1;
    unsigned int eof   :1;
    unsigned int err   :1;
};

typedef struct _iobuf {
    int  cnt;   /* characters left */
    char *ptr;  /* next character position */
    char *base; /* location of the buffer */
    struct flags flag;   /* mode of file access */
    int fd;     /* file descriptor */
} FILE;

/* enum _flags { */
/*     _READ    = 01,    /\* file open for reading *\/ */
/*     _WRITE   = 02,    /\* file open for writing *\/ */
/*     _UNBUF   = 04,    /\* file is ubuffered *\/ */
/*     _EOF     = 010,   /\* EOF has occurred on this file *\/ */
/*     _ERR     = 020    /\* error occurred on this file *\/ */
/* }; */

//extern FILE _iob[OPEN_MAX];
FILE _iob[OPEN_MAX] = { /* stdin, stdout, stderr */
    /* { 0, (char *) 0, (char *) 0, _READ, 0 }, */
    /* { 0, (char *) 0, (char *) 0, _WRITE, 1 }, */
    /* { 0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 } */
    { 0, (char *) 0, (char *) 0, {1,0,0,0,0}, 0 },
    { 0, (char *) 0, (char *) 0, {0,1,0,0,0}, 1 },
    { 0, (char *) 0, (char *) 0, {0,1,1,0,0}, 2 }
};

#define stdin    (&_iob[0])
#define stdout   (&_iob[1])
#define stderr   (&_iob[2])

int _fillbuf(FILE *);
int _flushbuf(int , FILE *);
int fflush(FILE *);
int fclose(FILE *fp);

#define feof(p)    (((p)->flag & _EOF) != 0)
#define ferror(p)  (((p)->flag & _ERR) != 0)
#define fileno(p)  ((p)->fd)

#define getc(p)    (--(p)->cnt >= 0					\
		    ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x, p) (--(p)->cnt >= 0				\
		    ? *(p)->ptr++ = (x) : _flushbuf((x),p))

#define getchar()  getc(stdin)
#define putchar()  putc((x), stdout)


#define PERMS 0666 /* RW for owner, group, others */

FILE *fopen(char *name, char *mode);

int main(void)
{
    FILE *fp1, *fp2;

    fp1 = fopen("./cat.c", "r");

    int c;

    while ((c = getc(fp1)) != EOF)
	write(1, &c, 1);

    fp2 = fopen("./hello-world.txt", "w");

    char *s = "hello world!";
    for (int i = 0; s[i] != '\0'; i++) {
	putc(s[i], fp2);
    }

    //fflush(fp2);
    //fflush(NULL);

    fclose(fp2);

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
	/* if ((fp->flag & (_READ | _WRITE)) == 0) */
	if (fp->flag.read == 0 && fp->flag.write == 0)
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
    //fp->flag = (*mode == 'r') ? _READ : _WRITE;
    if (*mode == 'r') fp->flag.read = 1;
    else fp->flag.write = 1;

    return fp;
}

/* _fillbuf: allocate and fill input buffer */
int _fillbuf(FILE *fp)
{
    int bufsize;
    /* if ((fp->flag&(_READ|_EOF|_ERR)) != _READ) */
    if (fp->flag.read==0 || fp->flag.eof==1 || fp->flag.err==1)
	return EOF;
    /* bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ; */
    bufsize = (fp->flag.unbuf) ? 1 : BUFSIZ;
    if (fp->base == NULL) /* no buffer yet */
	if ((fp->base = (char *) malloc(bufsize)) == NULL)
	    return EOF; /* can't get buffer */
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0) {
	if (fp->cnt == -1)
	    /* fp->flag |= _EOF; */
	    fp->flag.eof = 1;
	else
	    /* fp->flag |= _ERR; */
	    fp->flag.err = 1;
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
    if (fp->flag.write==0||fp->flag.err==1)
	return EOF;
    bufsize = (fp->flag.unbuf) ? 1 : BUFSIZ;

    if (fp->base == NULL)
	if ((fp->base = (char *) malloc(bufsize)) == NULL)
	    return EOF;

    if (fp->ptr == fp->base + bufsize)
	write(fp->fd, fp->base, bufsize);

    fp->cnt = bufsize;
    fp->ptr = fp->base;

    if (--fp->cnt < 0) {
	fp->flag.err = 1;
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
    }

    if (fp == NULL) {
	// Loop over FILE structs in _iob, skipping stdin, stdout and
	// stderr
	for (fp = _iob+3; fp < _iob + OPEN_MAX; fp++)
	    if (fp->flag.write==1&&fp->flag.err==0)
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
    if (fp->flag.write==1)
	if (fflush(fp) == EOF) {
	    fp->flag.err = 1;
	    return EOF;
	}

    free(fp->base);

    return close(fp->fd) == -1 ? EOF : 0;
}
