//Raymond Waidmann
//rcw5k2
//e-Lab 5

#include <stdio.h>
#include <stdlib.h> //to seed time
#include <time.h> //to seed time
#include <math.h> //pow function

int check_error(int); //error check for the size of the array
void initialize_array(int b[], int size); //initializer the array with random numbers
void print_array(int c[], int size); //prints the array
float average(int d[], int size); //calculates the average of the array 
float std_dev(int e[], int size); //calculates the std dev of the array

//BONUS!!
int min(int f[], int size); //finds the index of the smallest number in the array
//BONUS!!

int main(void)
{
	srand(time(NULL)); //seed random function with time to make it more random;
	int arr[50] = {0}; //creating an array of size 50
	int size; //the size of the array 1-50
	float avg; //average variable for main
	float sd; //standard deviation
	int index; //index of minimum value in array


	printf("\nEnter the size of the input: "); //prompting user input for size of array and scanning inout value
	scanf("%d", &size);

	while (check_error(size) == 0) //error checking array size 1-50 using function int check_error
		{
			printf("Invalid input! Enter the size of the input again (1-50): ");
			scanf("%d", &size);
		}

	printf("\nInput array: \n"); 
	initialize_array(arr, size); //call function initialize array to set the value of each part of the array
	print_array(arr, size); //call function print array to print the results of each part of the array

	avg = average(arr, size); //call function average to find the average of the array
	printf("\nThe average of the array is: %.2f", avg); //print the average

	sd = std_dev(arr, size); //call function std_array to find the std dev of the array
	printf("\nThe standard deviation of the array is: %.2f\n\n", sd); //printing the std dev

	//BONUS!!
	index = min(arr, size);
	printf("*****BONUS***** (lines 16-18, 49-52, 130-149)\nThe index of the smallest element is: %d\n\n", index);
	//BONUS!!

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


void initialize_array(int b[], int size) //takes an integer array and its size as input, initialize the integer 1D aray with random numbers between 0-9.
										 // (USE rand(). REMEMBER WHERE TO USE srand() HINT: use for loop)
{
	for (int x = 0; x < size; x++) //where x is just a counter
		{
			b[x] = ((rand() % 9)+1); //was 0-9 in prelab, changed to values 1-9 in actual lab
		}
}


void print_array (int c[], int size) //takes integer array and size, prints the content of array (HINT USE for LOOP)
{
	for (int x = 0; x < size; x++) //where x is just a counter
		{
			printf("%d ", c[x]);
		}
}


float average(int d[], int size) //calculates the average of the array
{
	float total; //total value of all of the array components summed
	float avg2; //value to be returned to main as average
	for (int x = 0; x < size; x++)
		{
			total += d[x]; //add all the elements of the array together
		
			if (size == x+1) //on the last loop
				{
					avg2 = total/(x+1); //since x is 0 base but average is 1 base, we must add 1 to x to divide by the number of components in the array
				}
		}
	return (avg2); //return the average back to main
}


float std_dev(int e[], int size) //calculates the std dev of the array
{
	float avg3; //average in this function
	avg3 = average(e, size); //call function average to find the average of the array

	float xmms; //calculating the sum of (x-m)^2 for all the elements of the array ("X Minus Mu Squared" XMMS)
	for (int x = 0; x < size; x++)
		{
			xmms += pow((e[x] - avg3), 2); //taking the value of the array at sub x, subtracting average, squaring the result, and adding to xmms
		}
	
	float oon; //"One Over N"
	oon = pow(size, -1); //1/N

	float radicand; //everything under the square root
	radicand = (oon * xmms); // 1/N * (x-m)^2

	float expression; //value of std dev, the entire expression, (adding the sqare root)
	expression = pow(radicand, 0.5);

	return (expression); //returning the std dev back to main
}


//BONUS!!
int min(int f[], int size)
	{
		int sub; //index of the smallest number
		int min; //temporary minimum value

		min = f[0]; //assigning the first value of the array to the minimum

		for(int x = 1; x < size; x++) //start at one since we set x = 0 to the minimum in line 136
			{
				if (f[x] < min) //if an element is less than the current minimum, this step also ensures only the first index of a repeated minimum 
								//is displayed
					{
						min = f[x]; //minimum is the new value
						sub = x; //index at the new minumum
					}
				}
		return (sub);
	}
//BONUS!!
