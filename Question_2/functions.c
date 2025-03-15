// Rami Musleh - prog71990 w25 - Assignment 4 Q2
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


// FILE FUNCTIONS
bool AccessFile() {

	FILE* fp = fopen(FILENAME, "r");

	bool userSelection = true;
	if (fp == NULL) {
		NewFile(rooms);
		fprintf(stdout, "New File Created: %s", FILENAME);
	}
	else {
		userSelection = ReadFile(rooms);
		fprintf(stdout, "Accessed file: %s\n", FILENAME);
		fclose(fp);
	}

	return userSelection;
}

bool ReadFile(ROOMS room[]) {

	FILE* fp = fopen(FILENAME, "r");

	if (fp == NULL) {
		fprintf(stderr, "Error Opening File");
		return false;
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
		return false;
	}

	for (int i = 0; i < MAXROOMS; i++) {
		fprintf(tfp, data[i]);
	}


	fclose(tfp);

	rename("tempfile.txt", FILENAME);

	remove("tempfile.txt");
	return true;
}

bool NewFile(ROOMS room[]) {

	FILE* fp = fopen(FILENAME, "w");
	if (fp == NULL) {
		fprintf(stderr, "Error Opening File");
		return false;
	}


	for (int i = 1; i <= MAXROOMS; i++) {
		room[i].roomNumber = i;
		room[i] = CreateRoom(room[i], i, "empty", "", "", fp);

	}
	fclose(fp);
	return true;
}





// ROOM STRUCT FUNCTIONS
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


// ROOM FUNCTIONS
bool AddRoom(ROOMS room[], int i,char* status, char* firstName, char* lastName) {

	FILE* fp = fopen(FILENAME, "r");

	if (fp == NULL) {
		fprintf(stderr, "Error Opening File");
		return false;
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
		return false;
	}
	if (i != 1) {
		for (int j = 0; j < i-1; j++) {
			if (j != i) {
				fprintf(tfp, data[j]);
			}
		}
	}
	
		room[i].roomNumber = i;
		strcpy(room[i].roomStatus, status);
		strcpy(room[i].firstName, firstName);
		strcpy(room[i].lastName, lastName);
		room[i] = ReplaceRoom(room[i], i, status, firstName, lastName, tfp);
		
		fprintf(tfp, ROOM_FORMAT_OUT, i, status, firstName, lastName);

		if (i != 10) {
			for (int j = i; j < MAXROOMS; j++) {
				fprintf(tfp, data[j]);
				
			}
		}
		
	
		fclose(tfp);
		remove(FILENAME);
		rename("tempfile.txt", FILENAME);

		printf("\nBooking created\n");
		
		return true;
}


bool DeleteRoom(ROOMS room[], int i, char* status, char* firstName, char* lastName) {

	FILE* fp = fopen(FILENAME, "r");

	if (fp == NULL) {
		fprintf(stderr, "Error Opening File");
		return false;
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
		return false;
	}

	if (i != 1) {
		for (int j = 0; j < i - 1; j++) {
			if (j != i) {
				fprintf(tfp, data[j]);
			}
		}
	}

	room[i].roomNumber = i;
	strcpy(room[i].roomStatus, status);
	strcpy(room[i].firstName, firstName);
	strcpy(room[i].lastName, lastName);
	room[i] = ReplaceRoom(room[i], i, status, firstName, lastName, tfp);

	fprintf(tfp, ROOM_FORMAT_OUT, i, status, firstName, lastName);

	if (i != 10) {
		for (int j = i; j < MAXROOMS; j++) {
			fprintf(tfp, data[j]);
		}
	}

	fclose(tfp);
	remove(FILENAME);
	rename("tempfile.txt", FILENAME);

	printf("Booking Deleted\n");
	return true;
}


