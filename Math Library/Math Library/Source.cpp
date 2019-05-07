#include <iostream>
#include "Vector2.h"

using namespace std;

int main()
{
	Vector2 myVector(1.0f, 1.0f);
	Vector2 myVector2(4.0f, 6.0f);

	float dotProduct = myVector.dot(myVector2);
	Vector2 myUnitVector = myVector.normalise();

	

	cout << myUnitVector[0] << " " << myUnitVector[1] << endl;



	system("pause");
	return 0;
}