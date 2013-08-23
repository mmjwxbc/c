#include <stdio.h>

int main (int ac, char *av[])
{
	float ave, num, sum, count = 0;
		
    	
	printf("\nEnter a number:");
	scanf("%f",&num);
	printf("\n");
	while (num != -999999)
	{
		sum += num;
		count++;
		printf("\nEnter another number:");
		scanf("%f",&num);
		printf("\n");
	}



	count >= 1 ? ave = sum/count : printf("\n no data \n");
	count >= 1 ? printf("average = %10.3f", ave) : printf("\n error \n");
	printf("The average is: %f\n",ave);

	return 0;
}
