#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "globals.h"

char* MakeUpper(char* fileText) {
	size_t fileTextLength = strlen(fileText);
	for (int i = 0; i < fileTextLength; i++) {
		fileText[i] = toupper(fileText[i]);
	}
	return fileText;
}

FILE* CreateFile(char* fileTwoName) {
	FILE* fp = fopen(fileTwoName, "w");

	if (fp == NULL) {
		fprintf(stderr, "error opening file\n");
		return NULL;
	}

	fprintf(stdout, "%s Accessed\n", fileTwoName);

	return fp;
}

void PrintToFile(FILE* fp, char* fileText) {

	fprintf(fp, fileText); // paste text into new file
}

