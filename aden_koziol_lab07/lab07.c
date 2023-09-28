/*-----------------------------------------------------------------------------
-           SE 185 Lab 07 - The DS4 Equalizer
-             Developed for 185-Rursch by T.Tran and K.Wang
- Name: Aden Koziol
-  Section: 5
- NetID: akoziol
- Date: 10/18/2022
-
-   This file provides the outline for your program
-   Please implement the functions given by the prototypes below and
-   complete the main function to make the program complete.
-   You must implement the functions which are prototyped below exactly
-   as they are requested.
-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
- Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
/*-----------------------------------------------------------------------------
- Defines
-----------------------------------------------------------------------------*/
#define PI 3.141592653589
/* NO GLOBAL VARIABLES ALLOWED */
/*-----------------------------------------------------------------------------
- Prototypes
-----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------
--
    PRE: Arguments must point to double variables or int variables as appropriate
    This function scans a line of DS4 data, and returns
    True when left button is pressed
    False Otherwise
    POST: it modifies its arguments to return values read from the input line.
-----------------------------------------------------------------------------------
-*/
int read_input(int* t, double* x, double* y, double* z, int* triangle, int* circle, int* cross, int* square, int* j_LX, int* j_LY, int* j_RX, int* j_RY) 
{
	scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d", &t, &x, &y, &z, &triangle, &circle, &cross, &square, &j_LX, &j_LY, &j_RX, &j_RY);
	int a = 1;
	if(square == 0)
		return 0;
	else
		return 1;
}
/*-----------------------------------------------------------------------------
    PRE: ~(-1.0) <= mag <= ~(1.0)
    This function scales the roll/pitch value to fit on the screen.
    Input should be capped at either -1.0 or 1.0 before the rest of your
    conversion.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleMagForScreen(double rad)
{
	int num = rad * 39;
	if(num > 39)
		num = 39;
	if(num < - 39)
		num = - 39;
	return num;
}
/*-----------------------------------------------------------------------------
    PRE: -128 <= mag <= 127
    This function scales the joystick value to fit on the screen.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleJoyForScreen(int rad)
{
	double num = -39.0 / 128.0;
	int num1 = num * rad;
	return num1;
	
}
/*----------------------------------------------------------------------------
    PRE: -39 <= number <= 39
    Uses print_chars to graph a number from -39 to 39 on the screen.
    You may assume that the screen is 80 characters wide.
----------------------------------------------------------------------------*/
void graph_line(int number)
{
	
}
/*-----------------------------------------------------------------------------
    PRE: num >= 0
    This function prints the character "use" to the screen "num" times
    This function is the ONLY place printf is allowed to be used
    POST: nothing is returned, but "use" has been printed "num" times
-----------------------------------------------------------------------------*/
void print_chars(int num, char use)
{
	int i;
	if(num > 0)
		{
			printf("\n");
			for(i = 39 - num; i > 0; i--)
				printf(" ");
			for(i = num; i > 0; i--)
				printf("%c", use);
		}
		if(num < 0)
		{
			printf("\n");
			for(i = 0; i < 40; i++)
				printf(" ");
			for(i = num; i < 0; i++)
				printf("%c", use);
		}
		if(num == 0)
		{
			printf("\n");
			for(i = 0; i < 39; i++)
				printf(" ");
			printf("0");
		}
}
/*-----------------------------------------------------------------------------
- Implementation
-----------------------------------------------------------------------------*/
int main()
{
    double x, y, z;                     /* Values of x, y, and z axis*/
    int t;                              /* Variable to hold the time value */
    int triangle, cross, square, circle;  /* Variables to hold the button statuses */
    int j_LX, j_LY, j_RX, j_RY;         /* Variables to hold the joystick statuses */
    int scaled_pitch, scaled_roll;      /* Value of the roll/pitch adjusted to fit screen display */
    int scaled_joy;     				/* Value of joystick adjusted to fit screen display */
	char left = 'L', right = 'R', zero = '0', forward = 'F', back = 'B';
	int trianglePressed = 1;
	int crossPressed = 0;
	int circlePressed = 0;
    /* Put pre-loop preparation code here */
    do
    {
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d", &t, &x, &y, &z, &triangle, &circle, &cross, &square, &j_LX, &j_LY, &j_RX, &j_RY);
        scaled_roll = scaleMagForScreen(x);
		scaled_pitch = scaleMagForScreen(y);
		scaled_joy = scaleJoyForScreen(j_LX);
		
		if(triangle == 1 && cross == 0 && circle == 0)
		{
			trianglePressed = 1;
			crossPressed = 0;
			circlePressed = 0;
		}
		if(triangle == 0 && cross == 1 && circle == 0)
		{
			trianglePressed = 0;
			crossPressed = 1;
			circlePressed = 0;
		}
		if(triangle == 0 && cross == 0 && circle == 1)
		{
			trianglePressed = 0;
			crossPressed = 0;
			circlePressed = 1;
		}
		
		if(trianglePressed == 1)
		{
			if(scaled_roll > 0)
				print_chars(scaled_roll, left);
			if(scaled_roll < 0)
				print_chars(scaled_roll, right);
			if(scaled_roll == 0)
				print_chars(scaled_roll, zero);
		}
		
		if(crossPressed == 1)
		{
			if(scaled_pitch > 0)
				print_chars(scaled_pitch, forward);
			if(scaled_pitch < 0)
				print_chars(scaled_pitch, back);
			if(scaled_pitch == 0)
				print_chars(scaled_pitch, zero);
		}
		if(circlePressed == 1)
		{
			if(scaled_joy > 0)
				print_chars(scaled_joy, left);
			if(scaled_joy < 0)
				print_chars(scaled_joy, right);
			if(scaled_joy == 0)
				print_chars(scaled_joy, zero);
		}
		
			
		/* Calculate and scale for pitch AND roll AND joystick */
        /* Switch between roll, pitch, and joystick with the up, down, and right button, respectivly */
        /* Output your graph line */
        fflush(stdout);
    } while (read_input(&t, &x, &y, &z, &triangle, &circle, &cross, &square, &j_LX, &j_LY, &j_RX, &j_RY) == 0); /* Modify to stop when left button is pressed */
    return 0;
}