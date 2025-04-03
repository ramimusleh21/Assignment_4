// Rami Musleh - prog71990 w25 - Assignment 4 Q2 Refactor

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "HotelOne.h"
#include "HotelTwo.h"
#include "globals.h"


// FILE FUNCTIONS
bool AccessFile(ROOMS* rooms) {

	FILE* fp = fopen(FILENAME, "r");

	bool userSelection = true;
	if (fp == NULL) {
		NewFile(rooms);
		fprintf(stdout, "New File Created: %s", FILENAME);
	}
	else {
		fclose(fp);
		userSelection = ReadFile(rooms);
		fprintf(stdout, "Accessed file: %s\n", FILENAME);
	}

	return userSelection;
}

bool ReadFile(ROOMS* rooms) {

	FILE* fp = fopen(FILENAME, "r");

	if (fp == NULL) {
		fprintf(stderr, "Error Opening File");
		return false;
	}

	char data[TOTALROOMS][LINESIZE] = { 0 };
	int lineCounter = 0;
	int read = 0;
	while (fgets(data[lineCounter], LINESIZE, fp) != NULL && lineCounter < TOTALROOMS) {
		read = sscanf(data[lineCounter], "%d,%49[^,],%49[^,],%49[^,],%d,%49[^\n]",
			&rooms[lineCounter].roomNumber,
			rooms[lineCounter].roomStatus,
			rooms[lineCounter].firstName,
			rooms[lineCounter].lastName,
			&rooms[lineCounter].hotel,
			rooms[lineCounter].type);

		if (read == 6) {
			lineCounter++;
		}
		else {
			printf("File format incorrect\n");
			return false;
		}
	}

	fclose(fp);

	FILE* tfp = fopen("tempfile.txt", "w");
	if (tfp == NULL) {
		fprintf(stderr, "Error Opening File");
		return false;
	}

	for (int i = 0; i < TOTALROOMS; i++) {
		fprintf(tfp, data[i]);
	}

	fclose(tfp);

	(void)rename("tempfile.txt", FILENAME);

	remove("tempfile.txt");

	return true;
}

bool NewFile(ROOMS* room) {

	FILE* fp = fopen(FILENAME, "w");
	if (fp == NULL) {
		fprintf(stderr, "Error Opening File");
		return false;
	}
	int roomCount = 0;
	for (int i = 1; i <= 5; i++) {
		room[roomCount].roomNumber = i;
		room[roomCount] = CreateRoom(room[i], i, "empty", ROOM_IS_EMPTY, ROOM_IS_EMPTY,
										HotelOne, "King", fp);
		roomCount++;
	}

	for (int i = 6; i <= MAXROOMS; i++) {
		room[roomCount].roomNumber = i;
		room[roomCount] = CreateRoom(room[i], i, "empty", ROOM_IS_EMPTY, ROOM_IS_EMPTY,
										HotelOne, "Queen+2", fp);
		roomCount++;
	}

	for (int i = 1; i <= 5; i++) {
		room[roomCount].roomNumber = i;
		room[roomCount] = CreateRoom(room[i], i, "empty", ROOM_IS_EMPTY, ROOM_IS_EMPTY, HotelTwo, "King", fp);
		roomCount++;
	}

	for (int i = 6; i <= MAXROOMS; i++) {
		room[roomCount].roomNumber = i;
		room[roomCount] = CreateRoom(room[i], i, "empty", ROOM_IS_EMPTY, ROOM_IS_EMPTY, HotelTwo, "Queen+2", fp);
		roomCount++;
	}

	fclose(fp);
	return true;
}

void ReplaceRoomV2(ROOMS room, int RoomNumber, char* status, char* firstName,
	char* lastName) {

	room.roomNumber = RoomNumber;
	strcpy(room.roomStatus, status);
	strcpy(room.firstName, firstName);
	strcpy(room.lastName, lastName);

}

ROOMS CreateRoom(ROOMS RoomName, int RoomNumber, char* status, char* firstName, char* lastName,
				HOTEL hotel, char* type, FILE* fp) {

	RoomName.roomNumber = RoomNumber;
	strcpy(RoomName.roomStatus, status);
	strcpy(RoomName.firstName, firstName);
	strcpy(RoomName.lastName, lastName);
	RoomName.hotel = hotel;
	strcpy(RoomName.type, type);

	fprintf(fp, ROOM_FORMAT_OUT, RoomNumber, status, firstName, lastName, hotel, type);
	fprintf(stdin, "Room %d created in BookingData.txt\n", RoomNumber);


	return RoomName;
}


//****** PRINT FUNCTIONS ******
bool PrintAllRooms(ROOMS* rooms) {
	printf("List of booked Rooms\n\n");
	
	int counter = 0;
	printf("Hotel 1 (Original):\n\n");
	for (int i = 0; i < MAXROOMS; i++) {
		if (strcmp(rooms[i].firstName, ROOM_IS_EMPTY)) {
			PrintRoom(rooms, i);
			counter++;
		}
	}
	if (counter == 0) {
		printf("There are no Bookings at Hotel 1\n");
	}

	counter = 0;
	printf("\nHotel 2 (New):\n\n");
	for (int i = MAXROOMS; i < TOTALROOMS; i++) {
		if (strcmp(rooms[i].firstName, ROOM_IS_EMPTY)) {
			PrintRoom(rooms, i);
		}
	}
	if (counter == 0) {
		printf("There are no Bookings at Hotel 2\n");
	}
	return true;
}


void PrintRoom(ROOMS* rooms, int i) {
	if (!strcmp(rooms[i].type, "Queen+2")) {
		printf(ROOM_FORMAT_PRINT, rooms[i].roomNumber, "Family", rooms[i].firstName,
			rooms[i].lastName);
	}
	else {
		printf(ROOM_FORMAT_PRINT, rooms[i].roomNumber, rooms[i].type, rooms[i].firstName,
			rooms[i].lastName);
	}
}


//***** MENU FUNCTION ******
bool TopMenu(ROOMS* rooms) {
	printf("\n*** MAIN MENU ***\n\n");

	printf("A: Hotel One (Original)\n");
	printf("______________________________\n\n");
	printf("B: Hotel Two (New)\n");
	printf("______________________________\n\n");
	printf("C: See All Current Bookings\n");
	printf("______________________________\n\n");
	printf("F: Exit\n");
	printf("______________________________\n\n");

	char userSelection;
	printf("Select an Option: ");
	(void)scanf(" %c", &userSelection);
	userSelection = toupper(userSelection);

	bool ProgramStatus = true;

	switch (userSelection) {

	case 'A':
		ProgramStatus = MainMenuOne(rooms);
		return ProgramStatus;

	case 'B':
		ProgramStatus = MainMenuTwo(rooms);
		return ProgramStatus;

	case 'C':
		PrintAllRooms(rooms);
		return ProgramStatus;

	case 'F':
		ProgramStatus = false;
		return ProgramStatus;

	default:
		printf("Invalid Entry");
		ProgramStatus = false;
		return ProgramStatus;

	}

	return ProgramStatus;
}