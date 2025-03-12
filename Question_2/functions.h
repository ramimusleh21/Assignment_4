// Rami Musleh - prog71990 w25 - Assignment 4 Q2

#pragma once

// DEFS
	#define NAMELIMIT 50
	#define MAXROOMS 10
	#define USERSELECTIONLIMIT 2

// STRUCTS
	typedef struct Rooms {

		int roomNumber;				// room identification number
		bool roomStatus;			// a marker that indicates whether the room is booked
		char lastName[NAMELIMIT];	// the last name of the booking guest
		char firstName[NAMELIMIT];	// the first name of the booking guest.

	}ROOMS;


// FUNCTIONS HEADERS
	bool MainMenu();

	AccessRoomStructs();

	int AccessFile();

	void NumberOfEmptyRooms();

	void ListOfEmptyRooms();

	void AlphaOrderGuests();

	void BookARoom();

	void DeleteABooking();





