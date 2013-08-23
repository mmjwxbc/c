#include <stdio.h>

#define MAXLINE 1000

int getline1(char line[], int maxline);

main()
{
	int len, i, a;
	char line[MAXLINE];
	
	while ((len = getline1(line, MAXLINE)) > 0)
	{
		a = len;
		while (--len){
			if (line[len+1] == '\n') 
				if (line[len] == ' ' || line[len] == '\t')
					line[len] = '\b';
						
			}
		
		
		i = 0;
		while (i<a)
			{
				if (line[i] == '\n')
					if (line[i-1] != '\n')
						putchar(line[i]);
				if (line[i] != '\n')
					putchar(line[i]);
				i++;
			}
	}
	return 0;
}

int getline1(char line[], int maxline)
{
	int c, i;
	
	for (i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n')
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	
	return i;
}
