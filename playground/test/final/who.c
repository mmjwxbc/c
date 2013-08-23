#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define SHOWHOST

void show_info(struct utmp *);

int main(int ac, char *av[])
{
	struct utmp current_record;
	int utmpfd;
	int reclen=sizeof(struct utmp);

	if ((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1)
	{
		perror(UTMP_FILE);
	}/*if*/
	
	while (read(utmpfd,&current_record,reclen) == reclen)
		show_info(&current_record);
	
	close(utmpfd);
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

	if ((tm = localtime(&tt)) == NULL) // No need, assign and then check if (!tt)
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
