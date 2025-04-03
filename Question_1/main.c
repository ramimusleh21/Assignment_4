// Rami Musleh - prog71990 w25 - Assignment 4 Q1


//Question 1: File I / O and toupper()
// Specifications : 4.00 / 8.00 (The program produces correct results
// but does not display them correctly or the following issues were noted : )
//—file size should not be limitted to input buffer size

// Readability + Design : 8.00 / 8.00 (The code is exceptionally well organized
// and readable due to the use of good variable names, data and function structure.
// The code is designed ‘defensively’(meaning garbage is kept out).The code allows
// for both effective testing and extension.)

// Reusability : 2.00 / 4.00 (The code appears to be designed / implemented by
// machine and /or without regard to readability or design concepts taught in the
// course or the following issues were noted : )
//--Functionality should be split into separate components, each having its own responsibility. (2)

// Documentation : 4.00 / 4.00 (The documentation is well written and clearly explains what
// the code is accomplishing and how.)


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "functions.h"
#include "globals.h"


// Write a file copy program that takes 2 command line parameters: 
	// 1) the name of an existing text file 
	// 2) the name of file to be created by your program.

// The program should use the toupper() function from ctype.h to convert all text
// in the file used as parameter 1 to uppercase as its written to the output file
// (parameter 2).Use standard I / O and access the files in text mode.


int main(int argc, char** argv) {
	
// If existing file is not found, safely end program.
	if (argc != MAXARGUMENTS) {
		fprintf(stderr, "Usage: %s <Existing File Name> <New File Name\n>.", argv[0]);
		return 1;
	}
	
	char fileOneName[FILESIZE];	// initialize Existing file name as a string
	strcpy(fileOneName, argv[1]);	// Set it equal to the first parameter

	char fileTwoName[FILESIZE];	
	strcpy(fileTwoName, argv[2]);	


	FILE* fp = fopen(fileOneName, "r");	

// Validate if file opened correctly, if not, return error and end safely
	if (fp == NULL) {
		fprintf(stderr, "error opening file\n");
		return 1;
	}

	fprintf(stdout, "%s Accessed\n", fileOneName); // Validate file opened

	char fileText[BUFFERSIZE]; // Copy text in File and store it in variable
	fgets(fileText, BUFFERSIZE, fp);

	strcpy(fileText, MakeUpper(fileText)); // make all characters uppercase using toupper()
	fclose(fp); // Close File 1
	
	fp = CreateFile(fileTwoName); // Create a new file
	if (CreateFile == NULL) {
		return 1;
	}

	PrintToFile(fp, fileText); // paste text into new file
	
	fclose(fp); // Close file 2

	return 0;
}
