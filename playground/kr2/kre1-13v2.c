#include <stdio.h>

int asteriks(int);

main()
{
	int words[12];
	int nc, i, c;
	
	nc = 0;
	for ( i = 0; i < 12; ++i)
		words[i] = 0;
	
	while ((c = getchar()) != EOF)
	{	
		++nc;
		if (c == ' ' || c == '\n' || c == '\t')
			if (nc > 0 && nc < 11)
			{			
				++words[nc-1];
				nc = 0;
			}
			else
			{
				++words[11];
				nc = 0;
			}
				
	}
	printf("     1 2 3 4 5 6 7 8 9\n");
	for(i = 1; i<11; i++)
	{
		printf(" %2d: ", i);
		asterisks(words[i]);
			
	}
	printf(">10: ");
	asterisks(words[11]);
}

int asterisks(int x)
{
	while(x--)		
	{
		printf("* ");
	}
	printf("\n");
}
