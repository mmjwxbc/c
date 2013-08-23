#include <stdio.h>

float convertion(float celsius);

int main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0; upper = 300; step = 20;

	celsius = lower;
	printf("---CONVERSION TABLE FROM CEL TO FAHR---\n");
	
	while(celsius <= upper)
	{
		printf("%3.0f %3.0f\n", celsius, convertion(celsius));
		celsius += step;
	}
	return 0;
}

float convertion(float cels)
{
	return ((9.0/5.0) * cels + 32);
}
