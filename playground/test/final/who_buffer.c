#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "./utmplib.h"

#define SHOWHOST

void show_info(struct utmp *);

int main(int ac, char *av[])
{
	struct utmp 	*utmpfd,
			*utmp_next();

	if (utmp_open(UTMP_FILE) == -1)
	{
		perror(UTMP_FILE);
		exit(1);
	}/*if*/
	
	while ((utmpfd = utmp_next()) != ((struct utmp *) NULL)) //No need use double parenthesis one for assignment and one for checking for NULL or 0.
		show_info(utmpfd);
	
	utmp_close();
	return 0;
}

void show_info(struct utmp *utbuff)
{
	struct tm *tm;
	time_t tt;	
	char stime[200];

	if (utbuff->ut_type != USER_PROCESS)
		return;

	printf("%-8.8s", utbuff->ut_name);
	printf(" %-8.8s", utbuff->ut_line);
	tt = utbuff->ut_time;	

	if ((tm = localtime(&tt)) == NULL) // fix. better check for null after the assignment.
		perror("localtime");

	if (strftime(stime, sizeof(stime), "%Y-%m-%d %R", tm) == 0)
		fprintf(stderr, "strftime returned 0");
	else	
		printf("     %s", stime);
	
	#ifdef SHOWHOST
		printf(" (%s)",utbuff->ut_host);
	#endif
		printf("\n");
}
