#include <stdio.h>

int main (int ac, char *av[])
{
	char *names;
	
	names = (char*)malloc(2*sizeof(char));
	int i=0;
	for (i=0;i<2;i++)
	{
		names[i] = "martin";
	}
	for (i=0;i<2;i++)
	{
		printf("%d\n",names[i]);
	}
	return 0;
}
