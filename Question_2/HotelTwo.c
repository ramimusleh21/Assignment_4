// Rami Musleh - prog71990 w25 - Assignment 4 Q2 Refactor

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "HotelTwo.h"
#include "globals.h"



bool NumberOfEmptyRoomsTwo() {

	printf("Number of Empty Rooms\n\n");

	FILE* fp = fopen(FILENAME, "r");

	if (fp == NULL) {
		fprintf(stderr, "Error Opening File");
		return false;
	}

	char fileText[BUFFER] = { 0 }; // Set equal to {0} to remove warning

	for (int i = 0; i < MAXROOMS; i++) { // Skip 10 lines
		if (fgets(fileText, LINESIZE, fp) == NULL) { // Make sure line is not empty
			fprintf(stderr, "File has fewer than 10 lines\n");
			fclose(fp);
			return false;
		}
	}

	int roomCounter = 0;
	int lineCounter = 1;
	int KingCounter = 0;
	int QueenCounter = 0;

	for (int i = 0; i < MAXROOMS; i++) {
		fgets(fileText, LINESIZE, fp);
		if (strstr(fileText, unbooked)) {
			roomCounter++;
			if (strstr(fileText, "King")) {
				KingCounter++;
			}
			else if (strstr(fileText, "Queen+2")) {
				QueenCounter++;
			}
		}

		lineCounter++;
	}

	fprintf(stdout, "\nThere are %d Rooms Available for Booking\n%d King Rooms\n%d Family Rooms\n\n",
		roomCounter, KingCounter, QueenCounter);

	fclose(fp);

	return true;

}

bool ListOfEmptyRoomsTwo() {

	printf("List of Empty Rooms\n\n");

	FILE* fp = fopen(FILENAME, "r");
	char fileText[BUFFER] = { 0 }; // Set equal to {0} to remove warning

	if (fp == NULL) {
		fprintf(stderr, "Error Opening File");
		return false;
	}


	int roomCounter = 0;
	int lineCounter = 1;

	for (int i = 0; i < MAXROOMS; i++) { // Skip 10 lines
		if (fgets(fileText, LINESIZE, fp) == NULL) { // Make sure line is not empty
			fprintf(stderr, "File has fewer than 10 lines\n");
			fclose(fp);
			return false;
		}
	}

	for (int i = 0; i < MAXROOMS; i++) {

		fgets(fileText, LINESIZE, fp);

		if (strstr(fileText, unbooked)) {
			if (strstr(fileText, "King")) {
				printf("Room %d is an empty King Room\n", lineCounter);
				roomCounter++;
			}

			else if (strstr(fileText, "Queen+2")) {
				printf("Room %d is an empty Family Room\n", lineCounter);
				roomCounter++;
			}
		}

		lineCounter++;
	}

	if (roomCounter == 0) {
		printf("There are 0 available Rooms\n");
	}

	fclose(fp);
	return true;
}

bool AlphaOrderGuestsTwo(ROOMS* rooms) {
	bool userSelection = true;

	printf("Guests in Alphabetical Order\n\n");

	printf("F: Order by first name\n");
	printf("L: Order by Last name\n");
	printf("B: Back to main menu\n");

	char userInput;
	printf("\nSelect an Option: ");

	int userInputSymbols = scanf(" %c", &userInput);
	userInput = toupper(userInput);

	switch (userInput) {
	case 'F':
		userSelection = OrderByFirstNameTwo(rooms);
		return userSelection;
	case 'L':
		userSelection = OrderByLastNameTwo(rooms);
		return userSelection;
	case 'B':
		printf("Back to Main Menu\n");
		return true;
	default:
		printf("Invalid Selection\n");
		return true;
	}
}


bool OrderByFirstNameTwo(ROOMS* rooms) {
	printf("\nOrdered by First Name\n\n");

	char nameArray[MAXROOMS][NAMELIMIT] = { 0 };
	char placeHolder[NAMELIMIT] = { 0 };
	int counter = 0;
	for (int i = MAXROOMS; i < TOTALROOMS; i++) {
		if (strcmp(rooms[i].roomStatus, unbooked)) {
			strcpy(placeHolder, rooms[i].firstName);
			char* temp = strcat(placeHolder, " ");
			char* fullName = strcat(temp, rooms[i].lastName);
			strcpy(nameArray[counter], fullName);
			strcat(nameArray[counter], " booked a ");

			if (!strcmp(rooms[i].type, "King")) {
				strcat(nameArray[counter], rooms[i].type);
			}
			else if (!strcmp(rooms[i].type, "Queen+2")) {
				strcat(nameArray[counter], "Family");
			}
			counter++;
		}
	}

	int numberOfGuests = sizeof(nameArray) / sizeof(nameArray[0]);
	char temp[NAMELIMIT] = { 0 };

	for (int i = 0; i < numberOfGuests - 1; i++) {
		int LowestElement = i;

		for (int j = i + 1; j < numberOfGuests; j++) {
			{
				if (strcmp(nameArray[j], nameArray[LowestElement]) < 0) {
					LowestElement = j;
				}
			}
		}

		if (LowestElement != i) {

			strcpy(temp, nameArray[i]);
			strcpy(nameArray[i], nameArray[LowestElement]);
			strcpy(nameArray[LowestElement], temp);
		}
	}

	for (int i = MAXROOMS - counter; i < numberOfGuests; i++) {
		printf("%s Room\n", nameArray[i]);
	}
	return true;
}



