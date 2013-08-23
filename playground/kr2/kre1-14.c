#include <stdio.h>

#define CHAR_MAX 256

int stars(int a[]);

main()
{
	int chars[CHAR_MAX + 1];
	int i, c, j, a;
	a = 1;
	for (i = 0; i <= CHAR_MAX; ++i)
		chars[i] = 0;
	
	while ((c = getchar()) != EOF)
	{
		++chars[c];	
	}
	for (i = 0; i <= CHAR_MAX; ++i)
		if (chars[i] > 0){
			printf("%d:\t", chars[i]);	
			while(chars[i]--)
				printf("*");
			printf("\n");}
}


				
