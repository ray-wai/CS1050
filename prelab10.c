//Raymond Waidmann
//rcw5k2
//e-prelab10.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getString (char*); 
int checkString (char*, int);

int main (void) //declares a new string (char pointer), call getString and print string with size out and free malloced memory from the string
{
	char *ptr = malloc (sizeof(char) * 21); //declare a pointer array of size 20 with a null terminator
	int returnedsize;
	returnedsize = getString (ptr); //returnsize is the size of the string actually even if less than the entered size
	printf("\nYou entered: %s which is size %d\n\n", ptr, returnedsize); //printing the uppercase string and the entered size
	free(ptr); //deallocating memory
	return(0);
}

int getString (char *PTR) //takes in an uninitialized string, prompt user for size of string (error chack size 1-20), then prompts and scans in the actual string from the user and converts it to uppercase
					      //returns the size of the string and the string should be valid when it terminates (HINT: if user enters in a string length less than the size but not empty, adjust the size. Use getSafeString from hw2)
	{
		int size;
		printf("\nEnter the size of the string (1-20): ");
		scanf("%d", &size);

		while (1 > size || 20 < size)
			{
				printf("Invalid input, please enter again (1-20): "); //prompting user for size of the string and error checking 
				scanf("%d", &size);
			}

		printf("Please enter a string: "); //promptiong user to enter a string
		scanf("%s", PTR);
		
		while (checkString(PTR, size) == 0) //checks to make sure the string is of proper length and characters
			{
				printf("Please enter a valid string: ");
				scanf ("%s", PTR);
			}

		for (int i = 0; i < strlen(PTR); i++) //converting the string to uppercase
			{
				*(PTR + i) = toupper(*(PTR + i)); 		
			}
	
		return (strlen(PTR)); //returning the size of the string to main

	}

int checkString (char *pointer, int sz) //takes in the string and the size, and checks to see if the string is valid. Valid == A - Z, not including null. (HINT: try using askii valus instead of checking for specific characters()
	{
		while (strlen(pointer) > sz) //while loop to ensure the entered string is less than or equal to the entered size
			{
				printf("The string entered is longer than the allowed size \nPlease enter a valid input: ");
				scanf("%s", pointer);
			}

		for (int i = 0; i < strlen(pointer); i++) //making sure the entered string is only a-z and A-Z
			{
				if (*(pointer + i) >= 'a' && *(pointer + i) <= 'z')
					{
						continue;
					}

				if (*(pointer + i) >= 'A' && *(pointer + i) <= 'Z')
					{
						continue;
					}

				return (0); //if one character is not valid, immediately return 0
			}
		return (1); //if the whole string it valid, return 1
	}
