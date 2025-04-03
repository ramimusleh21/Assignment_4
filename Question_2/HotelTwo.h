// Rami Musleh - prog71990 w25 - Assignment 4 Q2 Refactor

#pragma once

// MENU FUNCTIONS
bool MainMenuTwo(ROOMS* rooms);


// ROOM FUNCTIONS
bool NumberOfEmptyRoomsTwo();

bool ListOfEmptyRoomsTwo();

bool AlphaOrderGuestsTwo(ROOMS* rooms);
bool OrderByFirstNameTwo(ROOMS* rooms);
bool OrderByLastNameTwo(ROOMS* rooms);

bool BookARoomTwo(rooms);

bool AddRoomTwo(ROOMS* room, int i, char* status, char* firstName, char* lastName);

bool DeleteABookingTwo(rooms);
bool DeleteRoomTwo(ROOMS* room, int i, char* status, char* firstName, char* lastName,
	char* type, HOTEL hotel);