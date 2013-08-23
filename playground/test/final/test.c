#include <stdio.h>
#include <fcntl.h>

int main(int ac, char *av[])
{
	FILE *fp;
	fp = open(av[1], O_WRONLY);
	putc('a', fp);
	return 0;
}
