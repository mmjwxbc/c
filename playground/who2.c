/* who2.c - a second version of the who program
 *		open, read UTMP file, and show results also shows time in a readable way. using ctime()
 * Martin j. Minaya.
 */
#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>	/* open()	*/
#include <unistd.h>	/* read()	*/
#include <time.h>	/* ctime()	*/

#define SHOWHOST	/* include remote machine output */

void showtime(long);
void show_info(struct utmp *);

int main()
{
	struct utmp 	utbuf;		/* read info into here 		*/
	int		utmpfd;		/* read from this descriptor	*/

	if ((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1)
	{
		perror(UTMP_FILE);	/* UTMP_FILE is in utmp.h	*/
		exit(1);
	}
	
	while (read(utmpfd, &utbuf, sizeof(utbuf)) == sizeof(utbuf))
		show_info(&utbuf);
	close(utmpfd);
	return 0;
}

/*
 * show info()
 *	displays contents of the utmp struct in human readable form
 */
void show_info(struct utmp *utbufp)
{
	//printf("%d", utbufp->ut_type);
	if (utbufp->ut_type != USER_PROCESS)	/* users only !	*/
		return;
	
	printf("%-8.8s", utbufp->ut_name);	/* the logname	*/
	printf(" ");				
	printf("%-8.8s", utbufp->ut_line);	/* the tty	*/
	printf(" ");				
	showtime(utbufp->ut_time);		/* login time	*/
#ifdef	SHOWHOST
	//if (utbufp->ut_host[0] != '\0') /* to get rid of the local users host... */
	printf("(%s)", utbufp->ut_host);/* the host	*/
#endif
	printf("\n");
}

void showtime(long timeval)
/*
 *	display time in a format fit for human consumption
 *	uses ctime to build a string then picks parts out of it
 *	Note: %12.12s prints a string 12 chars wide and LIMITS it to 12chars. the first 12 is not needed but it limits ensuring readability.
 */
{
	char *cp;				/* to hold adress of time	*/
	cp = ctime(&timeval);			/* convert time to string	*/
	printf("%12.12s", cp+4);		/* pick 12 chars from pos 4	*/	
}
