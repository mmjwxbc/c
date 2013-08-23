PROTOTYPES:

int creat(char *filename, int octal_perms);

int n_written = write(int fd, char *buf, int n_bufsize);
	if (n_written != n_bufsize)
		fprint(stderr,"%d write error",fd);

lseek():
SEEK_SET
SEEK_CUR
SEEK_END

long lseek(int fd, long offset, int origin);
	
