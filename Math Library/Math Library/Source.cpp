#include <iostream>
#include "Vector2.h"
#include "Vector3.h"

using namespace std;

int main()
{
	/*Vector2 a(2.0f, 1.0f);
	Vector2 b(1.0f, 0.0f);

	float dotProduct = a.dot(b);
	Vector2 myUnitVector = a.normalise();
	float myScalarResolute = a.scalarRes(b);
	Vector2 myVectorResolute = a.vectorRes(b);
	Vector2 myPerpendicularResolute = a.perpRes(b);*/

	
	//cout << myUnitVector.magnitude() << endl;
	//cout << myPerpendicularResolute.x << " " << myPerpendicularResolute.y << endl;



	Vector3 a(1.0f, 3.0f, 0.0f);
	Vector3 b(1.0f, -4.0f, 1.0f);

	Vector3 myVectorResolute = a.vectorRes(b);

	cout << myVectorResolute.x << " " << myVectorResolute.y << " " << myVectorResolute.z << endl;



	system("pause");
	return 0;
}