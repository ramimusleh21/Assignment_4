// Rami Musleh - prog71990 w25 - Assignment 4 Q2 Refactor


/* Question 2: Modeling a hotel reservation system
 Specifications : 6.00 / 8.00 (The program works
and produces the correct results and displays them
correctly and also meets most of the other specifications
or the following issues were noted : )
--Important / correctable compiler warnings and /or output
not addressed

 Readability + Design : 8.00 / 8.00 (The code is exceptionally
well organized and readable due to the use of good variable names,
data and function structure.The code is designed 'defensively'
(meaning garbage is kept out).The code allows for both effective
testing and extension.)

 Reusability : 3.00 / 4.00 (The code has some elements of ADTs
/ modules demonstrating some SRP, coupling and /or cohesion or
the following issues were noted : )
--Globally scoped variables should be avoided unless absolutely
required

 Documentation : 4.00 / 4.00 (The documentation is well written
and clearly explains what the code is accomplishing and how.)
*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include "functions.h"
#include "HotelOne.h"
#include "HotelTwo.h"


int main(void) {

	ROOMS rooms[TOTALROOMS] = { 0 }; // Array of rooms

	AccessFile(rooms);

	bool programOn = true;
	
	while (programOn) {	
		programOn = TopMenu(rooms);

	}

	return 0;
}