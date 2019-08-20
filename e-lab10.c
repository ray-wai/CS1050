//Raymond Waidmann
//rcw5k2
//e-Lab10.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <ctype.h> //bonus is to delete this and create a toupper function
#include <time.h>

int getString (char*); 
int checkString (char*, int);
void cipherString (char*, int, int);
void anticipherString (char*, int, int);
int stringSum (char*, int);

int main (void) //declares a new string (char pointer), call getString and print string with size out and free malloced memory from the string
{
	char *ptr = malloc (sizeof(char) * 21); //declare a pointer array of size 20 with a null terminator
	int returnedsize; //returned size from function getString
	returnedsize = getString (ptr); //returnsize is the size of the string actually even if less than the entered size
	printf("\nYou entered: %s which is size %d\n\n", ptr, returnedsize); //printing the uppercase string and the entered size

	srand(time(NULL));
	int RN = ((rand() % 25) + 1); //a random number 1-25
	cipherString (ptr, returnedsize, RN); //ciphering the string
	int cipherkey = 0; //setting cipherkey = 0 so the while loop below runs at least once (could use do whle but this was easier)

	while (cipherkey != RN) //while the user incorrectly guessed the cipherkey
		{
			printf("The ciphered string is %s, what is the Cipher Key?: ", ptr); //prompting user to enter cipherkey
			scanf ("%d", &cipherkey);

			while (0 >= cipherkey || 26 <= cipherkey) //checking for valid cipherkey input
				{
					printf("The cipher key is between 1-25, try again: ");
					scanf("%d", &cipherkey);
				}

			if (cipherkey == RN) //since cipherkey can be changed in the inner while loop, recheck the cipherkey == RN condition
				{
					break; //if recheck is the correct key, break from this while loop
				}

			anticipherString (ptr, returnedsize, cipherkey); //intermediate cipher string 
			printf("The cipher string shifted back %d is %s, incorrect!\n\n", cipherkey, ptr); //diplaying the incorrect string
			cipherString (ptr, returnedsize, cipherkey); //returning the intermediate string back to the ciphered string

		}
	
	anticipherString (ptr, returnedsize, RN); //reciphering the string back to original input
	printf ("The ciphered string shifted back %d is %s, that's correct!\n" , RN, ptr);

	int sum = stringSum (ptr, returnedsize); //calling function stringSum to sum the ascii values
	printf("The sum of the ascii in %s is %d\n$$$$$BONUS$$$$$ (lines 8,87-95) I have done the above without using the ctype.h library\n\n", ptr, sum);

	free(ptr); //deallocating memory
	return(0);
}

int getString (char *PTR) //takes in an uninitialized string, prompt user for size of string (error chack size 1-20), 
						  //then prompts and scans in the actual string from the user and converts it to uppercase
					      //returns the size of the string and the string should be valid when it terminates 
						  //(HINT: if user enters in a string length less than the size but not empty, adjust the size. Use getSafeString from hw2)
	{
		int size;
		printf("\nEnter the size of the string (1-20): ");
		scanf("%d", &size);

		while (1 > size || 20 < size)
			{
				printf("Invalid input, please enter again (1-20): "); //prompting user for size of the string and error checking 
				scanf("%d", &size);
			}

		printf("Please enter a string: "); //prompting user to enter a string
		scanf("%s", PTR);
		
		while (checkString(PTR, size) == 0) //checks to make sure the string is of proper length and characters
			{
				printf("Please enter a valid string: ");
				scanf ("%s", PTR);
			}

		for (int i = 0; i < strlen(PTR); i++) //converting the string to uppercase
			{
				//BONUS
				if (*(PTR + i) >= 97 && *(PTR + i) <= 122) //if lowercase
					{
						*(PTR + i) -= 32; //subtract 32 (lowercase letters have ascii values 32 higher than uppercase, ex. a = 97, A = 65
										  //thus, if lowercase, subtract 32 to convert to uppercase
					}

				//*(PTR + i) = toupper(*(PTR + i)); 	
				//BONUS	
			}
	
		return (strlen(PTR)); //returning the size of the string to main

	}

int checkString (char *pointer, int sz) //takes in the string and the size, and checks to see if the string is valid. Valid == A - Z, not including null
										//(HINT: try using askii valus instead of checking for specific characters()
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

void cipherString (char *pointer, int size, int randnum) //takes pointer, size, and a random number 1-25 then shifts the string to the right
														 // ex. B + 3 = E (B, C, D, E)
	{
		for (int i = 0; i < size; i++)
			{
				*(pointer + i) += randnum; //take the current ascii value and add whatever the random num is to it

				if (*(pointer + i) >= 91) //past Z
					{
						*(pointer + i) -= 26; //if past 'Z', reverse back to A. Since the random num ranges from 1-25, you can never "lap" Z meaning
											  //this if statement will never need to be performed more than once for a particular character that 
											  //has been ciphered
					}
			}

	}

void anticipherString (char *pointer, int size, int usernum) //basically the opposite of the above function
	{
		for (int i = 0; i < size; i++)
			{
				*(pointer + i) -= usernum; //take the current ascii value and add whatever the random num is to it (-= instead of +=)

				if (*(pointer + i) <= 64) //(<=64 instead of >= 91)
					{
						*(pointer + i) += 26; //if past 'A', reverse back to Z. Since the random num ranges from 1-25, you can never "lap" A meaning
											  //this if statement will never need to be performed more than once for a particular character that 
											  //has been ciphered (+= instead of -=)
					}
			}

	}

int stringSum (char *pointer, int size)
	{
		int SUM = 0;
		for (int i = 0; i < size; i++)
			{
				SUM += *(pointer + i); //looping through the string and summing the ascii values 
			}

		return (SUM); //returning the sum back to main
	}


