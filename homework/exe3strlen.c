#include <stdio.h>

int strlen(char *s);

int main(int ac, char *av)
{
	char *s = "martinaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	
	printf("%d\n", strlen(s));

	return 0;
}

int strlen(char *s)
{
	int count=0;
	
	for(;*s!='\0';count++,s++);
		return count;
}
