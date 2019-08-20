//Raymond Waidmann
//rcw5k2
//Homework 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //to seed time

//Global constants
#define ROW 12	// Number of Rows of seats
#define COL 6	// Number of Columns of seats
#define MAX 25	// Maximum space to reserve for merged strings (includes NULL terminator)

////A global 2-D array which holds the cost. Not a good practice to use global variables AT ALL, but I just want to test you on scope of variables.
////You will not be using Global variables much going forward.

int costMatrix[ROW][COL]= //This is the cost of each seat in all the 3 flights. There are 72 seats in each flight.
	{
		{500,200,500,500,200,500},
		{500,200,500,500,200,500},
		{500,200,500,500,200,500},
		{500,200,500,500,200,500},
		{500,200,500,500,200,500},
		{500,200,500,500,200,500},
		{500,200,500,500,200,500},
		{500,200,500,500,200,500},
		{500,200,500,500,200,500},
		{500,200,500,500,200,500},
		{500,200,500,500,200,500},
		{500,200,500,500,200,500}
	};

//Displays the Menu options
void displayMenu();	

//error check the menu selection to ensure valid input
int selectioncheck(int);
 
//This does the log-in authentication, called  to compares the password with adminPassword 
int loginMatch(int passcode,int adminPasscode);

//This does the initialization for each flight, called as soon as your program starts. Allocates 1-20 (specified by count)seats in the flight. 
//Fill those seats randomly in all 3 flights Before hand. print 'O' for unreserved seats and 'X' for reserved seats
void initialSeats(char flight[][COL],int count);

//Prints the current flight Map every time it is called. Send the flight as the parameter.
void printFlightMap(char flight[][COL]);

//Prints the flight options during reserve a seat 
void flightMenu();

//This calculates the Total Revenue, sum of the cost of all reserved seats from each flight. Called in admin mode only.
int getTotalRevenue(char flight1[][COL], char flight2[][COL], char flight3[][COL]);

//Reserves seat in a flight, have to ask for which row (0-5) and which column(0-3) from the user. Perform error check inside this for row and column entered. 
//Mark that seat as 'X', if the seat is already taken then you need to loop back and ask again. If reservation is possible, print a success message,assign the seat and print the flight map here
void seatReservation(char flight[][COL]);

//Just before calling this function in main() : flight numbers are "MIA1050","BNA1050",LSA1050". Store this in num1[],num2,num3[] respectively 
//Ask for the first name when a flight option is chosen. Store this in name[]. This function takes those two strings, name and flight number, as parameters. 
//Merges them and stores them in 3rd string as shown in the output and prints the message of confirmation. BONUS ONLY 
void printMessage(char name[],char num[]);

// This function provided below
void getSafeString(char *string, int maxsize);

