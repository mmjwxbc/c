#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int ac, char *av[])
{
	struct stat info;
	DIR *dirptr;
	struct dirent *direntp;
	
	if ((dirptr = opendir("..")) == NULL)
		fprintf(stderr,"error opening file");
	else
	{
		stat(".", &info);
	
		while ((direntp = readdir(dirptr)) != NULL)
			if (direntp->d_ino == info.st_ino)
				printf("%s\t",direntp->d_name); printf("%o\n", info.st_ino);
	
	}	
}