bool OrderByLastNameTwo(ROOMS* rooms) {
	printf("\nOrdered by Last Name\n\n");

	char nameArray[MAXROOMS][NAMELIMIT] = { 0 };

	char placeHolder[NAMELIMIT] = { 0 };
	int counter = 0;
	for (int i = MAXROOMS; i < TOTALROOMS; i++) {
		if (strcmp(rooms[i].roomStatus, unbooked)) {
			strcpy(placeHolder, rooms[i].lastName);
			char* temp = strcat(placeHolder, ", ");
			char* fullName = strcat(temp, rooms[i].firstName);
			strcpy(nameArray[counter], fullName);
			strcat(nameArray[counter], " booked a ");

			if (!strcmp(rooms[i].type, "King")) {
				strcat(nameArray[counter], rooms[i].type);
			}
			else if (!strcmp(rooms[i].type, "Queen+2")) {
				strcat(nameArray[counter], "Family");
			}
			counter++;
		}
	}

	int numberOfGuests = sizeof(nameArray) / sizeof(nameArray[0]);
	char temp[NAMELIMIT] = { 0 };

	for (int i = 0; i < numberOfGuests - 1; i++) {
		int LowestElement = i;

		for (int j = i + 1; j < numberOfGuests; j++) {
			{
				if (strcmp(nameArray[j], nameArray[LowestElement]) < 0) {
					LowestElement = j;
				}
			}
		}

		if (LowestElement != i) {

			strcpy(temp, nameArray[i]);
			strcpy(nameArray[i], nameArray[LowestElement]);
			strcpy(nameArray[LowestElement], temp);
		}
	}

	for (int i = MAXROOMS - counter; i < numberOfGuests; i++) {
		printf("%s Room\n", nameArray[i]);
	}
	return true;
}