//main function... good luck!
int main (void)
{
	srand(time(NULL)); //randomly seeding time
	int seats; //random number 1-20 of how many seats are already taken on each flight
	seats = (rand() % 20) + 1; //int counts in initial seats function
			//	printf("%d", seats); //used this to makle sure error checking randomization of seats works correctly (it does)

	char flight_1[ROW][COL];
	char flight_2[ROW][COL]; //three arrays that hold the seating charts of the flights. 
	char flight_3[ROW][COL];
	char name[MAX]; //array that holds the name of the person buying the ticket

	initialSeats(flight_1, seats);
	initialSeats(flight_2, seats); //calling function initializeSeats to initialize the seating charts on each flight
	initialSeats(flight_3, seats);

int sentinel = 1; //creating a sentinel value to loop through the program until the program is terminated
while (sentinel == 1) //after everything has been initialized, create a loop that continues until sentinel != 0 when exit is selected
{
	int selection; //1,2, or 3 in the menu
	printf("\n********** WELCOME TO MIZZOU AIRLINE BOOKING SYSTEM **********\n");  //header
	displayMenu(); //call displaymenu function and display the menu options
	scanf("%d", &selection); //storing the selection ina variable so we know which situation we have to execute
	while (selectioncheck(selection) == 0) //error checking the selection 
		{
			printf("Invalid menu selection!!! Select a valid input (1,2, or 3): ");
			scanf("%d", &selection);
		}

	
	
	//ADMIN LOGIN
	if (1 == selection)
		{
			int adminPassword = 105018; //the passcode that needs to be matched by password
			int password; //user entered password
			printf("\nEnter the login password to log in as an admin: ");
			scanf("%d", &password); //prompting the user to enter the password
			
			while (loginMatch(password, adminPassword) == 0) //calling function loginMatch to see if the two passwords match
				{
					printf("\nInvalid passcode combination!\nEnter the correct password: ");
					scanf("%d", &password); //prompting the user to enter the password
				}

			printf("\nPrinting the Flight Map of Flight 1 Columbia to Miami (MIA): \n"); 	//printing the seating chart maps from each flight by calling function 
			printFlightMap (flight_1);													 	//printFlightMap for each flight
			printf("Printing the Flight Map of Flight 2 Columbia to Nashville (BNA): \n");
			printFlightMap (flight_2);
			printf("Printing the Flight Map of Flight 3 Columbia to Las Vagas (LAS): \n");
			printFlightMap (flight_3);

			int revenue = getTotalRevenue(flight_1, flight_2, flight_3);
			printf("The total earnings from all the flights: $%d", revenue);
			printf("\n");

		}

	//RESERVE A SEAT
	if (2 == selection)
		{
			flightMenu(); //calling function flight menu to display the flight options
			int flightnumber; //creating a variable to scan for the users choice
			scanf("%d", &flightnumber);
			while (selectioncheck(flightnumber) == 0) //since function selectioncheck checks for inputs 1,2, or 3 (originally used in menu selection), 
				{									  //and the flight options are also 1,2, or 3, we can use it to ensure valid flight has been chosen as well. 
					printf("Not a valid flight, please select a valid flight: ");
					scanf("%d", &flightnumber);
				}

			printf("\nEnter your first name: ");
			getSafeString (name, MAX);               

			if (flightnumber == 1) //MIAMI
				{
					printf("\nPrinting the Flight Map of Flight 1 Columbia to Miami (MIA): \n"); 
					seatReservation (flight_1);
					char flight_number[] = "MIA1050";  
					printMessage(name, flight_number);
				}

			if (flightnumber == 2) //NASHVILLE
				{
					printf("\nPrinting the Flight Map of Flight 2 Columbia to Nashville (BNA): \n");
					seatReservation (flight_2);															//calling function seatReservation for the selected flight to reserve a seat. 
					char flight_number[] = "BNA1050";      												//assigning the appropriate string to flight_number
					printMessage(name, flight_number);													//printing the message
				}

			if (flightnumber == 3) //LAS VAGAS
				{
					printf("\nPrinting the Flight Map of Flight 3 Columbia to Las Vegas (LAS): \n");
					seatReservation (flight_3);
					char flight_number[] = "LAS1050";
					printMessage(name, flight_number);
				}

		}

	//EXIT
	if (3 == selection)
		{
			printf("\nTerminating the program\nThank you for using Mizzou Airline Booking System\n\n");
			sentinel = 0;
			return (0); 
		}
	
} //bracket for while loop with sentinel value

} //bracket for main




void displayMenu() //display the menu options
{
	printf("\n1. Admin Log-in\n2. Reserve a seat\n3. Exit\nChoose an option: "); //prints the menu options
}

int selectioncheck(int x) //checking for valid input for selection of admin, reserve a seat, or exit
{
	if (1 == x || 2 == x || 3 == x)
		{
			return (1); //return 1 if valid selection
		}
	return (0); //return 0 if invalid selection
}

int loginMatch(int passcode,int adminPasscode)
{
	if (passcode == adminPasscode) //comparing the user entered passcode and the correct passcode; if they are equal return 1, else return 0
		{
			return (1);
		}
	return(0);
}

void initialSeats(char flight[][COL],int count) //initializing the flight charts to O or X randomly
{
	for (int j = 0; j < ROW; j++) //initializing the entire array to O using nested for loops
		{
			for (int k = 0; k < COL; k++)
				{
					flight[j][k] = 'O';
				}
		}

	for (int i = 1; i <= count; i++) //insert random number of taken seats in random locations (count is a random number 1-20 from main)
		{
			int row = rand() % ROW; //random row
			int col = rand() % COL; //random column

			while (flight[row][col] == 'X') //if the seat in row, col is already taken, continue to re-randomize row and col until an open seat is found (error check)
				{
					row = rand() % ROW; 
					col = rand() % COL;
				}

			flight[row][col] = 'X'; //assign a random seat not already taken to X 
		}
}

void printFlightMap(char flight[][COL]) //printing the initialized character array
{
	for (int m = 0; m < ROW; m++) //loopiong through the rows and columns
		{
			for (int n = 0; n < COL; n++)
				{
					printf("%c", flight[m][n]); //print O or X
				}
			puts("");
		}	
	puts("");
}

void flightMenu() //prints the flight options during reserve a seat
{
	printf("\n1. COU --> MIA\n2. COU --> BNA\n3. COU --> LAS\nChoose a flight: ");
}

int getTotalRevenue(char flight1[][COL], char flight2[][COL], char flight3[][COL])
{
	int total = 0; //running total
	for (int i = 0; i < ROW; i++) //looping through the rows and columns
		{
			for (int j = 0; j< COL; j++) 
				{
					if (flight1[i][j] == 'X') //if a seat is taken
						{
							total += costMatrix[i][j]; //add the cost from the costMatrix for that seat to the running total
						}

					if (flight2[i][j] == 'X') 				//by using 3 if statements, if an X is present in two different matrixes in the same index, we get both of them
						{									//within the same for loop to contribute to the running total. if the index an X is in is unique to that matrix,
							total += costMatrix[i][j];		//then it just skips over the other if statements since there must be an O present in the other matrices at that index
						}

					if (flight3[i][j] == 'X')
						{
							total += costMatrix[i][j];
						}
				}
		}
	return (total);
}

