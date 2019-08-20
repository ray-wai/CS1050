//Raymond Waidmann
//rcw5k2
//Lab 4

#include <stdio.h>

int courseNumCheck(int);
float getScore(void);
int getUnit(void);
int scoreErrorCheck(float);
int unitErrorCheck(int);
int getScorePoint(float);
void printComment(float);
int computeSCU(float, int); //BONUS!!

int main(void)
{
		int n;//number of courses

		//displaying and getting user input for number of courses
		printf("\n==============================\n");
		printf("Student GPA Calculator \n");
		printf("==============================\n");
		printf("Enter the number of courses: ");
		scanf("%d", &n);
		
		while(courseNumCheck(n) == 0) //using the coursenumcheck function to check if the number of courses is greater than 1
			{
				printf("Error! Please enter a Number of Courses greater than 1: ");
				scanf("%d", &n); //scan in the users input again since courseNumCheck returned a 0
			}

		for (int x=1; x<=n; ++x) //running a loop equivalent to the number of courses there are (n = 7, for loops 7 times)
			{	
				printf("\nEnter the Student Score for Course %d (Percent): ", x); //prompt user for a score
				float score = getScore(); //call function getScore and scan and return a score, error check score to ensure valid input
				printf("Enter the number of units for course %d: ", x); //prompts user for course units
			    int courseunits = getUnit(); //call the function getUnit and scan and return course units, error check to ensure valid input
				float scorepoint = getScorePoint(score); //send score to function getScorePoint and assign a score to correct point value
				
				//BONUS!!!
				int top = computeSCU(scorepoint, courseunits); //send scorepoint and courseunits to computeSCU, function prints product
				//BONUS!!

				float toptotal = toptotal + top; //running total of products from line 43, allows us to calculate numerator of GPA calculator expression
				float courseunitstotal = courseunitstotal + courseunits; //creating a running total of the course units (DENOMINATOR)

		
					if (x == n) //on the last loop
						{
							float GPA;
							GPA = toptotal/courseunitstotal; //numerator from expression / denominator of expression (lines 45 and 46)
							printf("\nThe Student GPA: %.2f\n", GPA); //print the GPA
							printComment(GPA); //call print comment function which prints the correct comment
						}
			}
		
		printf("I DID THE BONUS!! (lines 14, 42, 201-207)\n\n");

		return (0);
}
	




int courseNumCheck(int x) //check if number of classes (n) is <=1 and if it is return 0 else return 1
	{
		if (x<=1)
			{
				return (0); //if 0 is returned to main, the while loop repeats again and asks for a new number of courses
			}

		return (1); //if a 1 is returned to main, the while loop is exited and the program cointinues

	}

float getScore() //scan for a grade
	{
		float grade;
		scanf("%f", &grade);

		while(scoreErrorCheck(grade) == 0) //using the score error check function to check if the number of courses is greater than 1
			{
				printf("Error! Please enter a valid course score: ");
				scanf("%f", &grade); //scan in the users input again since scoreErrorCheck returned a 0
			}

		return grade; //returning grade to main so we can use it to calculate scorePoint
		
	}

int getUnit(void)
	{
		int unit;
		scanf("%d", &unit);

		while (unitErrorCheck(unit) == 0) //error checking course unit to ensure it is a valid input
			{
				printf("Error! Please enter a course unit greater than 0: ");
				scanf("%d", &unit);
			}
		
		return unit; //returning course uniit to main so that we can use it to calculate SCU (numerator) and total course units (denom) in GPA expression
		
	}

int scoreErrorCheck(float x)
	{
		if (x<=0 || x>100) //error checking to see if the course score is between 0 and 100
			{
				return (0); //if 0 is returned to getScore, the while loop repeats again and asks for a new score
			}

		return (1); //if a 1 is returned to getScore, the while loop is exited and the program cointinues
	}

int unitErrorCheck(int x)
	{
		if (x<=0) //error checking to see if the course units is a valid input (positive integer)
			{
				return (0); //if 0 is returned to getUnit, the while loop repeats again and asks for a new number of units
			}

		return (1); //if a 1 is returned to getUnit, the while loop is exited and the program cointinues
	}

int getScorePoint(float y)//score = y, use y to calculate the point
	{
		float point;

		if (90<=y && y<=100) //based on what the score is, assign a value to point and return point back to main
			{
				point = 4;
			}
	
		else if (80<=y && y<=89)
			{
				point = 3;
			}


		else if (70<=y && y<=79)
			{
				point = 2;
			}

		else if (60<=y && y<=69)
			{
				point = 1;
			}

		else
			{
				point = 0;
			}

		return (point);

	}

void printComment (float z) //where z = GPA
	{	
		printf ("==============================\nComment: ");

				if (3.8<=z && z<=4.0) //based on what the GPA is, print the appropriate comment
					{
						printf("Outstanding!!\n");
					}

				else if (3.5<=z && z<=3.79)
					{
						printf("Excellent!!\n");
					}

				else if (3.0<=z && z<=3.49)
					{
						printf("Good!!\n");
					}

				else if (2.5<=z && z<=2.99)
					{
						printf("Satisfactory!!\n");
					}

				else if (2.0<=z && z<=2.49)
					{
						printf("Not Satisfactory!!\n");
					}

				else
					{
						printf("Do better next semester!!\n");
					}
				
		printf ("==============================\n\n");

	}

//BONUS!!
int computeSCU(float x, int y) //calculating the components of the numerator
	{
		int top; //numerator
		top = x * y; //each numerator component = scorepoint*courseunits
		printf("Multiplication of SCP and CU: %d\n", top); //printing the result
		return (top); //returning the result to main so we can have a running total of the numerator (line 45)
	}
//BONUS!!

