#include "Binary.h"

int binToDec(const char* binaryString)
{
	int nDigits = strlen(binaryString);
	int result = 0;
	for (int i = nDigits; i > 0; --i)
	{
		int power = pow(2, (nDigits - i));
		int binChar = binaryString[i - 1] - 48;
		int toAdd = binChar * power;
		result += toAdd;
	}
	return result;
}

void decToBin(char* binaryString, int len, int value)
{

}

void setBit(char& bitfield, char bit, char value)
{

}

//char checkBit(char& bitfield, char bit)
//{
//
//}