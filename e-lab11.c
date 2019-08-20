//Raymond Waidmann
//rcw5k2
//e-lab11.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 40

void get_size(int*);
int check_size(int);
void get_group(int*);
int check_group(int);
int load_structdata(char*, int); //changed from void to int in order to return a sentinel value to main amd terminate the program. the return
								 //value does not change any other part of the program
void classify(char*, int);
void print_data(int);
void frequency (char*, int, int);

int load_bonusdata(char*, int); //literally the same functions as loadstruct_data and print_data but designed for the bonus
void print_bonusdata(int);		//since i did the lab via struct anyways, the bonus was literally the same thing

typedef struct //creating a struct for MOHousing array
{
	char county[12];
	int zip;
	char city[12];
	int group;
}_data;

typedef struct //struct for bonus
{
	int zip;
	float income;
}_bonus;

_data MOHousing[MAX]; //a global variable
_bonus Bonus[MAX];    //alspo a global variable

int main(int argc, char * argv[]) //comments on the following 6 lines are from the prelab
			   //read the input size from the user by calling get_size, and error check via check_size
			   //call load_structdata, and uses a struct array (Info) to store the information
			   //use print_data to print the data in the array to the screen
			   //
			   //argc = the number of arguements on the command line (starting at 1)
			   //argv[] = the text arguement on the command line (starting at [0])
{		
	if (argc != 3)
		{
			printf("Insufficient Arguements!"); //if the command line arguments are not the correct number (./a.out and argv[1]), end the program
			return (-1);
		}

	int size; //size of the array 4-40
	get_size(&size); //get the size of the array
	while (check_size(size) == 0) //calling errorcheck to make sure number 4-40
		{
			printf("Input must be 4-40. Please enter again: ");
			get_size(&size); //get the size of the array
		}

	int sentinel = load_structdata (argv[1], size); //calling function load_structdata to put the file data into the global array
	if (sentinel == 0) //if the file can't be opened, terminate the program
		{
			return (-1);
		}

	print_data(size); //calling function print_data to print out the data stored in global array StudentInfo
	classify(argv[1], size); //classifying the houses by zip code and assigning group numbers to MOHousing.group. print results to screen

	int group; //same process and error checking as getting the size
	get_group(&group);
	while (check_group(group) == 0)
		{
			printf("Input must be 1-3. Please enter again ");
			get_group(&group);
		}

	frequency(argv[1], size, group); //printing the cities within the user selected group and displaying the frequency of the first three

	int sentinel2 = load_bonusdata(argv[2], size); //if the bonus file can't be opened, terminate the program; loading the bonus data
	if (sentinel2 == 0)
		{
			return (-1);
		}
	print_bonusdata(size); //printing the bonus data
	return (0);

}

void get_size(int * size) //reads in the size of the pointer by reference (same as lab 10)
	{
		printf("\nEnter the size of the input: ");
		scanf("%d", size);
	}

int check_size(int x) //error check 4-40
	{
		if (x < 4 || x > 40)
			{
				return (0);
			}
		return (1);
	}

void get_group(int * group) //same as getsize function but for group variable
	{
		printf("\nEnter the group number: ");
		scanf("%d", group);
	}

int check_group(int x) //same as check_size but 1-3
	{
		if (x < 1 || x > 3)
			{
				return (0);
			}
		return (1);
	}

int load_structdata(char * filename, int size) //takes the filename containing the student record and the input size as arguement
											   //return type changed to int only so that we can return a sentinel and terminate
											   //the program if the file can't be opened
	{
		FILE * fptr = fopen(filename, "r"); //opening a file for reading and assigning it to the pointer filename

		if ((fptr = fopen(filename, "r")) == NULL) //error check to see if the file can be opened
			{
				printf("\n*****INPUT FILE COULD NOT BE OPENED*****\n\n");
				return (0); //return 0 if file can't be opened; program will terminate back in main
			}

		else
			{
				for (int i = 0; i < size; i++)
					{
						fscanf(fptr, "%12s%d%12s", MOHousing[i].county, &MOHousing[i].zip, MOHousing[i].city); //note strings do not ned address operator & when using fscanf
							//scanning in the data from the file to the global array
					}

				fclose (fptr); //closing the file pointer
			}
		return (1);
	}
	
void print_data(int size) //print the content of the struct array(info). takes input size as arguement
	{
		printf("\nHousing Record\nS/NO %-12s%-8s%-12s\n", "County", "Zip", "City"); //- means left justified in the field

		for (int i = 0; i < size; i++)
			{
				printf("%-5d%-12s%-8d%-12s", i+1, MOHousing[i].county, MOHousing[i].zip, MOHousing[i].city); 
					//printing the output to the screen using the dot operator
				puts("");
			}
	}

void classify(char * filename, int size) //classifying the data in the input file into groups
	{
		int g1total = 0;
		int g2total = 0; //variables to keep track of how many houses are in each group
		int g3total = 0;

		for (int i = 0; i < size; i++)
			{
				if (63000 <= MOHousing[i].zip && 63999 >= MOHousing[i].zip)
					{
						MOHousing[i].group = 1;
						g1total++;
					}

				if (64000 <= MOHousing[i].zip && 64999 >= MOHousing[i].zip) //assigning groups in the struct based on the value of .zip
					{
						MOHousing[i].group = 2;
						g2total++;			//for each zip code within each range, add one to g#total to keep track of total houses in each group
					}

				if (65000 <= MOHousing[i].zip && 66000 >= MOHousing[i].zip)
					{
						MOHousing[i].group = 3;
						g3total++;
					}
			}

		printf("\nHousing Record\nS/NO %-12s%-8s%-12s%6s\n", "County", "Zip", "City", "Group"); //- means left justified in the field

		for (int i = 0; i < size; i++)
			{
				printf("%-5d%-12s%-8d%-12s%6d", i+1, MOHousing[i].county, MOHousing[i].zip, MOHousing[i].city, MOHousing[i].group); 
					//printing the output to the screen using the dot operator
				puts("");
			}
		
		puts("");
		printf("Number of Info in Group 1: %d\n", g1total);
		printf("Number of Info in Group 2: %d\n", g2total); //printing the totals to the screen
		printf("Number of Info in Group 3: %d\n", g3total);
	}

