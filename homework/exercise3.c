#include <stdio.h>
#include <string.h>
#include <limits.h>

int bufio(FILE * fpin, FILE * fpout)
{
	char *s;
	
	while((s=fgets(s,LINE_MAX,fpin))!=NULL)
		if((fputs(s,fpout))= EOF)
		{
			fprint(stderr,"\nfputs() error\n");
			return -1;
		}
	if(!(strlen(s)>0))
	{			
		fprintf(stderr,"\n fgets() error");
		return -2;
	}
	return 0;
}