bool NumberOfEmptyRooms() {
	printf("Number of Empty Rooms\n\n");

	FILE* fp = fopen(FILENAME, "r");

	if (fp == NULL) {
		fprintf(stderr, "Error Opening File");
		return false;
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

	return true;
}

bool ListOfEmptyRooms() {
	printf("List of Empty Rooms\n\n");

	FILE* fp = fopen(FILENAME, "r");
	char fileText[BUFFER] = { 0 };

	if (fp == NULL) {
		fprintf(stderr, "Error Opening File");
		return false;
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
	
	if (roomCounter == 0) {
		printf("There are 0 available Rooms\n");
	}

	fclose(fp);
	return true;
}

bool AlphaOrderGuests() {
	bool userSelection = true;
	
	printf("Guests in Alphabetical Order\n\n");

	printf("F: Order by first name\n");
	printf("L: Order by Last name\n");
	printf("B: Back to main menu\n");

	char userInput;
	printf("\nSelect an Option: ");
	
	int userInputSymbols = scanf(" %c", &userInput);
	userInput = toupper(userInput);

	switch (userInput){
	case 'F':
		userSelection = OrderByFirstName();
		return userSelection;
	case 'L':
		userSelection = OrderByLastName();
		return userSelection;
	case 'B':
		printf("Back to Main Menu\n");
		return true;
	default:
		printf("Invalid Selection\n");
		return true;
	}

}



bool OrderByFirstName() {
	printf("\nOrdered by First Name\n\n");

	char nameArray[MAXROOMS][NAMELIMIT] = { 0 };

	FILE* fp = fopen(FILENAME, "r");  // Open file for reading
	if (fp == NULL) {
		printf("Error: Could not open file.\n");
		return false;
	}

	char line[LINESIZE];
	int lineCounter = 0;
	
	while (fgets(line, sizeof(line), fp)) {
	
		char* name[ARRAYLIMIT]; 
		int wordCounter = 0;

		char* token = strtok(line, " \n");  
		while (token != NULL && wordCounter < ARRAYLIMIT) {
			name[wordCounter++] = token;
			token = strtok(NULL, " \n");
		}

		if (wordCounter >= ARRAYLIMIT) {
			char* fullName = strcat(name[2], name[3]);
			strcpy(nameArray[lineCounter], fullName);
		}
		lineCounter++;
	}

	int numberOfGuests = sizeof(nameArray) / sizeof(nameArray[0]);
	char temp[NAMELIMIT];
	
	
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
	
		for (int i = 0; i < numberOfGuests; i++) {
			printf("%s\n", nameArray[i]);
			strcpy(nameArray[i], "\0");
			
		}
	
	
		
	
	fclose(fp);
	return true;
}


bool OrderByLastName() {
	printf("\nOrdered by Last Name\n\n");

	char nameArray[MAXROOMS][NAMELIMIT] = { 0 };

	FILE* fp = fopen(FILENAME, "r");  // Open file for reading
	if (fp == NULL) {
		printf("Error: Could not open file.\n");
		return false;
	}

	char line[LINESIZE];
	int lineCounter = 0;
	char spacer[NAMELIMIT] = ", " ;

	while (fgets(line, sizeof(line), fp)) {

		char* name[ARRAYLIMIT];
		int wordCounter = 0;

		char* token = strtok(line, " \n");
		while (token != NULL && wordCounter < ARRAYLIMIT) {
			name[wordCounter++] = token;
			token = strtok(NULL, " ,\n");
		}

		if (wordCounter >= ARRAYLIMIT) {
			strcat(name[3], spacer);
			char* fullName = strcat(name[3], name[2]);
			strcpy(nameArray[lineCounter], fullName);
		}
		lineCounter++;
	}

	int numberOfGuests = sizeof(nameArray) / sizeof(nameArray[0]);
	char temp[NAMELIMIT];


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

	for (int i = 0; i < numberOfGuests; i++) {
		printf("%s\n", nameArray[i]);
		strcpy(nameArray[i], "\0");

	}

	fclose(fp);
	return true;
}


bool BookARoom() {
	printf("Book a Room\n\n");
	
	char userInput[INPUTLIMIT] = "";
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

	FILE* fp = fopen(FILENAME, "r");

	if (fp == NULL) {
		fprintf(stderr, "Error Accessing File\n");
		return false;
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
		printf("This Room is Already Booked. Please Select Again.\n\n ");
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

	bool userSelection = true;
	userSelection = AddRoom(rooms, userInputAsInt, "booked", firstName, lastName);
	
	fclose(fp);
	return userSelection;
}


bool DeleteABooking() {
	printf("Delete a Booking\n\n");

	char userInput[INPUTLIMIT] = "";

		printf("Which Bookin would you Like to delete (Enter B to go back to main menu): ");
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

		FILE* fp = fopen(FILENAME, "r");

		if (fp == NULL) {
			fprintf(stderr, "Error Accessing File");
			return false;
		}

		char fileText[BUFFER] = { 0 };
		char LINE[LINESIZE];

		char* unbooked = "empty";
		int userInputAsInt = atoi(userInput);


		if (userInputAsInt < 1 || userInputAsInt > MAXROOMS) {
			printf("\nInvalid Entry, Please Try again.\n");
			return false;
		}

		for (int i = 0; i < userInputAsInt; i++) {
			(fgets(fileText, LINESIZE, fp));
		}

		if (strstr(fileText, unbooked)) {
			printf("There is no booking in Room %d. Please Select Again.\n", userInputAsInt);
			printf("Back to Main Menu\n");
			return true;
		}

		fclose(fp);

		bool userSelection = true; 
		userSelection = DeleteRoom(rooms, userInputAsInt, "empty", "", "");

		fclose(fp);
		return userSelection;
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
		ProgramStatus = NumberOfEmptyRooms();
		return ProgramStatus;

	case 'B':
		ProgramStatus = ListOfEmptyRooms();
		return ProgramStatus;

	case 'C':
		ProgramStatus = AlphaOrderGuests();
		return ProgramStatus;

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