// Rami Musleh - prog71990 w25 - Assignment 4 Q2
#pragma once

// DEFS
	#define NAMELIMIT 50
	#define MAXROOMS 10
	#define USERSELECTIONLIMIT 2
	#define MAXLIMIT 1000
	#define BUFFER 255
	#define FILENAME "BookingData.txt"
	#define ROOM_FORMAT_OUT "%d, %s, %s, %s\n"
	#define LINESIZE 50
	#define INPUTLIMIT 50
	#define ARRAYLIMIT 4



// STRUCTS
	typedef struct Rooms {

		int roomNumber;				// room identification number
		char roomStatus[NAMELIMIT];	// a marker that indicates whether the room is booked
		char lastName[NAMELIMIT];	// the last name of the booking guest
		char firstName[NAMELIMIT];	// the first name of the booking guest.

	}ROOMS;

	ROOMS rooms[MAXROOMS]; // Array of rooms




// FUNCTIONS HEADERS

// FILE FUNCTIONS
	bool AccessFile();
	bool ReadFile(ROOMS room[]);
	bool NewFile(ROOMS room[]);


// ROOM STRUCT FUNCTIONS
	ROOMS CreateRoom(	ROOMS RoomName, int RoomNumber, char* status,
						char* firstName, char* lastName, FILE* fp);

	ROOMS ReplaceRoom(ROOMS RoomName, int RoomNumber, char* status,
		char* firstName, char* lastName, FILE* fp);


	
	
// ROOM FUNCTIONS
	bool AddRoom(ROOMS room[], int i, char* status, char* firstName,
				 char* lastName);

	bool DeleteRoom(ROOMS room[], int i, char* status, char* firstName, char* lastName);

	bool MainMenu();

	bool NumberOfEmptyRooms();

	bool ListOfEmptyRooms();

	bool AlphaOrderGuests();
	bool OrderByFirstName();
	bool OrderByLastName();

	bool BookARoom();

	bool DeleteABooking();





