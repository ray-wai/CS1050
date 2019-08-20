//Raymond Waidmann
//rcw5k2
//e-LAB8.c

#include <stdio.h>
#define MAX 10
#include <math.h>

int errorcheck (int); //checks if a number between 1-10
int factorial(int limit); //takes a pointer to the beginning of an array of integers (the output variable) and a limit. calculate 
						  //factorials from 1 to and including the limit, store each result in the output array. 
void printarray(float *, int); //prints the content of the array
void maclaurinseries(float *, int, int); //takes a float pointer array, size of array, and the degree of the series to be calculated
void reversearray(float *, int); //BONUS, prints the array in reverse

int main (void) //read input size from user, perform error check, initialize int pointer and call functions
{
	int number; //value of cos(number) to be approximated
	int degree; //(n), the number of degrees of the expansion that will be calculated
	float array[MAX] = {0}; //array of size 10 initialized to 0
	float *Parray = array; //pointer to the first number in the array

	printf("Enter a value to compute Maclaurin series expansion (cos(#)): "); //prompting user to enter a number to be computed
	scanf("%d", &number);
	
	while (errorcheck(number) == 0) //calling errorcheck to make sure number 1-10
		{
			printf("Input must be 1-10. Please enter again: ");
			scanf("%d", &number);
		}

	printf("Enter a degree for the Maclaurin series to run: ");
	scanf("%d", &degree);

	while (errorcheck(degree) == 0) //calling errorcheck to make sure number 1-10
		{
			printf("Input must be 1-10. Please enter again: ");
			scanf("%d", &degree);
		}

	maclaurinseries(Parray, number, degree); //passing the pointer, value to calculate, and the degree to be calculated to maclauriin function
	printarray(Parray, degree); //printing the array via pointer
	reversearray(Parray, degree); //calling reverse array function to print the array in reverse

}

int errorcheck(int x) //checks to ensure valid input 1-10
	{
		if (x < 1 || x > 10)
			{
				return (0);
			}
		return (1);
	}

int factorial (int limit) 
	{
		int T; //the variable we will return to main
		for (int i = 0; i < limit; i++) 
			{
				int j = i; //set j = i so we can modify "i" (really j) without actually modifying i
				int total = 1; //set a running total
				while (j > 0) 
					{
						total = (total * (j+1)); //factorial function. j+1 since i starts at 0. 
						--j; //decrement j by 1 so in the next while loop it multiplies by the next smallest integer
					}
				if (i == limit-1)
					{
						T = total; //in the last run, set T = to total so we can return it to main
					}
			} 
		return (T); //return T to main
	}

void printarray (float *output, int limit)
	{
		for (int i = 0; i <= limit; i++)
			{
				printf("%.4f ", *(output+i)); //printing the output of the array to 4 decimal places
			}
		puts("");
	}

void maclaurinseries(float *output, int num, int deg)
	{
		for (int i = 0; i <= (deg); i++)
			{
				int j = i; //set j = i so we can modify "i" (really j) without actually messing with i
				float tempml; //temporary maclaurin; the value of each individual
				float tempmltot = 1.0000; //running total for the array
				j *= 2; //setting j to two times i

				while (j > 0)
					{
						tempml = (pow(num, j))/(factorial(j)); //x^n/n

						if ((j/2) % 2 != 0) //2, 6, 10, 14 (making the negative ones negative)
							{
								tempml *= (-1);
							}	
						tempmltot += tempml; //running total
						j -= 2; //subtracting 2 from j for the next loop
					}
				*(output + i) = tempmltot; //assigning the array value to the final value of the running total
			}
	}

void reversearray (float *a, int n)
	{
		printf("\n$$$$$ BONUS $$$$$\n");

		for (int i = n; i >= 0; i--) //this is the only difference from function printarray; have i start at the max value, 
									 //and decrement until end of array is reached
			{
				printf("%.4f ", *(a+i)); //printing the output of the array to 4 decimal places
			}
		puts("");
	}
