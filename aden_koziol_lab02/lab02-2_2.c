/*----------------------------------------------------------------------------
-		        SE 185: Lab 02 - Solving Simple Problems in C	    	 	 -
-	Name: Aden Koziol																 -
- 	Section: 5												 -
-	NetID: akoziol@iastate.edu													     -
-	Date: 9/6/2022																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
	int x, y, z;
	printf("Enter a width: ");
	scanf("%d", &x);
	printf("Enter a height: ");
	scanf("%d", &y);
	printf("Enter a depth: ");
	scanf("%d", &z);
	printf("The volume of a %d x %d x %d rectangle is: %d\n", x, y, z, x*y*z);




    return 0;
}