void frequency (char * filename, int size, int group)
	{
		printf("\nCities in Group %d:\n", group);
		int m = 0; //m is the number of houses in the user selected group in a given size
		for (int i = 0; i < size; i++)
			{		
				if(MOHousing[i].group == group)
					{
						m++;
						printf("%-4d%-12s\n", m, MOHousing[i].city); //printing the cities that are in the same group
					}
			}
		puts("");

		int r = 0; //r is used in the for loops below in order to continue looping through the cities where the previous loop left off

		char * city1 = malloc (sizeof(char) * 12);
		char * city2 = malloc (sizeof(char) * 12); //allocating space to store the first three cities
		char * city3 = malloc (sizeof(char) * 12);

		int z = 0; //z allows us to determine how many UNIQUE cities there are 1-3 (within the first three) ex (Ballwin, Manchester, Ballwin) -> z = 2 (2 unique cities)

		if (m >= 1)
		{
		for (int i = 0; i < size; i++)
			{
				r++;
				if(MOHousing[i].group == group)
					{
						strcpy(city1, MOHousing[i].city);
						z++;
						break;
					}
				
			}
		}

		if (m >= 2)
		{
		for (int n = r; n < size; n++)
			{
				r++;
				if (MOHousing[n].group == group)
					{
						strcpy(city2, MOHousing[n].city);  //if there are m unique cities, assign the next city within the same group to city#, check if city# matches the ones above it
						if (strcmp(city1, city2) == 0)	   //use of m >= # allows us to only assign 1 or 2 cities if there are only 1 or 2 unique cities in a group of a given size
							{
								continue;
							}

						else
							{
								z++;
								break;
							}
					}
			}
		}

		if (m >= 3)
		{
		for (int q = r; q < size; q++)
			{
				r++;
				if (MOHousing[q].group == group)
					{
						strcpy(city3, MOHousing[q].city);
						if (strcmp(city1, city3) == 0 || strcmp(city2, city3) == 0)
							{
								continue;
							}

						else
							{
								z++;
								break;
							}


					}
			}
		}

		int * freq1 = malloc(sizeof(int));
		int * freq2 = malloc(sizeof(int)); //allocating space to total the frequency of the first three cities
		int * freq3 = malloc(sizeof(int));

		*freq1 = 0;
		*freq2 = 0; //initializing the frequencies
		*freq3 = 0;

		if (z >= 1)
			{
				for (int a = 0; a < size; a++)
					{
						if(MOHousing[a].group == group && strcmp(city1, MOHousing[a].city) == 0)
							{
								(*freq1)++; 
							}
					}
			}

		if (z >= 2)
			{
				for (int b = 0; b < size; b++)
					{
						if(MOHousing[b].group == group && strcmp(city2, MOHousing[b].city) == 0) //totaling the frequencies for identical cities by checking if it is in the group, and the strings are the same
							{
								(*freq2)++;
							}
					}
			}

		if (z >= 3)
			{
				for (int c = 0; c < size; c++)
					{
						if(MOHousing[c].group == group && strcmp(city3, MOHousing[c].city) == 0)
							{
								(*freq3)++;
							}
					}
			}

		printf("Frequency Table:\n");
		printf("%-5s%-12s%9s\n", "S/NO", "City", "Frequency");

		int number = 1;
		if (z >= 1)
			{
				printf("%-5d%-12s%9d\n", number, city1, *freq1);
				number++;
			}

		if (z >= 2)
			{
				printf("%-5d%-12s%9d\n", number, city2, *freq2); //printing the results to the screen
				number++;
			}

		if (z >= 3)
			{
				printf("%-5d%-12s%9d\n", number, city3, *freq3);
			}

		free(city1);
		free(city2);
		free(city3);
						//freeing malloced space
		free(freq1);
		free(freq2);
		free(freq3);
	}

int load_bonusdata(char * filename, int size) //basically copy pasted from load_structdata since i used a struct to do the lab anyways
	{
		FILE * fptr = fopen(filename, "r"); //opening a file for reading and assigning it to the pointer filename

		if ((fptr = fopen(filename, "r")) == NULL) //error check to see if the file can be opened
			{
				printf("*****BONUS INPUT FILE COULD NOT BE OPENED*****\n\n");
				return (0); //return 0 if file can't be opened; program will terminate back in main
			}

		else
			{
				for (int i = 0; i < size; i++)
					{
						fscanf(fptr, "%d%f", &Bonus[i].zip, &Bonus[i].income); 
							//scanning in the data from the file to the global array
					}

				fclose (fptr); //closing the file pointer
			}
		return (1);
	}

void print_bonusdata(int size) //basically copy pasted from print_data since i used a struct to do the lab anyways
	{
		printf("\n\n*****BONUS*****\nS/NO %-8s%-12s\n", "Zip", "Income"); //- means left justified in the field

		for (int i = 0; i < size; i++)
			{
				printf("%-5d%-8d%-12.2f", i+1, Bonus[i].zip, Bonus[i].income); 
					//printing the output to the screen using the dot operator
				puts("");
			}
		puts("");
	}