void seatReservation(char flight[][COL])
{
	int R; //row
	int C; //column
	printFlightMap (flight);	

	printf("Which seat row do you want?: "); //prompting user to enter a seat row
	scanf("%d", &R);
	while (0 > R || 11 < R)	//error checking to ensure rows between 0-11
		{
			printf("Seat Rows are between 0-11.\nPlease enter a valid row: ");
			scanf("%d", &R);
		}
	
	printf("Which seat column do you want?: "); //prompting user to enter a seat column
	scanf("%d", &C);
	while (0 > C || 5 < C)	//error checking to ensure columns between 0-5
		{
			printf("Seat Columns are between 0-5.\nPlease enter a valid column: ");
			scanf("%d", &C);
		}
	
	while (flight[R][C] == 'X') //error checking a looping if the selected seat has already been reserved
		{
			printf("\nSorry!! That seat has already been reserved. Please Try again.");

			printf("\nWhich seat row do you want?: "); //prompting user to enter a seat row
			scanf("%d", &R);
			while (0 > R || 11 < R)	//error checking to ensure rows between 0-11
				{
					printf("Seat Rows are between 0-11.\nPlease enter a valid row: ");
					scanf("%d", &R);
				}
	
			printf("\nWhich seat column do you want?: "); //prompting user to enter a seat column
			scanf("%d", &C);
			while (0 > C || 5 < C)	//error checking to ensure columns between 0-5
				{
					printf("Seat Columns are between 0-5.\nPlease enter a valid column: ");
					scanf("%d", &C);
				}
		}

	flight[R][C] = 'X'; //assigning the selected seat to X
	printf("\nYour requested seat has been reserved\n");
	printFlightMap (flight); //printing the updated flight map

}


void printMessage(char name[],char num[])
{
	char message[MAX]; //defining a character array to merge the two strings
	int counter1 = 0; //increment by 1
	int counter2 = 0; //increment by 2. we need an icrement by two counter since for every one index for name and num strings, we get 2 characters for new array message.

	while (name[counter1] != '\0' && num[counter1] != '\0' && counter1 < MAX) //while neither of the indexes of name or num are NULL
		{
			message[counter2] = name[counter1]; //assign message[0] to name[0]
			message[counter2 + 1] = num[counter1]; //assign message[1] to num[0], the plus 1 in the index works together with counter2 += 2 to make sure the string is correct. 
			counter1++; //increase the index of name and counter by 1
			counter2 += 2; //increase the index of message by 2
		}

	if (name[counter1] == '\0') //if the name is shorter than the flight number
		{
			while (num[counter1] != '\0')
				{
					message[counter2] = num[counter1]; //assign the rest message[] to the remainder of num[]
					counter1++;
					counter2++;
					
					if (counter2 == 24) //breaking after 24 spaces in the array have been filled 
						{
							break;
						}

				}
		}

	if (num[counter1] == '\0') //if the flight number is shorter than the name
		{
			while (name[counter1] != '\0') //assign the rest of message[] to the remainder of name[]
				{
					message[counter2] = name[counter1];
					counter1++;
					counter2++;

					if (counter2 == 24) //breaking after 24 spaces have been filled (if name is extremely long, cut it off after message[] reaches 24 characters
						{
							break;
						}
				}
		}

	message[counter2] = '\0'; //end message[] with \0
	printf("Congrats %s! Your flight %s is booked, enjoy your trip\n", name, num); //printing name and num strings
	printf("\nYour e-ticket number is: %s\n\n", message); //printing the mixed array message[]

}

/*
 * Function: getSafeString
 * Parameters:
 * string - the target where the input string will be stored
 * maxsize - the largest string that can be input, including the null-terminator
 * Discussion:
 * This function inputs a string from stdin that can contain any character, except newline.  The function will return when a newline is entered.  
 * Newline is not included in the string.  The string will be null-terminated.  Characters beyond the max will be thrown away.
 * By: Jim Ries
 * Date: 20181007
*/
void getSafeString(char *string, int maxsize)
{
	int indexcur = 0;
	char charcur = '\n';
				
	//Spin until we get something other than newline
	while ('\n'==charcur)
		{
			charcur = getc(stdin);
		}
				 						
	while (indexcur<(maxsize-1) && '\n'!=charcur)
		{
			if ('\n'!=charcur)
				{
				 	string[indexcur] = charcur;
				}
			indexcur++;
			charcur = getc(stdin);
		}

	string[indexcur] = '\0';
					 																								
	//Spin until they hit enter
	while ('\n'!=charcur)
		{
			charcur = getc(stdin);
		}
}
					
