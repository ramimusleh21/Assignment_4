// Rami Musleh - prog71990 w25 - Assignment 4 Q2

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include "functions.h"




// The StayRite Hotel Company consists of a single hotel with a room capacity
// of 10. Guests may only stay at the hotel 1 night and each room can only
// accommodate 1 guest.Write a room reservation program with the following
// features :

// (a)The program uses an array of 10 structures.Each structure should hold
// a room identification number, a marker that indicates whether the room
// is booked, the last name of the booking guest, and the first name of the
// booking guest.
//
// The program displays the following menu :
//	To choose a function, enter its letter label :
//		a) Show number of empty(unbooked) rooms
//		b) Show list of the empty(unbooked) rooms
//		c) Show alphabetical listing of guests who have booked a room
//		d) Book a room to a guest
//		e) Delete an existing room booking
//		f) Quit
//
// (c) The program successfully executes the promise of each command on its
//	menu.
//
// (d)Choice c) will list the guests in alphabetic order, either by first or last
//	name(selected by user during program execution).
//
// (e)Choices d) and e) require additional input, and each choice should prompt
//	the user to enter the required data or abort the action.
//
// (f)After executing a particular function(options a) - e)), the program should
//	print the menu again and wait for input.Upon selecting f), the program
//	should exit.
//
// (g)Data is saved in a file between runs.The name and format of the file need
//	not be known to the user.When the program is started(or restarted), it
//	will first attempt to read the data file and populate itself with that data;
//	if there is no existing datafile, the program will create a new (empty)
//	datafile with no data populated.


int main() {
	FILE* fp = fopen("BookingData.txt", "r");

	if (fp == NULL) {
		FILE* fp = fopen("BookingData.txt", "w");
	} 

	AccessRoomStructs();
	
	bool programOn = true;
	while (programOn) {
		int userSelection = MainMenu();

		if (userSelection == false) {
			programOn = false;
		}
	}
	

	return 0;
}