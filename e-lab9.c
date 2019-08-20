//Raymond Waidmann
//rcw5k2
//e-Lab 9 


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50

void get_size(int *); //gets the size of the array via call by reference
int check_size(int); //checks if a number between 1-50
void initialize_pointerArray(int *, int); //takes a pointer and its size and stores random numbers in the array 1-50
void printarray(int *, int); //prints the content of the array
int find_max(int *, int); //returns the largest value stored in the int pointer
int find_min(int *, int); //returns the smallest value stored in the pointer
void bubble_sort (int *, int); //sorts the pointer into ascending order
float find_median(int *, int); //finds the median of the pointer

//BONUS
void bubble_sortdescend(int *, int); //same as bubble_sort but now descending order
	//void modifyarray(int *, int); //deleted every other element in the array
void printarray2(int *, int); //prints every other number of the decending array
//BONUS

int main (void) //read input size from user, perform error check, initialize int pointer and call functions
{
	srand(time(NULL)); //seeds random with time
	int size; //size of the array 1-50
	int array[MAX] = {0}; //array of size 10 initialized to 0
	int *Parray = array; //pointer to the first number in the array

	get_size(&size); //get the size of the array

	while (check_size(size) == 0) //calling errorcheck to make sure number 1-50
		{
			printf("Input must be 1-50. Please enter again: ");
			get_size(&size); //get the size of the array
		}

	initialize_pointerArray(Parray, size); //initialize the pointer array function call
	printarray(Parray, size); //print the pointer array function call

	int M; //value of the max
	M = find_max(Parray, size); //calling function find max to find the max value in the array
	printf("The largest value in the pointer is %d\n", M);

	int m; //value of the min
	m = find_min(Parray, size); //calling function find min to find the min value in the array
	printf("The smallest value in the pointer is %d\n\n", m);

	bubble_sort(Parray, size); //calling bubble function to sort the new pointer 
	printf("The sorted pointer is: \n");
	printarray(Parray, size);

	float F; //value of median returned from find_median
	F = find_median(Parray, size);
	printf("The median of the pointer = %.2f\n\n", F);

	//BONUS
	bubble_sortdescend(Parray, size); //sort the array in descending order
		//modifyarray(Parray, size); //delete every other element in the pointer (see commented code below)
	printf("$$$$$BONUS$$$$$\nThe pointer reversed and with every other number is: ");
	printarray2(Parray, size);
	//BONUS

}

void get_size (int *size)
	{
		printf("\nEnter the size of the input: ");
		scanf("%d", size); //since size is a pointer, we dont need &
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
		for (int i = 0; i < size; i++) //where size is the user input size of the array
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
		puts("");
	}

int find_max(int *output, int size)
	{
		int max = *(output); //assign first value of the array to the max
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


int find_min(int *output, int size)
	{
		int min = *(output); //assign first value of the array to the min
		for (int i = 1; i < size; i++) 
			{
				if (*(output + i) < min) //comparing the next value in the array to the current min, setting it as new min if less than current min
					{
						min = *(output + i);
						if (min == 1) //if min is 1, break so the for loop doesn't continue running since 1 is an absolute min
							{
								break;
							}
					}	
			}
		return (min);
	}

void bubble_sort (int *output, int size)
	{
		//bubble sort function from lab 6 changed to pointer notation
		int q;
		for (int m = 0; m < size; ++m) //running through the pointer as many times as necessary to sort 
			{
				for (int p = m+1; p < size; ++p) //running through each index
					{
						if (*(output + m) > *(output + p))
							{
								q = *(output + m);
								*(output + m) = *(output + p); //this is just a bubble sort function honestly not that hard. literally in the textbook. 
								*(output + p) = q;
							}
					}
			}
	}

float find_median (int *output, int size) //finds the median
	{
		float median;
		if (size % 2 == 1) //if there are an odd number of elements in the array, meaning there is a definite median
			{
				int a = ((size - 1) / 2); //example: if we have size 5, the median will be located at index 2 since we have indexes 0,1,2,3,4. 
										  //(size-1)/2 correctly gives us the median index for any odd numbered size
				median = *(output + a);   //assigning the median to the value at the index we just calclated
			}
			
		if (size % 2 == 0) //if there an even number of elements in the array, meaning the median is the average of two middle numbers
			{
				int b = ((size - 2) / 2);
				int c = (size / 2);       //example: if we have size 6, the median will be the average of the values at indexes 2 and 3 since we 
										  //have 0,1,2,3,4,5,6. b yields index 2, and c yields index three. We average these in the next line
										  //of code. This correctly finds the index for any odd size pointer
				
				median = ((float)((*(output + b)) + (*(output + c))) / 2);
			}
		return (median); //returning the median back to main
	}

//BONUS
void bubble_sortdescend (int *output, int size) //straight copy pasted with the exception of ">" changed to "<" in if statement 8 lines down
	{
		//bubble sort function from lab 6 changed to pointer notation
		int q;
		for (int m = 0; m < size; ++m) //running through the pointer as many times as necessary to sort 
			{
				for (int p = m+1; p < size; ++p) //running through each index
					{
						if (*(output + m) < *(output + p))
							{
								q = *(output + m);
								*(output + m) = *(output + p); //this is just a bubble sort function honestly not that hard. literally in the textbook. 
								*(output + p) = q;
							}
					}
			}
	}

void printarray2 (int *output, int size) //prints every other value of the array
	{
		for (int i = 0; i < size; i+=2)
			{
				printf("%d ", *(output+i)); //printing the output of the array. 
			}
		puts("");
		puts("");
	}
/*
//I tried this to actually create a new array, but was then told I could simply print the array backwards and only every other
void modiifyarray (int *output, int size)
	{
	for (int i = 0; i <= (size/2); i++)
		{
			*(output + i) = *(output + (2*i));
			if (i == (size/2))
				{
					for (int j = (size/2); j <size; j++)
						{
							*(output + j) = NULL;
						}
				}
		}
	}
*/

//BONUS
