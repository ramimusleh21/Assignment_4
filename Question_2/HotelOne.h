// Rami Musleh - prog71990 w25 - Assignment 4 Q2 Refactor

#pragma once

// MENU FUNCTIONS
bool MainMenuOne(ROOMS* rooms);


// ROOM FUNCTIONS
bool NumberOfEmptyRoomsOne();

bool ListOfEmptyRoomsOne();

bool AlphaOrderGuestsOne(ROOMS* rooms);
bool OrderByFirstNameOne(ROOMS* rooms);
bool OrderByLastNameOne(ROOMS* rooms);

bool BookARoomOne(rooms);

bool AddRoomOne(ROOMS* room, int i, char* status, char* firstName, char* lastName);

bool DeleteABookingOne(rooms);
bool DeleteRoomOne(ROOMS* room, int i, char* status, char* firstName, char* lastName,
	char* type, HOTEL hotel);