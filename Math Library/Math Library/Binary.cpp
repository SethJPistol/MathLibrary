#include "Binary.h"

int binToDec(const char* binaryString)
{
	int nBits = strlen(binaryString);			//Store how many binary digits in the binary string
	int nResult = 0;

	for (int i = 0; i < nBits; ++i)				//Until the end of the string,
	{
		if (binaryString[nBits - i - 1] == 49)	//If the char at the index is 1,
		{
			nResult |= (1 << i);				//Change the corresponding bit of the int to 1
		}
	}
	return nResult;
}

void decToBin(char* binaryString, int len, int value)
{
	assert(len >= 33);							//Make sure the size of the string is over 33
	char szReverseString[33];					//Character array storing up to a 32-bit binary string and a null terminator
	int i = 0;									//Iterator for the loop
	while (value > 1)							//Repeat until 0 or 1
	{
		szReverseString[i] = value % 2 + 48;	//Find the remainder (0 or 1) and convert it to a 0 or 1 char
		value /= 2;								//Divide value by 2
		++i;
	}
	szReverseString[i] = value + 48;			//Convert the final value (0 or 1) to a 0 or 1 char
	int j = 0;									//Second iterator
	for (j; i >= 0; ++j)						//Repeat until all bits have been reversed
	{
		binaryString[j] = szReverseString[i];	//Put the last bit in the reverse string into the first bit in the binary string
		--i;									//Count the iterator down
	}
	binaryString[j] = 0;						//Set the last char in the array to null
}

void setBit(char& bitfield, char bit, char value)
{
	if (value)
		bitfield |= (1 << bit);	//Sets the bit to 1
		// 01010000
		// 00001000
		// 01011000
	else
		bitfield ^= (1 << bit);	//Sets the bit to 0
		// 01011000
		// 00001000
		// 01010000
}

char checkBit(char& bitfield, char bit)
{
	return (bitfield & (1 << bit)) != 0;
	// 01011000
	// 00001000
	// 00001000
}