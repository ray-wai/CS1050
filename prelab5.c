//Raymond Waidmann
//rcw5k2
//e-Prelab 5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int check_error(int); //error check for the size of the array
void initialize_array(int b[], int size); //initializer the array with random numbers
void print_array(int b[], int size);

int main(void)
{
	srand(time(NULL)); //seed random function with time to make it more random;
	int arr[50] = {0}; //creating an array of size 50
	int size; //the size of the array 1-50


	printf("\nEnter the size of the input: "); //prompting user input for size of array and scanning inout value
	scanf("%d", &size);

	while (check_error(size) == 0) //error checking array size 1-50 using function int check_error
		{
			printf("\nInvalid input! Enter the size of the input again (1-50): ");
			scanf("%d", &size);
		}

	printf("\nInput array: \n"); 
	initialize_array(arr, size); //call function initialize array to set the value of each part of the array
	print_array(arr, size); //call function print array to print the results of each part of the array
	puts("");
	puts(""); //two newlines for aesthetic

	return (0);
}






int check_error(int x) //checks if selection is between 1 and 50, if valid return 1, else return 0
{
	if (0 >= x || 50 < x)
		{
			return (0);
		}
	return (1);
}


void initialize_array(int b[], int size) //takes an integer array and its size as input, initialize the integer 1D aray with random numbers between 0-9. (USE rand(). REMEMBER WHERE TO USE srand() HINT: use for loop)
{
	for (int x = 0; x < size; x++) //where x is just a counter
		{
			b[x] = (rand() % 10);
		}
}


void print_array (int b[], int size) //takes integer array and size, prints the content of array (HINT USE for LOOP)
{
	for (int x = 0; x < size; x++) //where x is just a counter
		{
			printf("%d ", b[x]);
		}
}
