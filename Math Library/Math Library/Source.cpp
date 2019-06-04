#include <iostream>
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix3.h"
#include "Binary.h"

using namespace std;

int main()
{
	//Checks for memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Vector2 a(2.0f, 1.0f);
	Vector2 b(1.0f, 0.0f);

	float dotProduct = a.dot(b);
	Vector2 myUnitVector = a.unitVector();
	float myScalarResolute = a.scalarRes(b);
	Vector2 myVectorResolute = a.vectorRes(b);
	Vector2 myPerpendicularResolute = a.perpRes(b);

	/*float* p = a;
	cout << p[0] << endl;
	p[0] = 4;
	cout << p[0] << endl;*/
	
	//cout << myUnitVector.magnitude() << endl;
	//cout << myPerpendicularResolute.x << " " << myPerpendicularResolute.y << endl;



	/*Vector3 a(1.0f, 3.0f, 0.0f);
	Vector3 b(1.0f, -4.0f, 1.0f);

	Vector3 myVectorResolute = a.vectorRes(b);

	cout << myVectorResolute.x << " " << myVectorResolute.y << " " << myVectorResolute.z << endl;*/

	
	const char* bin = "101010";
	cout << binToDec(bin) << endl;

	char binString[33];
	decToBin(binString, 33, binToDec(bin));
	cout << binString << endl;


	char bitfield = 0;
	setBit(bitfield, 3, true);
	bool bIsBitTrue = checkBit(bitfield, 3);
	cout << bIsBitTrue << endl;

	/*Matrix3 myTest(3, 0, 2, 2, 0, -2, 0, 1, 1);

	cout << "Original Matrix:" << endl;
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

	cout << "Inverse Matrix:" << endl;
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

	cout << "Original Matrix * Inverse Matrix:" << endl;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << myIdentTest[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/


	system("pause");
	return 0;
}