#include <stdio.h>
#include <termios.h>

#define QUESTION	"Do you want another transaction"
int main()
{
	int response;
	
	response = get_response(QUESTION);
	return response;
}

int get_response(char *question)
{
	int c;	
	printf("%s (y/n)?", question);
	while (1)
		switch (getchar())
		{
			case 'y': case 'Y':
				return 0;
				break;
			case 'n': case 'N': case EOF:
				return 1;
				break;
			default:
				printf("improper input; enter y or n");
		}
}
