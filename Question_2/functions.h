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



// STRUCTS
	typedef struct Rooms {

		int roomNumber;				// room identification number
		char roomStatus[NAMELIMIT];	// a marker that indicates whether the room is booked
		char lastName[NAMELIMIT];	// the last name of the booking guest
		char firstName[NAMELIMIT];	// the first name of the booking guest.

	}ROOMS;

	ROOMS rooms[10]; // Array of rooms

// FUNCTIONS HEADERS

	ROOMS CreateRoom(	ROOMS RoomName, int RoomNumber, char* status,
						char* firstName, char* lastName, FILE* fp);

	void NewFile(ROOMS room[]);

	bool MainMenu();


	int AccessFile();

	void NumberOfEmptyRooms();

	void ListOfEmptyRooms();

	void AlphaOrderGuests();

	void BookARoom();

	void DeleteABooking();





