#include <stdio.h>
#include <math.h>

int main(void)

{ 
	int selection;
	int length;
	int answer1;
	int answer2;
	double answer3;

	//picking between the different shapes
	printf("Area Calculation\n(1) Square\n(2) Cube\n(3) Circle\nPlease make a selection: \n");
	scanf("%d", &selection);

		//error check for selection
		while (1 != selection && 2 != selection && 3 != selection)
			{
				printf("Incorrect choice, please make a new selection: \n");
				scanf("%d", &selection);
			}
	
	//getting a length
	printf("Enter a positive number: \n");
	scanf("%d", &length);

		//error check for length
		while (0 >= length)
			{
				printf("Number can't be negative or zero\nEnter a positive number: \n");
				scanf("%d", &length);
			}

	//calculating area if square
	if (1 == selection)
		{
			printf("\nLength of the side of square is %d\n", length);
			answer1 = pow(length, 2);
			printf("Area of square is %d\n\n", answer1);
		}

	// calculating area if cube
	else if (2 == selection)
		{
			printf("\nLength of the side of cube is %d\n", length);
			answer2 = 6 * (pow(length, 2));
			printf("Area of cube is %d\n\n", answer2);
		}

	//calculating area if circle
	else if (3 == selection)
		{
			printf("\nRadius of circle is %d\n", length);
			answer3 = ((float)(3.14159 * (pow(length, 2))));
			printf("Area of circle is %.2f\n\n", answer3);
		}

	return (0);

}

