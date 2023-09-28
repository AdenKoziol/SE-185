/*----------------------------------------------------------------------------
-                     SE 185: Lab 06 - Bop-It!                   -
- Name: Aden Koziol
 -
-  Section:5
 -
- NetID:akoziol@iastate.edu
     -
- Date:10/11/2022
 -
-----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
- Includes
 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
/*----------------------------------------------------------------------------
-                             Prototypes                                   -
-----------------------------------------------------------------------------*/
int correct(int button, int triangle, int circle, int cross, int square);
/*----------------------------------------------------------------------------
-                             Notes                                        -
-----------------------------------------------------------------------------*/
// Compile with gcc lab06.c -o lab06
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -b | ./lab06
/*----------------------------------------------------------------------------
- Implementation
 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int cross = 0;
	int square = 0;
	int triangle = 0; 
	int circle = 0;
	int timeLeft, timePressed, button, i, y, isCorrect;
	int numCorrect = 0;
	char str[20];
	
	srand(time(NULL)); 
	fflush(stdout);
	printf("Press a button to start game\n");
    while(1)
	{
		scanf("%d, %d, %d, %d, %d", &timeLeft, &triangle, &circle, &cross, &square);
		//printf("\n%d, %d, %d, %d, %d", timeLeft, triangle, circle, cross, square);
		if(triangle == 1 || circle == 1 || cross == 1 || square == 1)
		{
			timePressed = timeLeft;
			break;
		}	
	}
	Sleep(200);
	printf("\nGame started\n");
	
	
	for(y = 2500; y > 0; y -= 100)
	{
		button = rand() % 4;
		if(button == 0)
			strcpy(str, "triangle");
		if(button == 1)
			strcpy(str, "circle");
		if(button == 2)
			strcpy(str, "cross");
		if(button == 3)
			strcpy(str, "square");
		printf("\nYou have %d ms to press %s\n", y, str);
		
		while(1)
		{
			scanf("%d, %d, %d, %d, %d", &timeLeft, &triangle, &circle, &cross, &square);
			//printf("\n%d, %d, %d, %d, %d", timeLeft, triangle, circle, cross, square);
			if(timePressed + y > timeLeft && timePressed + 150 < timeLeft)
			{
				if(correct(button, triangle, circle, cross, square) == 1)
				{
					printf("\nWrong Button\n");
					y = 0;
					break;
				}
				if(correct(button, triangle, circle, cross, square) == 0)
				{
					timePressed = timeLeft;
					numCorrect++;
					break;
				}
			}
			if(timePressed + y < timeLeft)
			{
				printf("\nYou ran out of time\n");
				y = 0;
				timePressed = timeLeft;
				break;
			}

		}
	}
	fflush(stdout);
	printf("\nYour Score: %d", numCorrect);
	return 0;
}
int correct(int button, int triangle, int circle, int cross, int square)
{
	if((button == 0 && cross == 1) || (button == 0 && circle == 1) || (button == 0 && square == 1))
		return 1;
	else if((button == 1 && cross == 1) || (button == 1 && triangle == 1) || (button == 1 && square == 1))
		return 1;
	else if((button == 2 && triangle == 1) || (button == 2 && circle == 1) || (button == 2 && square == 1))
		return 1;
	else if((button == 3 && cross == 1) || (button == 3 && circle == 1) || (button == 3 && triangle == 1))
		return 1;
	if(button == 0 && triangle == 1 && circle == 0 && cross == 0 && square == 0)
		return 0;
	else if(button == 1 && triangle == 0 && circle == 1 && cross == 0 && square == 0)
		return 0;
	else if(button == 2 && triangle == 0 && circle == 0 && cross == 1 && square == 0)
		return 0;
	else if(button == 3 && triangle == 0 && circle == 0 && cross == 0 && square == 1)
		return 0;
	else
		return 2;
}
