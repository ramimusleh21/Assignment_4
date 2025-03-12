// Rami Musleh - prog71990 w25 - Assignment 4 Q1

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BUFFERSIZE 100
#define MAXARGUMENTS 3


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


	
	char fileOneName[BUFFERSIZE];	// initialize Existing file name as a string
	strcpy(fileOneName, argv[1]);	// Set it equal to the first parameter

	char fileTwoName[BUFFERSIZE];	// initialize Existing file name as a string
	strcpy(fileTwoName, argv[2]);	// Set it equal to the second parameter


	FILE* fp = fopen(fileOneName, "r");	// This uses FILE* 
												// Function and lable 'fp' (file pointer)
												// to open a file in the source file folder
												// the "r" means its only reading the file.


// Validate if file opened correctly, if not, return error and end safely
	if (fp == NULL) {
		fprintf(stderr, "error opening file\n");
		return 1;
	}

	fprintf(stdout, "%s Accessed\n", fileOneName); // Validate file opened

// Copy text in File and store it in variable
	char fileText[BUFFERSIZE] = { 0 };
	fgets(fileText, BUFFERSIZE, fp);


// make all characters uppercase using toupper()
	int fileTextLength = strlen(fileText);
	for (int i = 0; i < fileTextLength; i++) {
		fileText[i] = toupper(fileText[i]);
	}
	
// Close File 1
	fclose(fp);
	
// Create a new file
	fp = fopen(fileTwoName, "w");

	if (fp == NULL) {
		fprintf(stderr, "error opening file\n");
		return 1;
	}

	fprintf(stdout, "%s Accessed\n", fileTwoName);
	
// paste text into new file
	fprintf(fp, fileText);
	
// Close file 2
	fclose(fp);

	return 0;
}
