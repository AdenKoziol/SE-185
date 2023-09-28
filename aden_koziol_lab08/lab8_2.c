/*-----------------------------------------------------------------------------
-					  		SE 185 Lab 08
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name: Aden Koziol
- Section: 5
-	NetID: akoziol@iastate.edu
-	Date: 11/1/2022
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-								Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


/*-----------------------------------------------------------------------------
-								Defines
-----------------------------------------------------------------------------*/
/* Mathmatical constants */
#define PI 3.14159

/* 	Screen geometry
    Use ROWS and COLUMNS for the screen height and width (set by system)
    MAXIMUMS */
#define COLUMNS 100
#define ROWS 80

/* 	Character definitions taken from the ASCII table */
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '

/*	Number of samples taken to form an moving average for the gyroscope data
    Feel free to tweak this. */
#define NUM_SAMPLES 10
#define MAXPOINTS 10000

/*-----------------------------------------------------------------------------
-								Static Data
-----------------------------------------------------------------------------*/
/* 2D character array which the maze is mapped into */
char MAZE[COLUMNS][ROWS];


/*-----------------------------------------------------------------------------
-								Prototypes
-----------------------------------------------------------------------------*/
/*	POST: Generates a random maze structure into MAZE[][]
    You will want to use the rand() function and maybe use the output %100.
    You will have to use the argument to the command line to determine how
    difficult the maze is (how many maze characters are on the screen). */
void generate_maze(int difficulty);

/*	PRE: MAZE[][] has been initialized by generate_maze()
    POST: Draws the maze to the screen */
void draw_maze(void);

/*	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
    POST: Draws character use to the screen and position x,y */
void draw_character(int x, int y, char use);

/*	PRE: -1.0 < mag < 1.0
    POST: Returns tilt magnitude scaled to -1.0 -> 1.0
    You may want to reuse the roll function written in previous labs. */
double calc_roll(double mag);

/* 	Updates the buffer with the new_item and returns the computed
    moving average of the updated buffer */
double m_avg(double buffer[], int avg_size, double new_item);


/*-----------------------------------------------------------------------------
-								Implementation
-----------------------------------------------------------------------------*/
/*	Main - Run with './ds4rd.exe -t -g -b' piped into STDIN */
void main(int argc, char* argv[])
{
    double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
    double new_x, new_y, new_z;
    double avg_x, avg_y, avg_z;
	int personX = 50, personY = 0, t, currentTime;
	double gx, gy, gz;
	int tempX = 0, tempY = 0;
	int lengthofavg = 25;
	srand((int)time(NULL));

  if (argc != 2)
  {
      printf("You must enter the difficulty level on the command line.");
      refresh();
      return;
  }
  else
  {
    /* 	Setup screen for Ncurses
        The initscr functionis used to setup the Ncurses environment
        The refreash function needs to be called to refresh the outputs
        to the screen */
    initscr();
    refresh();

    generate_maze(atoi(argv[1]));
	draw_maze();

    /* Read gyroscope data and fill the buffer before continuing */

    /* Event loop */
    do
    {
		scanf("%d, %lf, %lf, %lf", &t, &new_x, &new_y, &new_z);
		
		avg_x = m_avg(x, lengthofavg, new_x);
        avg_y = m_avg(y, lengthofavg, new_y);
        avg_z = m_avg(z, lengthofavg, new_z);
		
		if(MAZE[personX][personY + 1] == '*' && MAZE[personX - 1][personY] == '*' && MAZE[personX + 1][personY] == '*')
		{
			printf("\nYou Lose");
			personY = 82;
		}
		
		draw_character(tempX, tempY, EMPTY_SPACE);
        if(t > currentTime + 100)
		{
			if(MAZE[personX][personY + 1] != '*')
			{
				currentTime = t;
				if(MAZE[personX - 1][personY] != '*')
				{
					if(avg_x > .5)
						personX--;
				}
				if(MAZE[personX + 1][personY] != '*')
				{
					if(avg_x < -.5)
						personX++;
				}
				if(MAZE[personX][personY + 1] != '*')
					personY++;
			}
			else
			{
				currentTime = t;
				if(MAZE[personX - 1][personY] != '*')
				{
					if(avg_x > .5)
						personX--;
				}
				if(MAZE[personX + 1][personY] != '*')
				{
					if(avg_x < -.5)
						personX++;
				}
			}
		}
		draw_character(personX, personY, AVATAR);
		tempX = personX;
		tempY = personY;
		if(personY == 79)
			printf("\nYou Win");
    } while(personY < 80 && personX > -1 && personX < 100);

    /* Print the win message */


    /* This function is used to cleanup the Ncurses environment.
    Without it, the characters printed to the screen will persist
    even after the progam terminates */
    endwin();

  }

}

double m_avg(double buffer[], int avg_size, double new_item)
{
	int i;
	for(i = 0; i < avg_size; i++)
		buffer[i] = buffer[i + 1];
	buffer[i] = new_item;
	double avg = 0;
	for(i = 0; i < avg_size; i++)
		avg += buffer[i];
	avg /= avg_size;
	return avg;
}


/* 	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
    POST: Draws character use to the screen and position x,y
    THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
    DO NOT NEED TO CHANGE THIS FUNCTION. */
void draw_character(int x, int y, char use)
{
    mvaddch(y,x,use);
    refresh();
}

double calc_roll(double mag)
{
	if(mag > 1.0)
		mag = 1.0;
	if(mag < -1.0)
		mag = -1.0;
	return mag;
}

void generate_maze(int difficulty)
{
	int i, j, num;
	for(i = 0; i < COLUMNS; i++)
	{
		for(j = 0; j < ROWS; j++)
		{
			num = rand() % 100;
			if(num < difficulty)
				MAZE[i][j] = '*';
			else
				MAZE[i][j] = ' ';
		}			
	}
}

void draw_maze(void)
{
	int i, j;
	for(i = 0; i < COLUMNS; i++)
	{
		for(j = 0; j < ROWS; j++)
		{
			draw_character(i, j, MAZE[i][j]);
		}
	}
}