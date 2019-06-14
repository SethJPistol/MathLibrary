#pragma once
#include <math.h>
#include <assert.h>

class Vector2
{
public:

	float x;
	float y;

	//List of all public functions:

	//---------------------------------------------------------------------------------------
	Vector2();									//Default constructor
	Vector2(float xpos, float ypos);			//Constructor with parameters
	~Vector2();									//Destructor
	
	Vector2 operator+(const Vector2& vToAdd);	//Overload to add two vectors and return a new vector
	void operator+=(const Vector2& vToAdd);		//Overload to add a vector and reassign
	Vector2 operator-(const Vector2& vToSub);	//Overload to subtract two vectors and return a new vector
	void operator-=(const Vector2& vToSub);		//Overload to subtract a vector and reassign
	
	Vector2 operator*(const float fScalar);		//Overload to multiply a vector by a scalar and return a new vector
	void operator*=(const float fScalar);		//Overload to multiply a vector by a scalar and reassign
	Vector2 operator/(const float fScalar);		//Overload to divide a vector by a scalar and return a new vector
	void operator/=(const float fScalar);		//Overload to divide a vector by a scalar and reassign

	bool operator==(const Vector2& vToCompare);	//Overload to return true if vector components are equal
	bool operator!=(const Vector2& vToCompare);	//Overload to return true if vector components are not equal
	
	float dot(const Vector2& vToDot);			//Returns the dot product of two vectors
	float magnitude();							//Returns the magnitude of the vector
	void normalise();							//Normalises the magnitude of the vector
	Vector2 unitVector();						//Returns the unit vector

	float scalarRes(Vector2& vDirecOf);			//Returns the scalar resolute of a vector in the direction of the parameter
	Vector2 vectorRes(Vector2& vDirecOf);		//Returns the vector resolute of a vector in the direction of the parameter
	Vector2 perpRes(Vector2& vDirecOf);			//Returns the perpendicular resolute of a vector in the direction of the parameter
	
	float& operator[](int nIndex);				//Overload that returns x at index [0] and y at index [1]
	operator float*();							//Overload to cast a vector to a float pointer
	//---------------------------------------------------------------------------------------
};

//Overload to multiply a vector by a scalar (in reverse order) and return a new vector
Vector2 operator*(const float& fScalar, const Vector2& vToMult);