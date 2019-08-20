//Raymond Waidmann
//rcw5k2
//e-prelab11.c

#include <stdio.h>
#define MAX 30

void get_size(int*);
int check_size(int);
int load_structdata(char*, int); //changed from void to int in order to return a sentinel value to main
void print_data(int);

typedef struct 
{
	char name[10];
	int id;
	int grade;
}_data;

_data StudentInfo[MAX]; //a global variable

int main(int argc, char * argv[]) //read the input size from the user by calling get_size, and error check via check_size
			   //call load_structdata, and uses a struct array (Info) to store the information
			   //use print_data to print the data in the array to the screen
			   //
			   //argc = the number of arguements on the command line (starting at 1)
			   //argv[] = the text arguement on the command line (starting at [0])
{		
	if (argc != 2)
		{
			printf("Insufficient Arguements!"); //if the command line arguments are not the correct number (./a.out and argv[1]), end the program
			return (-1);
		}

	int size; //size of the array 1-22
	get_size(&size); //get the size of the array
	while (check_size(size) == 0) //calling errorcheck to make sure number 1-22
		{
			printf("Input must be 1-22. Please enter again: ");
			get_size(&size); //get the size of the array
		}

	int sentinel = load_structdata (argv[1], size); //calling function load_structdata to put the file data into the global array
	if (sentinel == 0) //if the file can't be opened, terminate the program
		{
			return (-1);
		}

	print_data(size); //calling function print_data to print out the data stored in global array StudentInfo
}

void get_size(int * size) //reads in the size of the pointer by reference (same as lab 10)
	{
		printf("\nEnter the size of the input: ");
		scanf("%d", size);
	}

int check_size(int x) //error check 1-22
	{
		if (x < 1 || x > 22)
			{
				return (0);
			}
		return (1);
	}

int load_structdata(char *filename, int size) //takes the filename containing the student record and the input size as arguement
	{
		FILE * fptr = fopen(filename, "r"); //opening a file for reading and assigning it to the pointer filename

		if ((fptr = fopen(filename, "r")) == NULL) //error check to see if the file can be opened
			{
				printf("\n*****FILE COULD NOT BE OPENED*****\n\n");
				return (0); //return 0 if file can't be opened; program will terminate back in main
			}

		else
			{
				for (int i = 0; i < size; i++)
					{
						fscanf(fptr, "%10s%d%d", StudentInfo[i].name, &StudentInfo[i].id, &StudentInfo[i].grade); //scanning in the data from the file to the global array
					}

				fclose (fptr); //closing the file pointer
			}
		return (1);
	}
	
void print_data(int size) //print the content of the struct array(info). takes input size as arguement
	{
		printf("\nStudent Record\nS/NO %-10s%-5s%-5s\n", "Name", "ID", "Grade"); //- means left justified in the field

		for (int i = 0; i < size; i++)
			{
				printf("%-5d%-10s%4d%6d", i+1, StudentInfo[i].name, StudentInfo[i].id, StudentInfo[i].grade); //printing the output to the screen using the dot operator
				puts("");
			}
		puts("");
	}

