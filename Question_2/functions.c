// Rami Musleh - prog71990 w25 - Assignment 4 Q2
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include "functions.h"

int AccessFile() {

	FILE* fp = fopen("BookingData.txt", "r");

	if (fp == NULL) {
		fprintf(stderr, "Error Opening File");
		return 1;
	}
}

AccessRoomStructs() {
	ROOMS room1;
	room1.roomNumber = 1;
	room1.roomStatus = true;
	strncpy(room1.firstName, "Rami", NAMELIMIT - 1);
	strncpy(room1.lastName, "Musleh", NAMELIMIT - 1);

	printf("Room %i: %s %s - ", room1.roomNumber, room1.firstName, room1.lastName);
	if (room1.roomStatus) {
		printf("Room is Booked\n");
	}
	else{
		printf("Room is vacant\n");
	}


	ROOMS room2;
	room2.roomNumber = 2;
	room2.roomStatus = false;
	strncpy(room2.firstName, "\0", NAMELIMIT - 1);
	strncpy(room2.lastName, "\0", NAMELIMIT - 1);

	printf("Room %i: %s %s - ", room2.roomNumber, room2.firstName, room2.lastName);
	if (room2.roomStatus) {
		printf("Room is Booked\n");
	}
	else {
		printf("Room is vacant\n");
	}


	ROOMS room3;
	room3.roomNumber = 3;
	room3.roomStatus = false;
	strncpy(room3.firstName, "\0", NAMELIMIT - 1);
	strncpy(room3.lastName, "\0", NAMELIMIT - 1);

	printf("Room %i: %s %s - ", room3.roomNumber, room3.firstName, room3.lastName);

	if (room3.roomStatus) {
		printf("Room is Booked\n");
	}
	else {
		printf("Room is vacant\n");
	}

	ROOMS room4;
	room4.roomNumber = 4;
	room4.roomStatus = false;
	strncpy(room4.firstName, "\0", NAMELIMIT - 1);
	strncpy(room4.lastName, "\0", NAMELIMIT - 1);

	printf("Room %i: %s %s - ", room4.roomNumber, room4.firstName, room4.lastName);
	if (room4.roomStatus) {
		printf("Room is Booked\n");
	}
	else {
		printf("Room is vacant\n");
	}

	ROOMS room5;
	room5.roomNumber = 5;
	room5.roomStatus = false;
	strncpy(room5.firstName, "\0", NAMELIMIT - 1);
	strncpy(room5.lastName, "\0", NAMELIMIT - 1);

	printf("Room %i: %s %s - ", room5.roomNumber, room5.firstName, room5.lastName);
	if (room5.roomStatus) {
		printf("Room is Booked\n");
	}
	else {
		printf("Room is vacant\n");
	}

	ROOMS room6;
	room6.roomNumber = 6;
	room6.roomStatus = false;
	strncpy(room6.firstName, "\0", NAMELIMIT - 1);
	strncpy(room6.lastName, "\0", NAMELIMIT - 1);

	printf("Room %i: %s %s - ", room6.roomNumber, room6.firstName, room6.lastName);
	if (room6.roomStatus) {
		printf("Room is Booked\n");
	}
	else {
		printf("Room is vacant\n");
	}

	ROOMS room7;
	room7.roomNumber = 7;
	room7.roomStatus = false;
	strncpy(room7.firstName, "\0", NAMELIMIT - 1);
	strncpy(room7.lastName, "\0", NAMELIMIT - 1);

	printf("Room %i: %s %s - ", room7.roomNumber, room7.firstName, room7.lastName);
	if (room7.roomStatus) {
		printf("Room is Booked\n");
	}
	else {
		printf("Room is vacant\n");
	}

	ROOMS room8;
	room8.roomNumber = 8;
	room8.roomStatus = false;
	strncpy(room8.firstName, "\0", NAMELIMIT - 1);
	strncpy(room8.lastName, "\0", NAMELIMIT - 1);

	printf("Room %i: %s %s - ", room8.roomNumber, room8.firstName, room8.lastName);
	if (room8.roomStatus) {
		printf("Room is Booked\n");
	}
	else {
		printf("Room is vacant\n");
	}

	ROOMS room9;
	room9.roomNumber = 9;
	room9.roomStatus = false;
	strncpy(room9.firstName, "\0", NAMELIMIT - 1);
	strncpy(room9.lastName, "\0", NAMELIMIT - 1);

	printf("Room %i: %s %s - ", room9.roomNumber, room9.firstName, room9.lastName);
	if (room9.roomStatus) {
		printf("Room is Booked\n");
	}
	else {
		printf("Room is vacant\n");
	}

	ROOMS room10;
	room10.roomNumber = 10;
	room10.roomStatus = false;
	strncpy(room10.firstName, "\0", NAMELIMIT - 1);
	strncpy(room10.lastName, "\0", NAMELIMIT - 1);

	printf("Room %i: %s %s - ", room10.roomNumber, room10.firstName, room10.lastName);
	if (room10.roomStatus) {
		printf("Room is Booked\n");
	}
	else {
		printf("Room is vacant\n");
	}

}

void NumberOfEmptyRooms() {
	printf("Number of Empty Rooms\n\n");

}

void ListOfEmptyRooms() {
	printf("List of Empty Rooms\n\n");

}

void AlphaOrderGuests() {
	printf("Guests in Alphabetical Order\n\n");

}


void BookARoom() {
	printf("Book a Room\n\n");

}

void DeleteABooking() {
	printf("Delete a Booking\n\n");

}

bool MainMenu() {
	printf("\n*** MAIN MENU ***\n\n");


	printf("A: See Number of empty rooms\n");
	printf("______________________________\n\n");
	printf("B: See List of empty rooms\n");
	printf("______________________________\n\n");
	printf("C: See Ordered List of Guests\n");
	printf("______________________________\n\n");
	printf("D: Book A Room\n");
	printf("______________________________\n\n");
	printf("E: Delete a Booking\n");
	printf("______________________________\n\n");
	printf("F: Exit\n");
	printf("______________________________\n\n");

	char userSelection;
	printf("Select an Option: ");
	int userSelectionSymbols = scanf(" %c", &userSelection);
	userSelection = toupper(userSelection);


	switch (userSelection) {

	case 'A':
		NumberOfEmptyRooms();
		break;

	case 'B':
		ListOfEmptyRooms();
		break;

	case 'C':
		AlphaOrderGuests();
		break;

	case 'D':
		BookARoom();
		break;

	case 'E':
		DeleteABooking();
		break;

	case 'F':
		return false;

	default:
		printf("Invalid Entry");
		return false;

	}
	return true;
}