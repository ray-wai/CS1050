//Raymond Waidmann
//rcw5k2
//e-HW1

#include <stdio.h>

void displaymenu(); //prints the display options
int errorcheck(int option); //error check inputs for displaymenu f(x), return 0 if invalid input, return 1 if valid
int errorcheckunits(int units); //error check for valid unit inputs, if unit<0, return 0; if unit input is valid, return 1
float getrate(int units, int option); //takes user's unit and option and determines rate (in tenths of cents) per kWH by looking at the given number of units, return the rate. 
int charge(int option); //takes menu option and determines connection charge, return connection charge
int NumCheck(int); //error check function for bonus

int main(void)
{
	int sentinel; //value to terminate the program from running again (0)
	int counter; //number of times the while loop has executed
	
	sentinel = 1; //terminates the whiule loop if the user chooses to do so
	counter = 0; //allows us to print the number of times we ran the loop in the final total statement at the end

	while (1 == sentinel) //allows us to calculate the bill as many times we want
{
	
//selecting the type of bill and error checking to ensure valid input
	int selection; //1, 2, or 3 for the type of bill
	displaymenu(); //display the menu and error check for valid slelection
	scanf("%d", &selection);

	while (0 == errorcheck(selection)) //call the errorcheck f(x) and ensure valid input, if input is not valid, print error and rescan
		{
			printf("\nInvalid Choice! Please enter a valid choice: ");
			scanf("%d", &selection); //prompt for new selection if necessary
		}

//selecting the amount of energy consumed and error checking to ensure valid input
	int units; //amount of energy consumed
	printf("Enter the number of units in kWH: ");
	scanf("%d", &units); 

	while (0 == errorcheckunits(units)) //call the errorcheckunits f(x) and ensure valid input, if input is not valid, print error and rescan
		{
			printf("\nInvalid input!!!\nEnter the number of units in kWH: ");
			scanf("%d", &units); //prompt for new selection if necessary
		} 

//getting the rate from function getrate and calculating the usage cost based on units consumed, and rate of charge
	float rate;
	rate = getrate(units, selection); //getting the rate based on units consumed and selection type

//new variable usagecost finds the cost of energy consumed via rate*units consumed
	int usagecost;
	usagecost = rate * units; //calculating the total cost of energy used based on units consumed and selection type

			/*
   				//USE THIS AND THE ONE BELOW THE IFF STATEMENT TO CHECK TO ENSURE CORRECT ROUNDING UP OF TENTHS OF PENNIES IN PROGRAM TESTING
				printf("rate: %f\n", rate); //here so program will compile
				printf("usage cost pre rounding:%d\n", usagecost);
			*/

//little rounding trick!!! if tenths of pennies are still involved, round up 1/2 penny to make a whole penny (round up the 1/2 penny if the charge has fractional pennies))
	if (0 != usagecost % 10) //rounding the cost up for fractions of pennies
		{
			usagecost += 5; //rounding up half a penny if the usage cost is not a whole number of pennies (since they are only in 1/2 penny increments)
		}

			/*  
			    //USE THIS TO SHOW CORRECT ROUNDING IF NECESSARY AFTER THE IF STATEMENT IN PROGRAM TESTING
				printf("rate: %f\n", rate); //here so program will compile
				printf("usage cost post rounding:%d\n", usagecost);
			*/

//converting usagecost to a float now that we are certain it only contains whole values of pennies
	float usagecostfloat;
	usagecostfloat = usagecost;

//finding the connection charge based on the selection by calling charge function
	int connectioncharge; 
	connectioncharge = charge(selection); //get the connection charge from called funtion charge

//at this point we have the usage cost in 1/10's of pennies, but ending in a 0 after error check meaning we have a whole number of pennies total (usagecostfloat) 
//and the connection charge (connectioncharge) in 1/10's of pennies (also whole number of pennies) so now we just have to convert them to dollars and add

	float totaltenth; //total in tenths of pennies
	float totaldollar; //total in dollars
	float usagecost1000; //usagecost in dollars
	float connectioncharge1000; //connection charge in dollars

	float TOT; //total of all the totals to be printed at the end of the program, before the bonus
	float TOT1000;
	
	totaltenth = usagecostfloat + connectioncharge; //adding the usagecost and connectioncharge in tenths of pennies to get the total charge in tenths of pennies
	totaldollar = totaltenth/1000; //calculating the total charge in dollars to display to user
	usagecost1000 = usagecostfloat/1000; //converting usagecost to dollars to display result to user
	connectioncharge1000 = connectioncharge/1000; //converting connectioncharge to dollars to display result to user

	TOT = TOT + totaltenth;
	TOT1000 = TOT/1000;
	

			/*
			 	//USE THIS IN TESTING TO ENSURE OUTPUT VALUES FOR VARIABLES ARE CORRECT AND NOT ROUNDED INCORRECTLY
				printf("usagecostfloat: %f\n", usagecostfloat);
				printf("usagecost: %d\n", usagecost);
				printf("totaltenth:  %f\n", totaltenth);
				printf("total dollar: %f\n", totaldollar);
				printf("usagecostdollar(1000): %f\n", usagecost1000);
				printf("connectionchargedollar(1000); %f\n", connectioncharge1000);
			*/

	printf("\nTotal energy charge for the customer is: $%.2f", usagecost1000);
	printf("\nConnection charge for this customer is: $%.2f", connectioncharge1000);
	printf("\nTotal bill due from this connection is: $%.2f\n\n", totaldollar);

	printf("Do you want to continue and calculate another bill? If yes enter 1, if no enter 0: "); //prompting user to calculate another bill
	scanf("%d", &sentinel); //scanning for the sentinel value (0 terminates program)

	while (0 != sentinel && 1 != sentinel) //error checking the sentinel value
		{
			printf("\nInvalid value! Enter a 1 to recalculate or 0 to terminate: ");
			scanf("%d", &sentinel);
		}

	counter++;

	if (0 == sentinel)
		{
			printf("\nYou calculated the bill %d time(s) and the total amount from all the bills due is: $ %.2f\n\n", counter, TOT1000);
		}
} //brace for the while loop





//BONUS!!!

//take positive int as input (error check) print numbers from one to int, product of all numbers, all evens, and all odds, use for loop

	int N; //number to be input by user
	printf("\n*****BONUS***** (lines 12, 140-211)\nEnter a number: ");
	scanf("%d", &N);


	while(NumCheck(N) == 0) //using numcheck function to check if input is a positive integer
		{
			printf("Error! Please enter a positive integer: ");
			scanf("%d", &N); //scan in the users input again 
		}

	for (int x = 1; x <= N; ++x) //loop that runs an equivalent number of times as the input
		{
			int prod; //product of all numbers 
			int odds; //product of all odds
			int evens; //product of all evens

			if (1 == x) //on the first loop
				{
					printf("\nThe numbers are:"); //printing the "header"
					prod = 1; 
					odds = 1; //assigning 1 (as opposed to 0) to all of the variables we will be multiplying over and over in this loop, this way if statements below don't yield 0 at the end (0*0*0*0*0...)
					evens = 1;
				}
			printf(" %d", x); //printing numbers 1 through N
			
			prod = prod * x; //multiplying every number by every number

			if (x % 2 == 1) //if the number is odd, multiply it by the product of all the other odd numbers
				{
					odds = odds * x;
				}

			if (x % 2 == 0) //if the number is even, multiply it by the product of all the other even numbers
				{
					evens = evens * x;
				}

			if (x == N) //on the last loop
				{
					printf("\n\nThe product of all the numbers from 1 to %d is %d", x, prod); 
					printf("\nThe product of all the even numbers is %d", evens); //print the results
					printf("\nThe product of all the odd numbers is %d\n\n", odds); 
				}

			}

//BONUS!!





} //brace for main