bool BookARoomTwo(ROOMS* rooms) {

	printf("Book a Room\n\n");

	printf("A: King Room (1-5)\n");
	printf("B: Family Room (6-10)\n");
	printf("Select a Room Type: ");

	char roomInput;
	(void)scanf(" %c", &roomInput);
	roomInput = toupper(roomInput);

	switch (roomInput)
	{
	case 'A':
	{
		int roomCounter = 0;
		for (int i = MAXROOMS; i < TOTALROOMS; i++) {
			if (!strcmp(rooms[i].type, "King") && !strcmp(rooms[i].roomStatus, unbooked)) {
				roomCounter++;
			}
		}
		printf("\n%d Available King Room(s).\n", roomCounter);
		if (roomCounter == 0) {
			return true;
		}
		else if (roomCounter > 0) {
			break;
		}
	}

	case 'B':
	{
		int roomCounter = 0;
		for (int i = MAXROOMS; i < TOTALROOMS; i++) {
			if (!strcmp(rooms[i].type, "Queen+2") && !strcmp(rooms[i].roomStatus, unbooked)) {
				roomCounter++;
			}
		}
		printf("\n%d Available Family Room(s).\n", roomCounter);
		if (roomCounter == 0) {
			return true;
		}
		else if (roomCounter > 0) {
			break;
		}

	}

	default:
		printf("Invalid Entry");
		return false;
	}



	char userInput[INPUTLIMIT] = "";
	printf("Which Room would you Like to Book (Enter B to go back to main menu): ");
	(void)scanf(" %s", &userInput);
	size_t lengthOfInput = strlen(userInput);	// set to size_t instead 
	// of int to remove warning


	for (int i = 0; i < lengthOfInput; i++) {
		if (isdigit(userInput[i]) != 0) {

		}

		else if (userInput[i] != 'b' && userInput[i] != 'B') {

			printf("\nInvalid Entry, Please Try again.\n");
			return false;
		}

		else if (userInput[i] == 'b' || userInput[i] == 'B') {
			if (lengthOfInput > 1) {
				printf("\nInvalid Entry, Please Try again.\n");
				return false;
			}
			printf("Back to Main Menu\n");
			return true;
		}
		else {
			if (isdigit(userInput[i]) == 0) {
				printf("\nInvalid Entry, Please Try again.\n");
				return false;
			}
		}
	}


	FILE* fp = fopen(FILENAME, "r");

	if (fp == NULL) {
		fprintf(stderr, "Error Accessing File\n");
		return false;
	}

	char fileText[BUFFER] = { 0 };

	char* booked = "booked";

	int userInputAsInt = atoi(userInput);
	
	if (roomInput == 'A') {
		if (userInputAsInt < 1 || userInputAsInt > 5) {
			printf("\nKing Rooms are Only rooms 1-5.\n Please try again\n");
			return true;
		}
	}

	else if (roomInput == 'B') {
		if (userInputAsInt < 6 || userInputAsInt > 10) {
			printf("\nFamily Rooms are Only rooms 6-10.\nPlease try again\n");
			return true;
		}
	}

	if (userInputAsInt < 1 || userInputAsInt > MAXROOMS) {
		printf("\nInvalid Entry, Please Try again.\n");
		return false;
	}

	
	userInputAsInt = userInputAsInt + 10;
	

	
	for (int i = 0; i < userInputAsInt; i++) {
		(fgets(fileText, LINESIZE, fp));
	}

	if (strstr(fileText, booked)) {
		printf("This Room is Already Booked. Please Select Again.\n\n ");
		printf("Back to Main Menu\n");
		return true;
	}

	fclose(fp);
	char firstName[NAMELIMIT] = { 0 };;
	firstName[NAMELIMIT - 1] = '\0';

	char lastName[NAMELIMIT] = { 0 };;
	lastName[NAMELIMIT - 1] = '\0';

	printf("Enter The First Name: ");
	(void)scanf("\n%s", firstName);

	size_t firstNameLength = strlen(firstName);


	for (int i = 0; i < firstNameLength; i++) {
		if (!isalpha(firstName[i])) {
			printf("\nInvalid Entry, Please Try again.\n");
			return false;
		}
	}

	printf("Enter The Last Name: ");
	(void)scanf("\n%s", lastName);

	size_t lastNameLength = strlen(lastName);



	for (int i = 0; i < lastNameLength; i++) {
		if (!isalpha(lastName[i])) {
			printf("\nInvalid Entry, Please Try again.\n");
			return false;
		}
	}

	bool userSelection = true;
	userSelection = AddRoomTwo(rooms, userInputAsInt, "booked", firstName, lastName);

	fclose(fp);
	return userSelection;

}

bool AddRoomTwo(ROOMS* room, int input, char* status, char* firstName, char* lastName) {

	FILE* fp = fopen(FILENAME, "r");

	if (fp == NULL) {
		fprintf(stderr, "Error Opening File");
		return false;
	}

	char data[TOTALROOMS][LINESIZE] = { 0 };
	int lineCounter = 0;

	while (!feof(fp)) {
		for (int j = 1; j <= TOTALROOMS; j++) {
			if (fgets(data[lineCounter], LINESIZE, fp) != NULL) {
				lineCounter++;
			}
		}
	}

	fclose(fp);

	FILE* tfp = fopen("tempfile.txt", "w");
	if (tfp == NULL) {
		fprintf(stderr, "Error Opening File");
		return false;
	}
	
	for (int i = 0; i < MAXROOMS; i++) {
		fprintf(tfp, data[i]);
	}

	if (input != 11) {
		for (int j = MAXROOMS; j < input - 1; j++) {
			if (j != input) {
				fprintf(tfp, data[j]);
			}
		}
	}

	
	ReplaceRoomV2(room[input-1], input - MAXROOMS, status, firstName, lastName);

	
	fprintf(tfp, ROOM_FORMAT_OUT, input - MAXROOMS, status, firstName,
		lastName, room[input-1].hotel, room[input-1].type);
	
	

	if (input != 20) {
		for (int j = input; j < TOTALROOMS; j++) {
			fprintf(tfp, data[j]);

		}

	}
	else {
		for (int j = input; j < TOTALROOMS; j++) {
			fprintf(tfp, data[j]);

		}
	}


	fclose(tfp);
	remove(FILENAME);
	(void)rename("tempfile.txt", FILENAME);

	printf("\nBooking created\n");

	ReadFile(room);
	return true;
}



