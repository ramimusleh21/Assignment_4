// Rami Musleh - prog71990 w25 - Assignment 4 Q2 Refactor

#pragma once

// DEFS
#define NAMELIMIT 50 // I removed defined variables that were not used
#define TOTALROOMS 20
#define MAXROOMS 10
#define BUFFER 255
#define FILENAME "BookingData.txt"
#define ROOM_FORMAT_PRINT "Room %d is a %s Room Booked out to %s %s.\n"
#define ROOM_FORMAT_OUT "%d,%s,%s,%s,%d,%s\n"
#define SCAN_ROOM_FORMAT_OUT "%d,%49s[^,],%49s[^,],%49s[^,],%d,%49s[^,]\n"
#define ROOM_IS_EMPTY "Blank"
#define unbooked "empty"
#define LINESIZE 100
#define INPUTLIMIT 50
#define ARRAYLIMIT 6


// ENUMERATIONS
typedef enum Hotel { 
	
	HotelOne = 1, 
	HotelTwo = 2

} HOTEL;


// STRUCTS
typedef struct Rooms {

	int roomNumber;				// room identification number
	char roomStatus[NAMELIMIT];	// a marker that indicates whether the room is booked
	char lastName[NAMELIMIT];	// the last name of the booking guest
	char firstName[NAMELIMIT];	// the first name of the booking guest.
	char type[NAMELIMIT];
	HOTEL hotel;

}ROOMS;

