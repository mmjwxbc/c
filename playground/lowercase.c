#include <stdio.h>
#include <ctype.h>

main()
{
	int c;
	while(7) printf("te quiero 7!!\n");

	while ((c = getchar()) != EOF)
		putchar(tolower(c));
	return 0;
}
