// Rami Musleh - prog71990 w25 - Assignment 4 Q2 Refactor

#pragma once
#include "globals.h"


// FILE FUNCTIONS
	bool AccessFile(ROOMS* rooms);
	bool ReadFile(ROOMS* room);
	bool NewFile(ROOMS* room);


// ROOM STRUCT FUNCTIONS
	ROOMS CreateRoom(	ROOMS RoomName, int RoomNumber, char* status,
						char* firstName, char* lastName, HOTEL hotel, char* type, FILE* fp);

	void ReplaceRoomV2(ROOMS room, int RoomNumber, char* status, char* firstName,
		char* lastName);


	
// PRINT FUNCTIONS

	void PrintRoom(ROOMS* rooms, int i);

	bool PrintAllRooms(ROOMS* rooms);


// MENU FUNCTIONS
	bool TopMenu(ROOMS* rooms);
	

	





