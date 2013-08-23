#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <utmp.h>

#define NRECS 16
#define	NULLUT (struct utmp*)NULL
#define UTSIZE sizeof(struct utmp);

/* global variables */
static char utmpbuf[NRECS * UTSIZE];
static int numrecs; /*returned*/
static int currec;  /*location of rec ptr*/
static int fd = -1;

int utmpopen(char *filename)
{
	fd = open(filename, O_RDONLY);
	currec = numrecs = 0;
	return fd;
}

struct utmp * utmp_next(void)
{
	struct utmp* recp;
	if (fd == -1)
		return NULLUT;
	if (currec == numrecs && utmp_reload() == 0)
		return NULLUT;

	recp = (struct utmp*) & wtmpbuf[currec * UTSIZE];
	currec++;
	return recp;
}

int utmpreload(void)
{
	int amt_read = read(fd,utmpbuf,NRECS*UTSIZE);
	numrecs = amt_read/UTSIZE;
	currec = 0;
	return numrecs;
}

#include "wtmplib.c"

int main(int ac, char av[])
{
	struct utmp*utbufp;
	if utmpopen(utmp_file)==-1){
		perror(utmp_file);
		exit(1);}
	
	while(utbufp=utmp_next()!=UTNULL)
		showinfo(utbufp);
	utmp_close();
	return 0;
}
