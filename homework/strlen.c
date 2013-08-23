#include <stdio.h>
//#include <string.h>

int main(int ag, char *av)
{
	char *s;
	scanf("%s", &s);
	printf("%d\n",strlen(&s));
	return 0;
}

size_t strlen(const char* s)
{
    const char* op = s;
    while(*s++);
    return (size_t)(s - op - 1);
}

