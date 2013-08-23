#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

void do_ls(char[]);

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
	struct dirent * direntp;
		
	if((dirptr=opendir(dirname)) == NULL)
	{
		fprintf(stderr,"Error opening");
		exit(1);
	}
	else
		while((direntp=readdir(dirptr)) != NULL)
			printf("%s\n",direntp->d_name);
	//closedir(dirptr);
}
