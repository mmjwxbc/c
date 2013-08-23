#include <stdio.h>
#include <stdlib.h>

#define LINELEN 512

int main(int ac, char *av[])
{
	char line[LINELEN];

	FILE *fd;
	
	if((fd = fopen(av[1], "r")) == NULL)
	{		
		fprintf(stderr, "Must provide a file.\n");
		exit(1);
	}

	while(fgets(line, LINELEN, fd))
		fputs(line, stdout);

	return 0;

}


