#include <stdio.h>

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
	for (i = 1; i < 11; ++i) 		
	{
		printf("%d: %d\n", i, words[i]);
	}
	printf(">10: %d\n", words[11]);
}