//BONUS!!
int NumCheck(int x) //check if number of classes (n) is <=1 and if it is return 0 else return 1
	{
		if (x<1)
			{
				return (0); //if 0 is returned to main, the while loop repeats again and asks for a new number of courses
			}

		return (1); //if a 1 is returned to main, the while loop is exited and the program cointinues

	}
//BONUS

void displaymenu() //prints the display options
	{
		printf("\n\n*****ELECTRICITY BILL CALCULATOR*****\n\n");
		printf("1. Residential\n2. Commercial\n3. Industrial\n\nChoose the type of connection: ");

	}

int errorcheck(int option) //error check inputs for displaymenu f(x), return 0 if invalid input, return 1 if valid
	{
		if (1 == option || 2 == option || 3 == option)
			{
				return(1);
			}
		return(0);
	} 

int errorcheckunits(int units) //error check for valid unit inputs, if unit<=0, return 0; if unit input is valid, return 1
	{
		if (0 <= units)
			{	
				return(1);
			}
		return(0);
	}

float getrate(int units, int option) //takes user's unit and option and determines rate (in cents) per kWH by looking at the given number of units, return the rate. 
{
	float rate;
	if (1 == option) //if residential
		{
			if (0 <= units && 200 >= units)
				{
					rate = 75; //returning rate in tenths of cents
				}

			else if (200 < units && 700 >= units)
				{
					rate = 100; //returning rate in tenths of cents
				}

			else if (700 < units && 1250 >= units)
				{
					rate = 135; //returning rate in tenths of cents
				}

			else if (1250 < units)
				{
					rate = 150; //returning rate in tenths of cents
				}

		}

	else if (2 == option) //if commercial
		{
			if (0 <= units && 300 >= units)
				{
					rate = 105; //returning rate in tenths of cents
				}

			else if (300 < units && 1000 >= units)
				{
					rate = 140; //returning rate in tenths of cents
				}

			else if (1000 < units && 2000 >= units)
				{
					rate = 175; //returning rate in tenths of cents
				}

			else if (2000 < units)
				{
					rate = 200; //returning rate in tenths of cents
				}

		}

	else if (3 == option) //if industrial
		{
			if (0 <= units && 500 >= units)
				{
					rate = 365; //returning rate in tenths of cents
				}

			else if (500 < units && 2000 >= units)
				{
					rate = 400; //returning rate in tenths of cents
				}

			else if (2000 < units && 3000 >= units)
				{
					rate = 455; //returning rate in tenths of cents
				}

			else if (3000 < units)
				{
					rate = 500; //returning rate in tenths of cents
				}

		}

	return (rate); //returning the appropriate rate back to main

}

int charge(int option) //takes menu option and determines connection charge, return connection charge
{
	int charge;
	if (1 == option)
	{	
		charge = 25000; //$25 in 1/10's of pennies
	}

	if (2 == option)
	{	
		charge = 90000; //$90 in 1/10's of pennies
	}

	if (3 == option)
	{	
		charge = 850000; //$850 in 1/10's of pennies
	}

	return (charge); //returning the appropriate connection charge back to main
}


