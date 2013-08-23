#include <stdio.h>
#include <stdlib.h>

float sum_function(float num1, float num2);
double diff_function(float num1, float num2);
double prod_function(float num1, float num2);
double quot_function(float num1, float num2);
int show_info(float number1, float number2);

int main(int ac, char *av)
{
	float number1, number2;
	
	printf("Input 2 numbers: ");
	scanf("%f %f", &number1, &number2);

	show_info(number1, number2);
	
	return 0;
}

int show_info(float number1, float number2)
{
	printf("The SUM of %.2f + %.2f \t= %.2f\n", number1, number2,		sum_function (number1, number2));
	printf("The DIFFERENCE of %.2f - %.2f\t= %.2f\n", number1, number2,	diff_function(number1, number2));
	printf("The PRODUCT of %.2f * %.2f\t= %.2f\n", number1, number2,	prod_function(number1, number2));
	printf("The QUOTIENT of %.2f and %.2f\t= %.2f\n", number1, number2,	quot_function(number1, number2));
	return 0;
}

float sum_function(float num1, float num2)
{
	return num1 + num2;
}

double diff_function(float num1, float num2)
{
	return num1 - num2;
}

double prod_function(float num1, float num2)
{
	return num1 * num2;
}

double quot_function(float num1, float num2)
{
	div_t n = div(num1, num2);
	return n.quot;
} 
