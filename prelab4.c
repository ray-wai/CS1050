//Raymond Waidmann
//rcw5k2
//Prelab 4

#include <stdio.h>

int courseNumCheck(int);
float getScore(void);
float getScorePoint(float);
void printComment(float);

int main(void)
{
		int n;//number of courses

		//displaying and getting user input for number of courses
		printf("\n==============================\n");
		printf("Enter the Number of Courses: \n");
		printf("==============================\n");
		scanf("%d", &n);
		
		while(courseNumCheck(n) == 0) //using the coursenumcheck function to check if the number of courses is greater than 1
			{
				printf("Error! Please enter a Number of Courses greater than 1: \n");
				scanf("%d", &n); //scan in the users input again since courseNumCheck returned a 0
			}

		for (int x=1; x<=n; ++x) //running a loop equivalent to the number of courses there are (n = 7, for loops 7 times)
			{	
				printf("Enter the Student Score for Course %d (Percent): ", x); //prompt user for a score
				float score = getScore(); //call function getScore and scan and return a grade, error check grade to ensure valid input
				float point = getScorePoint(score); //send score to function getScorePoint and assign a score to correct point value
				printf("Point =  %.2f\n", point); //printing the point value for the grade for EACH grade
				float pointtotal = pointtotal + point; //creating a running total of the point total so that we can calculate ASP

					if (x == n) //on the last loop
						{
							float ASP;
							ASP = pointtotal/n; //average the scores
							printf("\nThe Student ASP: %.2f\n", ASP); //print the average of the scvortes
							printComment(ASP); //call print comment function which prints the correct comment
						}
			}
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
		int grade;
		scanf("%d", &grade);

		while (grade < 0 || grade > 100) //error checking grade to ensure it is a valid input
			{
				printf("Error! Please enter a valid grade: \n");
				scanf("%d", &grade);
			}
		
		return grade; //returning this number to main so we can send it to the getScorePoint function
		
	}


float getScorePoint(float y)//score = y, use y to calculate the point
	{
		float point;

		if (95<=y && y<=100) //based on what the score is, assign a value to point and return point back to main
			{
				point = 4.00;
			}
	
		else if (90<=y && y<=94)
			{
				point = 3.50;
			}


		else if (85<=y && y<=89)
			{
				point = 3.00;
			}

		else if (80<=y && y<=84)
			{
				point = 2.50;
			}

		else if (75<=y && y<=79)
			{
				point = 2.00;
			}

		else if (70<=y && y<=74)
			{
				point = 1.00;
			}

		else
			{
				point = 0.00;
			}

		return (point);

	}


void printComment (float z) //where z = ASP 
	{	
		printf ("==============================\nComment: ");

				if (3.8<=z && z<=4.0) //based on what the ASP is, print the appropriate comment
					{
						printf("Excellent\n");
					}

				else if (3.5<=z && z<=3.79)
					{
						printf("Very Good\n");
					}

				else if (3.0<=z && z<=3.49)
					{
						printf("Good\n");
					}

				else if (2.5<=z && z<=2.99)
					{
						printf("Satisfactory\n");
					}

				else if (2.0<=z && z<=2.49)
					{
						printf("Not Passed\n");
					}

				else
					{
						printf("Unofficial Drop\n");
					}
				
		printf ("==============================\n\n");

	}


