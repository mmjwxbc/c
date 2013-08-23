#include <stdio.h>

main()
{
	int c,a;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		  if (a == ' ' || a == '\t')
				;
			else
				putchar('\n');
		else
			putchar(c);
		
		a = c;
	}
}
