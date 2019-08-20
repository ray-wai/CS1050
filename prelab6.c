//Raymond Waidmann
//rcw5k2
//e-Prelab6

#include <stdio.h>
#include <stdlib.h> //to seed time
#include <time.h> //to include time
#define MAX 20

int check_error (int);
void initialize_2Darray (int b[MAX][MAX], int size);
void print_2Darray (int c[MAX][MAX], int size);
int findZeros (int d[][MAX], int size);

int main (void) //create a 2d array of size 20, initialize the array, call the functions needed on the array in main
{
	srand(time(NULL)); //seed random function with tuime to make it more random
	int arr[MAX][MAX] = {{0,0}}; //creating an array of size 20x20 so that we can use as much of it as we need
	int size; //size of the array 1-20

	printf("Enter the size of the 2D array: ");
	scanf("%d", &size);

	while (check_error(size) == 0) //error checking array size 1-50 using function int check_error
		{
			printf("Invalid input! Enter the size of the input again (1-20): ");
			scanf("%d", &size);
		}

	printf("\nThe First 2D array is: \n");
	initialize_2Darray (arr, size);
	print_2Darray (arr, size);

	int Z; //number of zeros
	Z = findZeros (arr, size);
	printf("\n\nThe number of zeros in the 2D array is: %d\n\n", Z);

	return (0);
}





int check_error (int x) //takes an integer and checks if between 1-20, it valid input return 1, else return 0
{
	if (0 >= x || 20 < x)
		{
			return (0);
		}
	return (1);
}

void initialize_2Darray (int b[MAX][MAX], int size) //takes an integer number and initialize the 2D array with random numbers 0-9
{
	for (int i = 0; i <= size-1; ++i) //looping through the rows
		{
			for (int j = 0; j <= size-1; ++j) //looping through the columns
				{
					b[i][j] = (rand() %10);
				}
		}
}

void print_2Darray (int c[MAX][MAX], int size) //prints the content of the 2d array. use proper formatting
{
	for (int i = 0; i <= size-1; ++i) //looping through the rows
		{
			for (int j = 0; j <= size-1; ++j) //looping through the columns
				{
					printf("%d", c[i][j]); //printing from left to right, top to bottom
				}
			puts("");
		}
}



int findZeros (int d[][MAX], int size) //count the number of zeros in the array, return the count to main
{
	int zero = 0; //counter for the number of zeros

	for (int i = 0; i <= size-1; ++i) //looping through the rows
		{
			for (int j = 0; j <= size-1; ++j) //looping through the columns
				{
					if (d[i][j] == 0)
					{
						zero++;
					}
				}
		}

	return (zero);
}
