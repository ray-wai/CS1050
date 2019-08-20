//Raymond Waidmann
//rcw5k2
//Lab 3

#include <stdio.h>
#include <math.h>

int main(void)

{ 
	int selection; //two legs or one leg and one hypo
	int leg1; //length of first leg
	int leg1sq; //leg1 squared
	
//making the entire triangle calculation repeat as necessary
	int repeat; //variable the user can input at the end to repeat the calculation
	repeat = 0;
	while (0 == repeat)	
		{

			//making a selection and error check
				//picking between the different triangle options
				printf("Right triangle calculation type\n\n(1) Two triangle legs\n(2) One leg one hypotenuse\nPlease make a selection: \n");
				scanf("%d", &selection);

					//error check for selection
					while (1 != selection && 2 != selection)
						{
							printf("\nIncorrect choice, please make a new selection: ");
							printf("\nRight triangle calculation type\n(1) Two triangle legs\n(2) One leg one hypotenuse\nPlease make a selection: \n");
							scanf("%d", &selection);
						}





			//getting the first leg for both since both options require at least one leg
				//getting the first leg
				printf("Enter a length for the first leg: \n");
				scanf("%d", &leg1);

					//error check for first leg
					while (0 >= leg1 || 100 < leg1)
						{
							printf("Incorrect value, length shoud be between 1-100\nEnter a new length for the first leg: \n");
							scanf("%d", &leg1);
						}

				//squaring the first leg since we need it in both scenarios
				leg1sq = pow(leg1, 2);





			//getting the second leg if option 1 and displaying hypotenuse result
				//determining the second leg if option 1 is selected
				if (1 == selection)
					{

						int leg2; //length of second leg (option 1)
						int leg2sq; //leg2 squared (option 1)
						int leg1sqleg2sq; //leg 1 squared plus leg 2 squared (option 1)
						double hypo1; //value of hypotenuse (option 1)

						printf("Enter a length for the second leg: \n");
						scanf ("%d", &leg2);

						//error check for the second leg
						while (0 >= leg2 || 101 <= leg2) //use of 101 allows for the inclusion of 100
							{
								printf("Incorrect value, length shoud be between 1-100\nEnter a new length for the second leg: \n");
								scanf("%d", &leg2);
							}

						//squaring the second leg
						leg2sq = pow(leg2, 2);

						//determining the hypotenuse
						leg1sqleg2sq = (leg1sq + leg2sq);
						hypo1 = ((float)(pow(leg1sqleg2sq, 0.5)));

						//displaying the calculation
						printf("Calculation: %d + %d = c^2\n", leg1sq, leg2sq);
						printf("Hypotenuse length = %.2f\n\n", hypo1);
					}





			//getting the hypotenuse if option 2 and displaying the leg result
				//determining the hypotenuse if 
				else if (2 == selection)
					{
						int hypo2; //value of hypotenuse (option 2)
						int hypo2sq; //hypotenuse squared (option 2)
						int hypo2sqleg1sq; //hypotenuse 2 squared minus leg 1 squared (option 2);
						double leg2v2; //value of the second leg (option 2)

						printf("Enter a length for the hypotenuse: \n");
						scanf("%d", &hypo2);

						//error check for the hypotenuse
						//since we already error checked leg1, as long as the hypotenuse is greater than leg 1, we should not have any issues
						while (leg1 >=  hypo2)
							{
								printf("Incorrect value, hypotenuse length cannot be less than or equal to leg length\n");
								printf("Enter a new length for the hypotenuse: \n");
								scanf("%d", &hypo2);
							}

						//squaring the hypotenuse
						hypo2sq = pow(hypo2, 2); 
			
						//determining the missing leg
						hypo2sqleg1sq = (hypo2sq - leg1sq); 
						leg2v2 = ((float)(pow(hypo2sqleg1sq, 0.5)));

						//displaying the calculation
						printf("Calculation: %d + b^2 = %d\n", leg1sq, hypo2sq);
						printf("Missing leg length = %.2f\n\n", leg2v2);
					}

//asking the user if they want to repeat the calculation with new numbers
		printf("Do you wish to calculate again?\nPress 1 for no, 0 for yes: ");
		scanf("%d", &repeat);

		}





//Bonus
	printf("\n\n******** Bonus Part ********\n\n");

		float x; //number that is the base //n
		int n; //number that is the exponent //p

		//getting the base and exponent
		printf("Enter a number: \n"); 
		scanf("%f", &x);
		printf("Enter an exponent: \n");
		scanf("%d", &n);

		//if the exponent is positive
		if (0 < n)
			{
				int counter; //counter for the for loop //i
				float workingresult; //number to be continuously multiplied to yield the result //c
				float x2; //assignment variable to collect the value of x without changing x's value //temp
				workingresult = 1; 
				
				for(counter=1; counter<=n; counter++)
					{
						x2 = x;
						workingresult = workingresult*x2;
					}

				printf("pow(%f, %d) = %f\n\n", x, n, workingresult);
			}
		//if the exponent is zero
		if (0 == n)
			{
				printf("pow(%f, %d) = 1\n\n", x, n);
			}
	
		//if the exponent is negative
		if (0 > n)
			{
				int n2; //making n positive
				n2 = n*(-1);
				
				int counter; //counter for the for loop //i
				float workingresult; //number to be continuously multiplied to yield the result //c
				float workingresult2; //number that is actually the answer
				float x2; //assignment variable to collect the value of x without changing x's value //temp
				workingresult = 1; 
				
				for(counter=1; counter<=n2; counter++)
					{
						x2 = x;
						workingresult = workingresult*x2;
					}
				
				//1 over the positive power to yield the negative power answer
				workingresult2 = ((float)(1/workingresult));

				printf("pow(%f, %d) = %f\n\n", x, n, workingresult2);


			}
	
	return (0);

}

