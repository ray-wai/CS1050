//Raymond Waidmann
//rcw5k2
//Prelab 9 


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50

void get_size(int *); //gets the size of the array via call by reference
int check_size(int); //checks if a number between 1-50
void initialize_pointerArray(int *, int); //takes a pointer and its size and stores random numbers in the array 1-10
void printarray(int *, int); //prints the content of the array
int find_max(int *, int); //returns the largest value stored in the int pointer

int main (void) //read input size from user, perform error check, initialize int pointer and call functions
{
	srand(time(NULL)); //seeds random with time
	int size; //size of the array 1-50
	int array[MAX] = {0}; //array of size 10 initialized to 0
	int *Parray = array; //pointer to the first number in the array

	get_size(&size); //get the size of the array

	while (check_size(size) == 0) //calling errorcheck to make sure number 1-10
		{
			printf("Input must be 1-10. Please enter again: ");
			get_size(&size); //get the size of the array
		}

	initialize_pointerArray(Parray, size); //initialize the pointer array function call
	printarray(Parray, size); //print the pointer array function call

	int M; //value of the max
	M = find_max(Parray, size); //calling function find max to find the max value in the array
	printf("The largest value in the pointer is %d\n\n", M);


}

void get_size (int *size)
	{
		printf("\nEnter the size of the input: ");
		scanf("%d", size); //i think this is correct, normally we use an & but since size is already a pointer we dont need it i dont think. works with the compiler...
	}

int check_size(int x) //checks to ensure valid input 1-50
	{
		if (x < 1 || x > 50)
			{
				return (0);
			}
		return (1);
	}

void initialize_pointerArray (int *output, int size)
	{
		for (int i = 0; i < size; i++) //wehere size is the user input size of the array
			{
				*(output + i) = ((rand() % 10) + 1); //assigns each array position to a random number 1-10
			}
	}

void printarray (int *output, int size)
	{
		for (int i = 0; i < size; i++)
			{
				printf("%d ", *(output+i)); //printing the output of the array. 
			}
		puts("");
	}

int find_max(int *output, int size)
	{
		int max = *(output);
		for (int i = 1; i < size; i++) //starts at i = 1 since i = 0 is already initialized to max
			{
				if (*(output + i) > max) //comparing the next value in the array to the current max, setting it as new max if larger than current max
					{
						max = *(output + i);
						if (max == 10) //if max is 10, break so the for loop doesn't continue running since 10 is an absolute max
							{
								break;
							}
					}
					
			}
		return (max);
	}
