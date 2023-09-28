/*----------------------------------------------------------------------------
-		                 SE 185: Lab 04 - Debugging Code	    	         -
-	Name: Aden Koziol																	 -
- 	Section: 5																 -
-	NetID: akoziol@iastate.edu																     -
-	Date: 9/20/2022																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab04-1_4.c -o lab04-1_4
// Run with ./lab04-1_4
/* This program calculates the energy of one photon
 * of user-inputted wave-length of light */

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    // double speed_of_light!;
	double speed_of_light; //took out !
    // double wave-length;
	double waveLength; //took out -
    // double ~length_in_meters;
	double length_in_meters; //took out ~
    // double plank const;
    // double 0energy;
	double energy; // took out 0

    const double plank = 6.62606957 * pow(10, -34); // Planck's constant //initialized plank here
    //speed_of_light! = 2.99792458 * pow(10, 8); // Constant for the speed of light
	speed_of_light = 2.99792458 * pow(10, 8); // Constant for the speed of light //took out !
    // wave-length = 0;
	waveLength = 0; //took out -
    //~length_in_meters = 0;
	length_in_meters = 0; //took out ~
    //0energy = 0;
	energy = 0; //took out 0

    printf("Welcome! This program will give the energy, in Joules,\n");
    printf("of 1 photon with a certain wave-length.\n");
    printf("Please input a wave-length of light in nano-meters.\n");
    printf("Please do not enter a negative, or zero, wave-length.\n");

    // scanf("%lf", &wave-length);
	scanf("%lf", &waveLength); //took out -

    //if (wave-length > 0.0)
	if (waveLength > 0.0) //took out -
    {
        //~length_in_meters = wave-length / pow(10, 9); // Converting nano-meters to meters
		length_in_meters = waveLength / pow(10, 9); // Converting nano-meters to meters // took out ~ and -
        //0energy = (plank const * speed_of_light!) / ~length_in_meters; // Calculating the energy of 1 photon
		energy = (plank * speed_of_light) / length_in_meters; // Calculating the energy of 1 photon // took out 0 and ~ and ! and const
        /*printf("A photon with a wave-length of %08.3lf nano-meters, carries "
               "\napproximately %030.25lf joules of energy.", wave-length, 0energy);*/
		printf("A photon with a wave-length of %08.3lf nano-meters, carries "
               "\napproximately %030.25lf joules of energy.", waveLength, energy); // took out - and 0
    } else
    {
        printf("Sorry, you put in an invalid number.");
        printf("Please rerun the program and try again.");
    }

    return 0;
}
