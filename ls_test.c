#include<sys/types.h>
#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>

void printing(struct stat *);

int main(int ac, char *av[])
{
	DIR 		*dir_ptr;
	struct dirent 	*direntp;
	struct stat 	info;
	//struct stat	*buf;
	while (--ac)	
	{
		if((dir_ptr = opendir(*++av)) == NULL)
			fprintf(stderr,"ls_test: cannot open %s\n", *av);
		else
		{
			//stat(av[1], &info);
			while ((direntp = readdir(dir_ptr)) != NULL)
			{
				stat(direntp->d_name, &info);
				printf("%s\t", direntp->d_name);
				printing(&info);
			}			
			closedir(dir_ptr);
		}	
	}
}

void printing(struct stat *buf)
{
	if(S_ISDIR(buf->st_mode))
		printf("it's a dir.\n");
	else if (S_ISREG(buf->st_mode))
		printf("it's a reg file.\n");
	else
		printf("%o\n", buf->st_mode);
}


