#include <stdio.h>

main()
{
	int c, a;
	
	while ((c=getchar()) != EOF)
	{
		if (c == ' ') 
			if (a != ' ')
				putchar(c);
		if (c != ' ')
			putchar(c);
		a = c;
	}
}
		
