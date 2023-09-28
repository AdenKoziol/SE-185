/*----------------------------------------------------------------------------
-		                 SE 185: Lab 04 - Debugging Code	    	         -
-	Name: Aden Koziol															 -
- 	Section: 5																 -
-	NetID: akoziol@iastate.edu																     -
-	Date: 9/20/2022																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab04-1_1.c -o lab04-1_1
// Run with ./lab04-1_1
/* This program outputs if a integer will divide into another integer with no remainder. */

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int i, j;

    // printf("Enter an integer: ")
	printf("Enter an integer: "); //Added semicolon
    scanf("%d", &i);

    // printf("Enter another integer: );
	printf("Enter another integer: "); // added quotation
    // scanf("%d", &j)
	scanf("%d", &j); //added semicolon

    if (j % i == 0)
    {
        printf("%d divides %d\n", i, j);
	}
    // } else
	else{ //separated the else from the curly brace of the if statement and added curly brace for else statement

        // pritf("%d does not divide %d\n", i, j);
		printf("%d does not divide %d\n", i, j); //printf was spelled wrong
        printf("%d %% %d is %d\n", j, i, (j % i));
    }

    return 0;
}
