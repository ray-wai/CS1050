#include<stdio.h>

int main(void)
{
	int number1; //first integer
	int number2; //second integer
	int sum; //number1+number2
	int product; //n1*n2

	printf("Enter the first number: ");
	scanf("%d", &number1);

	if (0 > number1) //if n1 is negative
	{
		printf("Enter a non-negative number: ");
		scanf ("%d", &number1);
	}

	printf("Enter the second number: ");
	scanf("%d", &number2);

	if (0 > number2) //if n2 is negative
	{
		printf("Enter a non-negative number: ");
		scanf("%d", &number2);
	}

	sum = number1 + number2;
	product = number1 * number2;

	printf("ADDITION \n The sum of %d and %d is %d\n", number1, number2, sum);
	printf("MULTIPLICATION \n The product of %d and %d is %d\n", number1, number2, product);

}

