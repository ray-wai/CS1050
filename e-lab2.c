//Raymond Waidmann
//rcw5k2
//Lab 2

#include <stdio.h>
#include <math.h>

int main (void)
{
	int number1; //first integer
	int number2; //second integer
	int number3; //third integer (square root number)
	int sum; //number1+number2
	int difference; //number1-number2
	int product; //n1*n2
	double quotient; //number1/number2 ***** might need to un-"int" this
	double squareroot; //square root of number3 ***** might need to un-"int" this
	

//getting number1
	printf("Enter the first number: ");
	scanf("%d", &number1);

	while (0 > number1) //while number1 is negative (error check until number1 is a positive integer)
	{
		printf("Enter a non-negative number: ");
		scanf ("%d", &number1);
	}

//getting number2
	printf("\nEnter the second number: ");
	scanf("%d", &number2);

	while (0 > number2) //while number2 is negative (error check until number2 is a positive integer)
	{
		printf("Enter a non-negative number: ");
		scanf("%d", &number2);
	}

//add number1 and number2 and display result
	sum = number1 + number2;
	printf("\nADDITION \n The sum of %d and %d is %d\n\n", number1, number2, sum);

//subtract number1 and number2 and display result
	difference = number1 - number2;
	printf("SUBTRACTION \n The difference between %d and %d is %d\n\n", number1, number2, difference);

//multiply number1 and number2 and dislay result
	product = number1 * number2;
	printf("MULTIPLICATION \n The product of %d and %d is %d\n\n", number1, number2, product);

//divide number1 and number2 and display result
	while (0 >= number2) //error checking if number2 is equal to 0, reassigning a new number to number2 if necessary, 
						 //if user enters a negative number, error check will also ask again for a new input
	{
		printf("Cannot divide by zero!\n"); 
		printf("Enter a new, positive, non-zero number: ");
		scanf("%d", &number2);
	}

	quotient =  ((float)number1 / number2);
	printf("DIVISION \n %d divided by %d is %.2f\n\n", number1, number2, quotient);

//finding and displaying the larger of number1 and number2
	if (number1 > number2)
	{
		printf("COMPARISON \n %d is the bigger number between %d and %d\n\n", number1, number1, number2);
	}

	if (number2 > number1)
	{
		printf("COMPARISON \n %d is the bigger number between %d and %d\n\n", number2, number1, number2);
	}

//finding the square root of a new integer

	printf("Enter a number for the square root operation: ");
	scanf("%d", &number3);

	while (0 > number3) //while number 3 is negative (error check until number3 is a positive integer)

	{
		printf("Cannot take the square root of a negative number!\n"); 
		printf("Try again: ");
		scanf("%d", &number3);
	}
	
	squareroot = pow(number3, 0.5);
	printf("\nSQUARE ROOT \n The square root of %d is %.2f\n\n", number3, squareroot);

	return(0);
}

