#include <stdio.h>

#define LINELEN 512

int main(int ac, char *av[])
{
	FILE *fp;
	char line[LINELEN];
	if ((fp = fopen(av[1], "r")) != NULL)
	{
		while (fgets(line, LINELEN, fp))
			if (fputs(line, stdout) == EOF)
				break;
	}
	return 0;
}
