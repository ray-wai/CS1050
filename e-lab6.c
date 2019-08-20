//Raymond Waidmann
//rcw5k2
//e-Lab6

#include <stdio.h>
#include <stdlib.h> //to seed time
#include <time.h> //to include time
#include <math.h>
#define MAX 20

int check_error (int);
void initialize_2Darray (int b[][MAX], int size);
void print_2Darray (int c[][MAX], int size);
int findZeros (int d[][MAX], int size);
int findEvenOdd (int e[][MAX], int size);
void printTranspose (int f[][MAX], int size);

void flattenArray (int g[][MAX], int size);

int main (void) //create a 2d array of size 20, initialize the array, call the functions needed on the array in main
{
	srand(time(NULL)); //seed random function with tuime to make it more random
	int arr[MAX][MAX] = {{0,0}}; //creating an array of size 20x20 so that we can use as much of it as we need
	int size; //size of the array 1-20

	printf("Enter the size of the 2D array: ");
	scanf("%d", &size);

	while (check_error(size) == 0) //error checking array size 1-20 using function int check_error
		{
			printf("Invalid input! Enter the size of the input again (1-20): ");
			scanf("%d", &size);
		}

	printf("\nThe First 2D array is: \n");
	initialize_2Darray (arr, size); //assigning the array to random numbers via function call
	print_2Darray (arr, size); //printing the generated array via function call

	int Z; //number of zeros as a variable in main
	Z = findZeros (arr, size); //calling function findZeros to count the number of 0's
	printf("\nThe number of zeros in the 2D array is: %d", Z);

	int E; //number of evens
	E = findEvenOdd (arr, size); //calling function findEvenOdd to calculate the number of even numbers
	int O; //number of odds
	O = ((pow(size, 2)) - E); //odds = total numbers in array (size^2) - number of evens
	printf("\nThe number of even numbers: %d", E); //printing evens
	printf("\nThe number of odd numbers: %d\n", O); //printing odds

	printf("\nThe transpose of the 2D array is:\n");
	printTranspose (arr, size); //calling function print transposed array (prints within the called function)
	puts("");

	flattenArray (arr, size); //calling flatten array to convert arr into a 1D array, also bonus is included in this function call

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

void initialize_2Darray (int b[][MAX], int size) //takes an integer number and initialize the 2D array with random numbers 0-9
{
	for (int i = 0; i <= size-1; ++i) //looping through the rows
		{
			for (int j = 0; j <= size-1; ++j) //looping through the columns
				{
					b[i][j] = (rand() %10);
				}
		}
}

void print_2Darray (int c[][MAX], int size) //prints the content of the 2d array. use proper formatting
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

int findEvenOdd (int e[][MAX], int size) //finds evens, then send that number back to main, calculate odds in main via total numbers - evens = odds
{
	int evens = 0; //counter for the number of evens

	for (int i = 0; i <= size-1; ++i) //looping through the rows
		{
			for (int j = 0; j <= size-1; ++j) //looping through the columns
				{
					if (e[i][j] % 2 == 0)
					{
						evens++;
					}
				}
		}
	return (evens);
}

void printTranspose (int f[][MAX], int size) 
/*
 * This is exactly the same code from function print_2Darray except for the columns and rows switched in the printf statement. By reversing the rows
 * and columns, it switches the precedence from left to right, top to bottom into top to bottom, left to right. It's almost the same as finding an
 * inverse function in math where y = f(x) --> x = f(y), then resolving for y in equation two. It works and makes sense to me so hopefully that
 * is sufficient. 
*/
{
	for (int i = 0; i <= size-1; ++i) //looping through the rows
		{
			for (int j = 0; j <= size-1; ++j) //looping through the columns
				{
					printf("%d", f[j][i]); //NOTE: [j][i] vs [i][j]
				}
			puts("");
		}
}


void flattenArray (int g[][MAX], int size) //converts the 2d array into a new 1d array and prints the new array
{
	int sizesq; //creating variable size squared to allocate the proper amount (without excess) storage in 1D array 2
	sizesq = pow(size, 2);
	int arr2[sizesq];
	int counter; //index of 1D array
	counter = 0;

	for (int i = 0; i <= size-1; ++i) //looping through the rows of 2d array
		{
			for (int j = 0; j <= size-1; ++j) //looping through the columns of 2d array
				{
					arr2[counter] = g[i][j]; //setting the 1D array to the contents of the 1D array
					counter++;	//adding 1 to the index of the 1D array for the next loop
				}
		}

	printf("The flattened array is: \n"); 
	for (int k = 0; k < sizesq; k++) 
		{
			printf("%d ", arr2[k]); //printing the 2D array
		}
	puts("");

//BONUS
	int q;
	for (int m = 0; m < sizesq; ++m) //running through the array as many times as necessary to sort 
		{
			for (int p = m+1; p < sizesq; ++p) //running through each index
				{
					if (arr2[m] > arr2[p])
						{
							q = arr2[m];
							arr2[m] = arr2[p]; //this is just a bubble sort function honestly not that hard. literally in the textbook. 
							arr2[p] = q;
						}
				}
		}

	printf("\n*****BONUS***** (lines 170-193)\nThe sorted array is:\n");
	for (int k = 0; k < sizesq; k++) 
		{
			printf("%d ", arr2[k]); //printing the 2D array again now in ascending order
		}
	puts("");
	puts("");

//BONUS

}

