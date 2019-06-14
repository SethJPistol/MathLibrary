#pragma once
#include <math.h>
#include <assert.h>

class Vector3
{
public:

	float x;
	float y;
	float z;

	//List of all public functions:

	//---------------------------------------------------------------------------------------
	Vector3();										//Default constructor
	Vector3(float xpos, float ypos, float zpos);	//Constructor with parameters
	~Vector3();										//Destructor

	Vector3 operator+(const Vector3& vToAdd);		//Overload to add two vectors and return a new vector
	void operator+=(const Vector3& vToAdd);			//Overload to add a vector and reassign
	Vector3 operator-(const Vector3& vToSub);		//Overload to subtract two vectors and return a new vector
	void operator-=(const Vector3& vToSub);			//Overload to subtract a vector and reassign

	Vector3 operator*(const float fScalar);			//Overload to multiply a vector by a scalar and return a new vector
	void operator*=(const float fScalar);			//Overload to multiply a vector by a scalar and reassign
	Vector3 operator/(const float fScalar);			//Overload to divide a vector by a scalar and return a new vector
	void operator/=(const float fScalar);			//Overload to divide a vector by a scalar and reassign

	bool operator==(const Vector3& vToCompare);		//Overload to return true if vector components are equal
	bool operator!=(const Vector3& vToCompare);		//Overload to return true if vector components are not equal

	float dot(const Vector3& vToDot);				//Returns the dot product of two vectors
	Vector3 cross(const Vector3& vToCross);			//Returns the right-hand cross product of two vectors
	float magnitude();								//Returns the magnitude of the vector
	void normalise();								//Normalises the magnitude of the vector
	Vector3 unitVector();							//Returns the unit vector

	float scalarRes(Vector3& vDirecOf);				//Returns the scalar resolute of a vector in the direction of the parameter
	Vector3 vectorRes(Vector3& vDirecOf);			//Returns the vector resolute of a vector in the direction of the parameter
	Vector3 perpRes(Vector3& vDirecOf);				//Returns the perpendicular resolute of a vector in the direction of the parameter

	float& operator[](int nIndex);					//Overload that returns x at index [0], y at index [1], and z at index [2]
	operator float*();								//Overload to cast a vector to a float pointer
	//---------------------------------------------------------------------------------------
};

//Overload to multiply a vector by a scalar (in reverse order) and return a new vector
Vector3 operator*(const float& fScalar, const Vector3& vToMult);