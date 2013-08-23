#include <stdio.h>

main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0; upper = 300; step = 20;

	celsius = lower;
	printf("---CONVERSION TABLE FROM CEL TO FAHR---\n");
	
	while(celsius <= upper)
	{
		fahr = (9.0/5.0) * celsius + 32;
		printf("%3.0f %3.0f\n", celsius, fahr);
		celsius += step;
	}
}
