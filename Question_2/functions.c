// Rami Musleh - prog71990 w25 - Assignment 4 Q2
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "functions.h"


void NewFile(ROOMS room[]) {
	
	fprintf(stdin, "creating new File\n");
	FILE* fp = fopen(FILENAME, "w");
	char* status = "empty";
	for (int i = 1; i <= MAXROOMS; i++) {
		room[i].roomNumber = i;
		room[i] = CreateRoom(room[i], i, status, "", "", fp);
		printf("Room %d Created and Added to BookingData.txt\n", i);

	}
	fclose(fp);
}

void ReadFile(ROOMS room[]) {

	FILE* fp = fopen(FILENAME, "r");

	if (fp == NULL) {
		fprintf(stderr, "Error Opening File");
		return 1;
	}

	char data[MAXROOMS][LINESIZE] = { 0 };
	int lineCounter = 0;

	while (!feof(fp)) {
		for (int i = 1; i <= MAXROOMS; i++) {
			if (fgets(data[lineCounter], LINESIZE, fp) != NULL) {
				lineCounter++;
			}
			//fprintf(fp, data[i]);
		}
	}
	
	fclose(fp);

	FILE* tfp = fopen("tempfile.txt", "w");
	if (tfp == NULL) {
		fprintf(stderr, "Error Opening File");
		return 1;
	}

	for (int i = 0; i < MAXROOMS; i++) {
		fprintf(tfp, data[i]);
	}

	
	fclose(tfp);

	rename("tempfile.txt", FILENAME);

	remove("tempfile.txt");
}

void AddRoom(ROOMS room[], int i,char* status, char* firstName, char* lastName) {

	FILE* fp = fopen(FILENAME, "r");

	if (fp == NULL) {
		fprintf(stderr, "Error Opening File");
		return 1;
	}

	char data[MAXROOMS][LINESIZE] = { 0 };
	int lineCounter = 0;

	while (!feof(fp)) {
		for (int i = 1; i <= MAXROOMS; i++) {
			if (fgets(data[lineCounter], LINESIZE, fp) != NULL) {
				lineCounter++;
			}
			
		}
	}

	fclose(fp);
	
	FILE* tfp = fopen("tempfile.txt", "w");
	if (tfp == NULL) {
		fprintf(stderr, "Error Opening File");
		return 1;
	}

	printf("initial i: %d\n", i);
	if (i != 1) {
		for (int j = 0; j < i-1; j++) {
			if (j != i) {
				fprintf(tfp, data[j]);
				printf("1\n");
				printf("J: %d - I: %d\n", j, i);
			}
		}
	}
	
		room[i].roomNumber = i;
		strcpy(room[i].roomStatus, status);
		strcpy(room[i].firstName, firstName);
		strcpy(room[i].lastName, lastName);
		room[i] = ReplaceRoom(room[i], i, status, firstName, lastName, tfp);
		printf(" %s", 
			data[i]);
		
		fprintf(tfp, ROOM_FORMAT_OUT, i, status, firstName, lastName);

		if (i != 10) {
			for (int j = i; j < MAXROOMS; j++) {
				fprintf(tfp, data[j]);
				printf("%d\n", i);
				printf("3\n");
				
			}
		}
		
	
		fclose(tfp);
		remove(FILENAME);
		rename("tempfile.txt", FILENAME);
	

	
}

ROOMS ReplaceRoom(ROOMS RoomName, int RoomNumber, char* status, char* firstName, char* lastName, FILE* fp) {

	RoomName.roomNumber = RoomNumber;
	strcpy(RoomName.roomStatus, status);
	strcpy(RoomName.firstName, firstName);
	strcpy(RoomName.lastName, lastName);


	return RoomName;
	

}

ROOMS CreateRoom(ROOMS RoomName, int RoomNumber, char* status, char* firstName, char* lastName, FILE* fp) {

	RoomName.roomNumber = RoomNumber;
	strcpy(RoomName.roomStatus, status);
	strcpy(RoomName.firstName, firstName);
	strcpy(RoomName.lastName, lastName);

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
		ReadFile(rooms);
		fclose(fp);
	}
}



