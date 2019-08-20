//Raymond Waidmann
//rcw5k2
//e-hw3.c

//DO NOT HARDCODE FILENAMES
//DO NOT HARDCODE THE COUNT OF RECORDS IN THE INPUT FILE

#include <stdio.h>
#include <stdlib.h>

int get_record_count(char*);
int load_data(char*, int*, float*, int);
void print_data(int*, float*, int);
int highest_amount(float*, int);
int lowest_amount(float*, int);
float average_amount(float*, int);
int write_data(char*, int*, float*, int, int, int, float);

int main (int argc, char * argv[])
//	 //use command line args to get file names from user
//	 //use argc to check if there enough inputs by user (if no, display error message and terminate program)
//	 //get number of lines in the input file (so you know how many ints and floats you will need to allocate)
//	 //allocate space using malloc to an int * and float * (for account numbers, and amount numbers) (int array and float array) (malloc only how much space you need based on # of lines)
//	 //call load_data and print_data to load and print the account info
//	 //call print_data to display the updated info
//	 //call highest, lowest, and average functions and print results as shpwn in sample output
//	 //call write_data and write the info to the output text file. 
//	 //free the malloced space
{
	if (argc != 3)
		{
			printf("Incorrect number of Arguments!"); //if the command line arguments are not the correct number (./a.out and argv[1]), end the program
			return (-1);
		}

	int count = get_record_count (argv[1]); //calling function get_records_count to count the number of lines in the input.txt file
		//printf("%d", count); (this prints 8 meaning count is the correct number of lines in the input file)
	if (count == -1) //if the input file could not be opened, terminate the program
		{
			return (-1);
		}

	int * account = malloc (sizeof(int) * count);
	float * balance = malloc (sizeof(float) * count); //allocating space to accoutn and balance arrays based of of how many lines were counted in the input file
	load_data (argv[1], account, balance, count); //calling function load_data to scan in the values of the file into arrays account and balance

	print_data(account, balance, count); //printing the data to the screen using function print data
	int high = highest_amount(balance, count); //calling the high, low, and average functions and printing the rresults to the screen
		//printf("high = %d", high); (testing to make sure the highest valued index is correct, it is 2 which is correct)
	printf("The highest amount of $%.2f is in the account number %d\n", balance[high], account[high]);
	int low = lowest_amount(balance, count);
	printf("The lowest amount of $%.2f is in the account number %d\n", balance[low], account[low]); //printing the high, low, and average values and their account nnumber
	float average = average_amount(balance, count);
	printf("The average amount of all the accounts is $%.2f\n\n", average);

	int sentinel = write_data(argv[2], account, balance, count, high, low, average);
	if (sentinel == 0) //if the output file could not be opened, terminate the program
		{
			return (-1);
		}

	free(account); //freeing the malloced space from account and balance arrays
	free(balance);
}

int get_record_count (char * filename)
	 //takes the name of an input file
	 //opens and read lines from the file
	 //count the lines as it goes
	 //returns the number of lines in the input file
	 //
	 //assume no line in the input file has no more than 255 characters
	 //use fgets() to read in one line at a time so you can count
	 //be careful about the return value of fgets(fgets returns NULL if it fails to read a line)
	 //be careful about checking feof() - didnt need to use per Madi YEET
	{
		FILE * fptr; //open the file and create a file pointer

		if ((fptr = fopen(filename, "r")) == NULL) //checking for successful opening of the input file
			{
				printf("\n*****INPUT FILE COULD NOT BE OPENED*****\n\n");
				return (-1); //returning -1 as "count
			}

		int count = 0;
		char buffer[255]; //number of chars per line (assume no line has more than 255 characters)

		while(fgets(buffer, sizeof(buffer), fptr) != NULL) //reading in a line from the file; loop doesnt execute of line is failed to be read (no contents in the line)
			{
				count++; //counting the number of lines
			}

		fclose(fptr); //closing the file
		return (count); //returning the number of lines 

	}

int load_data (char * filename, int * account, float * balance, int size)
	 //opens the input file (if unable, return 0) - error checkl for file opening is done in function get_record_count
	 //load account info from the text file into the int and float arrays and return 1 at end (first line of text file)
	 //
	 //use a file pointer to open the file (ex. FILE * file = fopen(filename, x) [where x the file access mode])
	{	
		FILE * fptr = fopen (filename, "r"); //opening the input file for reading

		for (int i = 0; i < size; i++)
			{
				fscanf(fptr, "%d%f", &account[i], &balance[i]); //scanning in the info from the file to account and balance arrays
			}
		fclose(fptr); //closing the file
		return(1); //indicated successful run of the function
	}

void print_data (int * account, float * balance, int size)
	 //takes in an int array, float array, and int size
	 //displays the data stored in these arrays as in sample output
	 //make sure things line up correctly as shown
	{
		printf("\n%d records in the file.\nAccount No.  Amount", size);
		for (int i = 0; i < size; i++)
			{
				printf("\n%-12d%7.2f", account[i], balance[i]); //(correctly prints the contents of account[] and balance[] as assigned from input.txt file
			}
		puts("");
		puts("");
	}

int highest_amount (float * balance, int size)
	 //takes float * and number of accounts
	 //finds highest amount and returns index cooresponding to highest amount
	{

		int q = 0;
		for (int m = 0; m < size; ++m) //running through the array as many times as necessary to check for the highest
			{	
				if (balance[m] > balance[q])
					{
						q = m; //assigning the highest index to q
					}
			}
		return q;
	}

int lowest_amount (float * balance, int size)
	 //same as above but lowest
	{
		int q = 0;
		for (int m = 0; m < size; ++m)
			{	
				if (balance[m] < balance[q]) //only difference is in this line
					{
						q = m;
					}
			}
		return q;
	}

float average_amount (float * balance, int size)
	 //same as above (returns average amount)
	{
		float average = 0;
		for (int i = 0; i < size; i++)
			{
				average += balance[i]; //average is really the total of all of the accounts
			}
		float da_real_average = (average/size); //total/number of accounts
		return (da_real_average); //returning the average back to main
	}

int write_data (char * filenameout, int * account, float * balance, int count, int highindex, int lowindex, float average)
	 //outfut file name, acount number info, amount info, number of accounts, index of highest amount, index of lowest amount, average amount
	 //use fprintf to write the data into the text file. return a 0 if the file was unable to open and write, return 1 if success
	{
		FILE * fptrout; //opening the output file for writing

		if ((fptrout = fopen(filenameout, "w")) == NULL) //checking for successful opening of the output file
			{
				printf("\n*****OUTPUT FILE COULD NOT BE OPENED*****\n\n");
				return (0); //returning 0 as sentinel
			}

		fprintf(fptrout, "Account No.  Amount");
		for (int i = 0; i < count; i++)
			{
				fprintf(fptrout,"\n%-12d%7.2f", account[i], balance[i]); //printing all the numbers to the output file
			}
		fprintf(fptrout,"\n\nThe highest amount of $%.2f is in the account number %d\n", balance[highindex], account[highindex]); 
		fprintf(fptrout,"The lowest amount of $%.2f is in the account number %d\n", balance[lowindex], account[lowindex]); //printing the high low and average to output file
		fprintf(fptrout,"The average amount of all the accounts is $%.2f", average);

		fclose(fptrout); //closing the file pointer
		return (1);
	}
