/*----------------------------------------------------------------------------
-		         SE 185: Lab 05 - Conditionals (What's up?)	    	         -
-	Name: Aden Koziol																	 -
- 	Section: 5																 -
-	NetID:	akoziol@iastate.edu															     -
-	Date: 9/27/2022																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
int close_to (double tolerance, double point, double value);
double magnitude(double x, double y, double z);
int orientation(double x, double y, double z, int position);
/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/ 
// Compile with gcc lab05.c -o lab05
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -a -g -b | ./lab05

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int triangle, circle, x_button, square;
    double ax, ay, az, gx, gy, gz;
	int recent = 0;
	int previousMagnitude;
	int position = 0;
	while (1)
    {
        scanf("%lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d",
			&ax, &ay, &az, &gx, &gy, &gz, &triangle, &circle, &x_button, &square);
		
		if(magnitude(ax, ay, az) < .15)
		{
			if(position != orientation(gx, gy, gz, position))
			{
				position = orientation(gx, gy, gz, position);
				if(position == 1)	
					printf("\nTop");
				if(position == 2)
					printf("\nBottom");
				if(position == 3)
					printf("\nLeft");
				if(position == 4)
					printf("\nRight");
				if(position == 5)
					printf("\nFront");
				if(position == 6)
					printf("\nBack");
			}
		}
			
		if(triangle == 1)
				break;
		
		fflush(stdout);
    }

    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */
int close_to (double tolerance, double point, double value)
{
	if (value <= point + tolerance && value >= point - tolerance)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

double magnitude(double x, double y, double z)
{
    return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
}


int orientation(double x, double y, double z, int position)
{
	if(close_to(.15, 0, x) && close_to(.15, 1, y) && close_to(.15, 0, z) && position != 1)
	{
		position = 1;
	}
	else if(close_to(.15, 0, x) && close_to(.15, -1, y) && close_to(.15, 0, z) && position != 2)
	{
		position = 2;
	}
	else if(close_to(.15, 1, x) && close_to(.15, 0, y) && close_to(.15, 0, z) && position != 3)
	{
		position = 3;
	}
	else if(close_to(.15, -1, x) && close_to(.15, 0, y) && close_to(.15, 0, z) && position != 4)
	{
		position = 4;
	}
	else if(close_to(.15, 0, x) && close_to(.15, 0, y) && close_to(.15, -1, z) && position != 5)
	{
		position = 5;
	}
	else if(close_to(.15, 0, x) && close_to(.15, 0, y) && close_to(.15, 1, z) && position != 6)
	{
		position = 6;
	}
	
	return position;
}