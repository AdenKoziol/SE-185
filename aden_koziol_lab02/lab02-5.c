/*----------------------------------------------------------------------------
-		        SE 185: Lab 02 - Solving Simple Problems in C	    	 	 -
-	Name:																	 -
- 	Section:																 -
-	NetID:																     -
-	Date:																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>   // Google this header file to learn more! :)

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    double a, b, c;
    double filler;

	printf("Enter a value for a: ", a);
	scanf("%lf", &a);
	printf("Enter a value for b: ", b);
	scanf("%lf", &b);
	c = sqrt(pow(a, 2) + pow(b, 2));
	printf("The value of c is: %lf", c);

    return 0;
}
