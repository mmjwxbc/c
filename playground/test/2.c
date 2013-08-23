#include <stdio.h>

#define LINELEN 512

int main(int ac, char *av[])
{
	FILE *fp;
	char line[LINELEN];
	while(--ac)
	{	
		if((fp=fopen(*++av,"r"))!=NULL)
		{	
			while(fgets(line,LINELEN,fp))
				fputs(line,stdout);
			
			fclose(fp);
		}
		else
			exit(1);
	}	
}
