#include <stdio.h>

void main()
{
	struct student
	{
		char first[10];
		char last[15];
		float gpa;
	};

	printf("%zu\n", sizeof(struct student));
}
