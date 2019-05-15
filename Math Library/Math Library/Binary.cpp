#include "Binary.h"

int binToDec(const char* binaryString)
{
	int nDigits = strlen(binaryString);			//Store how many digits in the binary string
	int result = 0;
	
	for (int i = nDigits; i > 0; --i)			//Start at the least significant digit
	{
		int power = pow(2, (nDigits - i));		//Calculate the significance of the current digit
		int binChar = binaryString[i - 1] - 48;	//Find which char is at the current digit (48 or 49) and convert it to binary (0 or 1)
		int toAdd = binChar * power;			//Calculate the decimal amount represented by the current binary digit
		result += toAdd;						//Add the decimal amount to the total
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