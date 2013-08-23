#include <stdio.h>
#include <termios.h>

main(int ac, char *av[])
{
	struct termios info;
	
	if (tcgetattr(0, &info) == -1)
	{
		perror("tcgetattr");
	}
	
	if (info.c_lflag & ECHO)
		printf(" echo is ON , since its bit is 1\n");
	else
		printf(" echo is OFF, since its bit is 0\n");
}
