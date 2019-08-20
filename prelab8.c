//Raymond Waidmann
//rcw5k2
//e-prelab8.c

#include <stdio.h>
#define MAX 10

int errorcheck (int); //checks if a number between 1-10
void factorial(int *output, int limit); //takes a pointer to the beginning of an array of integers (the output variable) and a limit. calculate factorials from 1 to and including the limit, store each result in the output array. 
void printarray(int *, int); //prints the content of the array

int main (void) //read input size from user, perform error check, initialize int pointer and call functions
{
	int number; //size of the array 1-10
	int array[MAX] = {0}; //array of size 10 initialized to 0
	int *Parray = array; //pointer to the first number in the array

	printf("Enter a number to calculate the factorial: "); //prompting user to enter a number for the factorial
	scanf("%d", &number);
	
	while (errorcheck(number) == 0) //calling errorcheck to make sure number 1-10
		{
			printf("Input must be 1-10. Please enter again: ");
			scanf("%d", &number);
		}

	factorial(Parray, number); //calling the funtions to initialize the array via pointer
	printarray(Parray, number);
}

int errorcheck(int x) //checks to ensure valid input 1-10
	{
		if (x < 1 || x > 10)
			{
				return (0);
			}
		return (1);
	}

void factorial (int *output, int limit) 
	{
		for (int i = 0; i < limit; i++) //i is an incrementor for the array subscripts
			{
				int j = i; //set j = i so we can modify "i" (really j) without actually modifying i
				int total = 1; //set a running total
				while (j > 0) 
					{
						total = (total * (j+1)); //factorial function. j+1 since i starts at 0. 
						--j; //decrement j by 1 so in the next while loop it multiplies by the next smallest integer
					}
				*(output+i) = total; //assigning the array to the value from the while loop
			}
	}

void printarray (int *output, int limit)
	{
		for (int i = 0; i < limit; i++)
			{
				printf("%d ", *(output+i)); //printing the output of the array. 
			}
		puts("");
	}