void NumberOfEmptyRooms() {
	printf("Number of Empty Rooms\n\n");

	FILE* fp = fopen(FILENAME, "r");

	if (fp == NULL) {
		fprintf(stderr, "Error Opening File");
		return 1;
	}

	char fileText[BUFFER] = { 0 };
	char unbooked[NAMELIMIT] = "empty";
	char LINE[LINESIZE];

	int roomCounter = 0;
	int lineCounter = 1;
	
	while (fgets(fileText, LINESIZE, fp)) {
		
		

		if (strstr(fileText, unbooked)) {
			roomCounter++;
		}

		lineCounter++;
	}
	fprintf(stdout, "\nThere are %d Rooms Available for Booking\n\n", roomCounter);


		fclose(fp);

}

void ListOfEmptyRooms() {
	printf("List of Empty Rooms\n\n");

	FILE* fp = fopen(FILENAME, "r");
	char fileText[BUFFER] = { 0 };

	if (fp == NULL) {
		fprintf(stderr, "Error Opening File");
		return 1;
	}

	
	char unbooked[NAMELIMIT] = "empty";
	char LINE[LINESIZE];
	int roomCounter = 0;
	int lineCounter = 1;

	while (fgets(fileText, LINESIZE, fp)) {



		if (strstr(fileText, unbooked)) {
			printf("Room %d is empty\n", lineCounter);
			roomCounter++;
		}


		lineCounter++;
	}


	fclose(fp);

}

void AlphaOrderGuests() {
	printf("Guests in Alphabetical Order\n\n");

}


bool BookARoom() {
	char userInput[INPUTLIMIT] = "";

	printf("Book a Room\n\n");
	printf("Which Room would you Like to Book (Enter B to go back to main menu): ");
	scanf(" %s", &userInput);
	int lengthOfInput = strlen(userInput);


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

	// Check if Room is empty
		// if not empty, alert them that the room is not empty and to try again

	FILE* fp = fopen(FILENAME, "r");

	if (fp == NULL) {
		fprintf(stderr, "Error Accessing File");
		return 1;
	}

	char fileText[BUFFER] = { 0 };
	char unbooked[NAMELIMIT] = "empty";
	char LINE[LINESIZE];

	char* booked = "booked";

	int userInputAsInt = atoi(userInput);


	if (userInputAsInt < 1 || userInputAsInt > MAXROOMS) {
		printf("\nInvalid Entry, Please Try again.\n");
		return false;
	}

	for (int i = 0; i < userInputAsInt; i++) {
		(fgets(fileText, LINESIZE, fp));
	}

	if (strstr(fileText, booked)) {
		printf("This Room is Already Booked. Please Select Again.\n ");
		printf("Back to Main Menu\n");
		return true;
	}

	fclose(fp);
	char firstName[NAMELIMIT];
	char lastName[NAMELIMIT];

	printf("Enter The First Name: ");
	scanf("\n%s", firstName);

	int firstNameLength = strlen(firstName);

	for (int i = 0; i < firstNameLength; i++) {
		if (!isalpha(firstName[i])) {
			printf("\nInvalid Entry, Please Try again.\n");
			return false;
		}
	}

	printf("Enter The Last Name: ");
	scanf("\n%s", lastName);

	int lastNameLength = strlen(lastName);



	for (int i = 0; i < lastNameLength; i++) {
		if (!isalpha(lastName[i])) {
			printf("\nInvalid Entry, Please Try again.\n");
			return false;
		}
	}

	
	AddRoom(rooms, userInputAsInt, "booked", firstName, lastName);
	
	fclose(fp);
}


	bool DeleteABooking() {
		printf("Delete a Booking\n\n");

		// Ask Which booking to delete or if they want to go back

		// Validate Input

		// IF back, then return

		// If they select a booking

			// Check if Room is booked
				// if not booked, alert them that there is no booking and to try again

			// If booked
				// set the first and last name to '\0' and set room to empty
		return true;
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

	bool ProgramStatus = true;

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
		ProgramStatus = BookARoom();
		return ProgramStatus;

	case 'E':
		ProgramStatus = DeleteABooking();
		return ProgramStatus;

	case 'F':
		return false;

	default:
		printf("Invalid Entry");
		return false;

	}
	return true;
}