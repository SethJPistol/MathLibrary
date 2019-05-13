#pragma once
#include <math.h>
#include <assert.h>

class Vector4
{
public:

	float x;
	float y;
	float z;
	float w;

	//List of all public functions:

	//---------------------------------------------------------------------------------------
	Vector4();													//Default constructor
	Vector4(float xpos, float ypos, float zpos, float wpos = 1);//Constructor with parameters
	~Vector4();													//Destructor
	//Vector4(Vector4& originalVector);							//Copy Constructor

	Vector4 operator+(const Vector4& vToAdd);					//Overload to add two vectors and return a new vector
	void operator+=(const Vector4& vToAdd);						//Overload to add a vector and reassign
	Vector4 operator-(const Vector4& vToSub);					//Overload to subtract two vectors and return a new vector
	void operator-=(const Vector4& vToSub);						//Overload to subtract a vector and reassign

	Vector4 operator*(const float fScalar);						//Overload to multiply a vector by a scalar and return a new vector
	void operator*=(const float fScalar);						//Overload to multiply a vector by a scalar and reassign
	Vector4 operator/(const float fScalar);						//Overload to divide a vector by a scalar and return a new vector
	void operator/=(const float fScalar);						//Overload to divide a vector by a scalar and reassign

	bool operator==(const Vector4& vToCompare);					//Overload to return true if vector components are equal
	bool operator!=(const Vector4& vToCompare);					//Overload to return true if vector components are not equal

	float dot(const Vector4& vToDot);							//Returns the dot product of two vectors
	Vector4 cross(const Vector4& vToCross);						//Returns the right-hand cross product of two vectors
	float magnitude();											//Returns the magnitude of the vector
	void normalise();											//Normalises the magnitude of the vector
	Vector4 unitVector();										//Returns the unit vector

	float scalarRes(Vector4& vDirecOf);							//Returns the scalar resolute of a vector in the direction of the parameter
	Vector4 vectorRes(Vector4& vDirecOf);						//Returns the vector resolute of a vector in the direction of the parameter
	Vector4 perpRes(Vector4& vDirecOf);							//Returns the perpendicular resolute of a vector in the direction of the parameter

	float& operator[](int nIndex);								//Overload that returns x at index [0], y at index [1], z at index [2], and w at index [3]
	operator float*();											//Overload to cast a vector to a float pointer
	//---------------------------------------------------------------------------------------
};

//Overload to multiply a vector by a scalar (in reverse order) and return a new vector
Vector4 operator*(const float& fScalar, const Vector4& vToMult);