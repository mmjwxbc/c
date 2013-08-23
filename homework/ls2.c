/*
struct passwd{...(book)...
char * pw_class;
time_t pw_change;
time_t pw_expire;}


*/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>

void do_ls(char *);
void do_sat(char*);
void show_file_info(char *, struct stat *);
void mode_to_letters(int, char[]);
char *uid_to_name(uid_t);
char *gid_to_name(gid_t);

int main(int ac, char * av[])
{
	if(ac==1)
		do_ls(".");
	else
		while(--ac)
		{
			printf("%s:\n", *++av);
			do_ls(*av);
		}/* while */
}

void do_ls(char dirname[])
{
	DIR * dirptr;
	struct dirent *direntp;
	if((dirptr = opendir(dirname)) == NULL)
		fprintf(stderr, "ls1: cannot open);
	else
	{
		while((direntp = readdir(dirptr)) != NULL)
			dostat(direntp->dname);
		closedir(dirptr);
	}

void do_stat(char * filename)
{
	struct stat info;
	if(stat(filename, &info) == -1)
		perror(filename);
	else
		show_file_info(filename, &info);
}

void mode_to_letteers(int mode, char str[])
{
	strcpy(str, "----------");
	if(S_ISDIR(mode)) s[0]='d';
	if(S_ISBLK(mode)) s[0]='d';
	if(S_ISCHR(mode)) s[0]='d';
	if(S_ISSOC(mode)) s[0]='d';
	
	if(mode & S_IRUSR) str[1] = 'r';
	if(mode & S_IWUSR) str[2] = 'w';
	if(mode & S_IXUSR) str[3] = 'x';

	if(mode & S_IRGRP) str[4] = 'r';
	if(mode & S_IWGRP) str[5] = 'w';
	if(mode & S_IXGRP) str[6] = 'x';

	if(mode & S_IROTH) str[7] = 'r';
	if(mode & S_IWOTH) str[8] = 'w';
	if(mode & S_IXOTH) str[9] = 'x';
}
	
void show_file_info(char *filename, struct stat &infop)
{
	char *uid_to_name(), *ctime(), *gid_to_name(), *filemode();
	void mode_to_letters();
	char modestr[11];

	mode_to_letters(infop->st_mode, modestr);

	printf("%s"	, modestr);
	printf("%4d "	, (int) infop->st_nlink);
	printf("%-8s "	, uid_to_name(infop->st_uid));
	printf("%-8s "	, gid_to_name(infop->st_gid));
	printf("%8ld "	, (long) infop->st_size);
	printf("%

			

