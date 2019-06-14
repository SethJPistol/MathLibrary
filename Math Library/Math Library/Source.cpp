#include <iostream>
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "Binary.h"

using namespace std;

int main()
{
	//Checks for memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Vector2 examples
	Vector2 a(2.0f, 1.0f);
	Vector2 b(1.0f, 0.0f);

	float dotProduct = a.dot(b);
	Vector2 aUnitVector = a.unitVector();
	float myScalarResolute = a.scalarRes(b);
	Vector2 myVectorResolute = a.vectorRes(b);
	Vector2 myPerpendicularResolute = a.perpRes(b);
	
	cout << "-Vector2 examples-" << endl;
	cout << "Vector a: " << a.x << ", " << a.y << endl;
	cout << "Magnitude of the unit vector: " << aUnitVector.magnitude() << endl;


	//Vector3 examples
	Vector3 c(2.0f, 1.0f, 3.0f);

	Vector3 cUnitVector = c.unitVector();

	cout << endl << endl << "-Vector3 examples-" << endl;
	cout << "Vector c: " << c.x << ", " << c.y << ", " << c.z << endl;
	cout << "Magnitude of the unit vector: " << cUnitVector.magnitude() << endl;
	

	//Binary examples
	const char* bin = "101010";
	cout << endl << endl << "-Binary examples-" << endl;
	cout << "Binary to convert to int: 101010" << endl;
	cout << "Converted = " << binToDec(bin) << endl << endl;

	char binString[33];
	decToBin(binString, 33, 42);
	cout << "Int to convert to binary: 42" << endl;
	cout << "Converted = " << binString << endl << endl;


	char bitfield = 0;	//Set all the bits to 0
	setBit(bitfield, 3, true);
	bool bIsBitTrue = checkBit(bitfield, 3);
	if (bIsBitTrue)
		cout << "Bit set and check successful" << endl;


	//Matrix3 inverse examples
	Matrix3 myTest(3, 0, 2, 2, 0, -2, 0, 1, 1);

	cout << endl << endl << "-Matrix3 examples-" << endl;
	cout << "Original Matrix =" << endl;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << myTest[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	Matrix3 myInvTest = myTest.Inverse();

	cout << "Inverse Matrix =" << endl;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << myInvTest[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	Matrix3 myIdentTest = myTest * myInvTest;

	cout << "Original Matrix * Inverse Matrix =" << endl;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << myIdentTest[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;


	system("pause");
	return 0;
}