bool DeleteABookingTwo(ROOMS* rooms) {
	printf("Delete a Booking\n\n");

	char userInput[INPUTLIMIT] = { 0 };

	printf("Which Booking would you Like to delete (Enter B to go back to main menu): ");
	(void)scanf(" %s", &userInput);
	size_t lengthOfInput = strlen(userInput);


	for (int i = 0; i < lengthOfInput; i++) {
		if (isdigit(userInput[i]) != 0) {
			
		}

		else if (userInput[i] != 'b' && userInput[i] != 'B') {

			printf("\nInvalid Entry, Please Try again.\n");
			return false;
		}

		else if (userInput[i] == 'b' || userInput[i] == 'B') {
			if (lengthOfInput > 1) {
				printf("\nInvalid Entry, Please Try again.\n");
				return false;
			}
			printf("Back to Main Menu\n");
			return true;
		}
		else {
			if (isdigit(userInput[i]) == 0) {
				printf("\nInvalid Entry, Please Try again.\n");
				return false;
			}
		}
	}

	FILE* fp = fopen(FILENAME, "r");

	if (fp == NULL) {
		fprintf(stderr, "Error Accessing File");
		return false;
	}

	char fileText[BUFFER] = { 0 };

	int userInputAsInt = atoi(userInput);


	if (userInputAsInt < 1 || userInputAsInt > MAXROOMS) {
		printf("\nInvalid Entry, Please Try again.\n");
		return false;
	}

	userInputAsInt = userInputAsInt + MAXROOMS;

	for (int i = 0; i < userInputAsInt; i++) {
		(fgets(fileText, LINESIZE, fp));
	}

	if (strstr(fileText, unbooked)) {
		printf("There is no booking in Room %d. Please Select Again.\n", userInputAsInt - MAXROOMS);
		printf("Back to Main Menu\n");
		return true;
	}

	fclose(fp);

	bool userSelection = true;
	userSelection = DeleteRoomTwo(rooms, userInputAsInt, "empty", ROOM_IS_EMPTY, ROOM_IS_EMPTY,
		rooms[userInputAsInt].type, rooms[userInputAsInt].hotel);

	fclose(fp);
	return userSelection;
}


bool DeleteRoomTwo(ROOMS* room, int input, char* status, char* firstName, char* lastName,
	char* type, HOTEL hotel) {

	FILE* fp = fopen(FILENAME, "r");

	if (fp == NULL) {
		fprintf(stderr, "Error Opening File");
		return false;
	}

	char data[TOTALROOMS][LINESIZE] = { 0 };
	int lineCounter = 0;

	while (!feof(fp)) {
		for (int j = 1; j <= TOTALROOMS; j++) {
			if (fgets(data[lineCounter], LINESIZE, fp) != NULL) {
				lineCounter++;
			}
		}
	}

	fclose(fp);

	FILE* tfp = fopen("tempfile.txt", "w");
	if (tfp == NULL) {
		fprintf(stderr, "Error Opening File");
		return false;
	}
	for (int i = 0; i < MAXROOMS; i++) {
		fprintf(tfp, data[i]);
	}

	if (input != 11) {
		for (int j = MAXROOMS; j < input - 1; j++) {
			if (j != input) {
				fprintf(tfp, data[j]);
			}
		}
	}

	ReplaceRoomV2(room[input - 1], input - MAXROOMS, "empty", ROOM_IS_EMPTY, ROOM_IS_EMPTY);
	

	fprintf(tfp, ROOM_FORMAT_OUT, input - MAXROOMS, status, firstName,
		lastName, room[input - 1].hotel, room[input - 1].type);

	if (input != 20) {
		for (int j = input; j < TOTALROOMS; j++) {
			fprintf(tfp, data[j]);

		}

	}
	else {
		for (int j = input; j < TOTALROOMS; j++) {
			fprintf(tfp, data[j]);

		}
	}

	fclose(tfp);
	remove(FILENAME);
	(void)rename("tempfile.txt", FILENAME);

	printf("\nBooking Deleted\n");

	ReadFile(room);
	return true;

}



bool MainMenuTwo(ROOMS* rooms) {

	char userSelection;

	bool ProgramStatus = true;
	while (ProgramStatus) {

		if (ProgramStatus == false) {
			return false;
		}

		printf("\n*** HOTEL TWO ***\n\n");

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
		printf("F: Back\n");
		printf("______________________________\n\n");

		printf("Select an Option: ");
		(void)scanf(" %c", &userSelection);
		userSelection = toupper(userSelection);

		{

			switch (userSelection) {

			case 'A':
				ProgramStatus = NumberOfEmptyRoomsTwo();
				break;

			case 'B':
				ProgramStatus = ListOfEmptyRoomsTwo();
				break;

			case 'C':
				ProgramStatus = AlphaOrderGuestsTwo(rooms);
				break;

			case 'D':
				ProgramStatus = BookARoomTwo(rooms);
				break;

			case 'E':
				ProgramStatus = DeleteABookingTwo(rooms);
				break;

			case 'F':
				return true;

			default:
				printf("Invalid Entry");
				return false;
			}
		}
	}
	return ProgramStatus;
}
