#pragma once
#include <iostream>
#include <assert.h>
	
//List of all public functions:

//---------------------------------------------------------------------------------------
int binToDec(const char* binaryString);					//Converts a string of binary to an integer
void decToBin(char* binaryString, int len, int value);	//Converts an integer into a string of binary

void setBit(char& bitfield, char bit, char value);		//Sets the specified bit in the bitfield to true or false
char checkBit(char& bitfield, char bit);				//Checks if the specified bit in the bitfield is true or false
//---------------------------------------------------------------------------------------