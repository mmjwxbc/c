#include <stdio.h>
#include <string.h> //strerror
#include <stdlib.h> //malloc
#include <errno.h> //errno

extern errno;

int main(void)
{	
	/* pointer to characters (bytes), requestiong dynamic allocation of 500000000000000000000 storage elements */
	char *ptr=(char *) malloc(5000000000000000000000*sizeof(int));
	if(ptr==NULL)
		fprintf(stdout,strerror(errno));
	else
	{
		/*the rest of the code hereafter can assume that 1000 bytes were successfully allocated */
		/* ... */
		free(ptr);
	}
	exit(EXIT_SUCCESS); /* exiting program */
}
	
