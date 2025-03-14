// Rami Musleh - prog71990 w25 - Assignment 4 Q2
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include "functions.h"


void NewFile(ROOMS room[]) {
	
	fprintf(stdin, "creating new File\n");
	FILE* fp = fopen(FILENAME, "w");

	for (int i = 1; i <= MAXROOMS; i++) {
		room[i].roomNumber = i;
		room[i] = CreateRoom(room[i], i, "empty", "", "", fp);
		printf("2: Room %d Created and Added to BookingData.txt\n", i);

	}
	fclose(fp);
}


ROOMS CreateRoom(ROOMS RoomName, int RoomNumber, char* status, char* firstName, char* lastName, FILE* fp) {

	RoomName.roomNumber = RoomNumber;
	strcpy(RoomName.roomStatus, status, NAMELIMIT - 1);
	strcpy(RoomName.firstName, firstName, NAMELIMIT - 1);
	strcpy(RoomName.lastName, lastName, NAMELIMIT - 1);

	fprintf(fp, ROOM_FORMAT_OUT, RoomNumber, status, firstName, lastName);
	fprintf(stdin, "Room %d created in BookingData.txt\n", RoomNumber);


	return RoomName;

}

int AccessFile() {

	FILE* fp = fopen("BookingData.txt", "r");

	if (fp == NULL) {
		NewFile(rooms);
		fprintf(stdout, "New File Created\n");
	}
	else {
		fclose(fp);
	}
}



void NumberOfEmptyRooms() {
	printf("Number of Empty Rooms\n\n");

	FILE* fp = fopen("BookingData.txt", "r");

	if (fp == NULL) {
		fprintf(stderr, "Error Opening File");
		return 1;
	}
	
	
	char BookingData[MAXLIMIT];
	for (int i = 1; i <= 10 ; i++) {
		char booked;
		fgets(BookingData, sizeof(BookingData), fp);
			if (fscanf(fp, "%c", &booked) == 1 && booked == 0) {
				printf("Room %d is empty\n", i);
		}
		
	}

	fclose(fp);

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