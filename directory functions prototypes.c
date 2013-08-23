#include <direct.h>

DIR * opendir(const char * pathname);

struct direct * readdir(DIR * dir_ptr);

void rewinddir(DIR * dir_ptr);

int closedir(DIR * dir_ptr);

long telldir(DIR * dir_ptr);

void seekdir(DIR * dir_ptr, long location);

struct stat{
	dev_t       st_dev;     /* ID of device containing file */
	ino_t       st_ino;     /* inode number */
	mode_t      st_mode;    /* protection */
	nlink_t     st_nlink;   /* number of hard links */
	uid_t       st_uid;     /* user ID of owner */
	gid_t       st_gid;     /* group ID of owner */
	dev_t       st_rdev;    /* device ID (if special file) */
	off_t       st_size;    /* total size, in bytes */
	time_t      st_atime;   /* time of last access */
	time_t      st_mtime;   /* time of last modification */
	time_t      st_ctime;   /* time of last status change */
	blksize_t   st_blksize; /* blocksize for filesystem I/O */
	blkcnt_t    st_blocks;  /* number of blocks allocated */
};

#include <sys/stat.h>

int stat(const char * restrict pathname, struct stat * restrict buf);
int lstat(const char * restrict pathname, struct stat * restrict buf);
int fstat(int fd, struct stat * buf);

st_mode
 | | | |u|g|s|r|w|x|r|w|x|r|w|x|
  type	

if ((buf->st_mode S_IFMT) == S_IFREG/* or 0100000 */)

#define S_ISREG(m)
	(((m) & (0170000)) == 0100000)

Constructing a mask:
	S_IFMT	1111 000 000 000 000

int x=0;
~0; // equal to 1

x<<12 //shift 12 to the left

0|1|0|1

0|1|0|0
| //or
0|0|0|1

