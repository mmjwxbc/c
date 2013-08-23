#include <stdio.h>

main()
{
	int c,a;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
			if (a == c)
				;
			else
				printf("\n");
		else
			putchar(c);
		
		a = c;
	}
}
