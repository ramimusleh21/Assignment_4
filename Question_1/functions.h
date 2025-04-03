#pragma once
#include <stdio.h>

char* MakeUpper(char* fileText);

FILE* CreateFile(char* fileTwoName);

void PrintToFile(FILE* fp, char* fileText);
