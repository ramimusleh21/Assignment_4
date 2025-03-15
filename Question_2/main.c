// Rami Musleh - prog71990 w25 - Assignment 4 Q2

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include "functions.h"

int main(void) {

	AccessFile();

	bool programOn = true;
	while (programOn) {
		int userSelection = MainMenu();

		if (userSelection == false) {
			programOn = false;
		}
	}

	return 0;
}