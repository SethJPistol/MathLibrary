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
	/*Vector2();								Default constructor
	Vector2(float xpos, float ypos);			Constructor with parameters
	~Vector2();									Destructor
	Vector2(Vector2& originalVector);			Copy Constructor

	Vector2 operator+(const Vector2& vToAdd);	Overload to add two vectors and return a new vector
	void operator+=(const Vector2& vToAdd);		Overload to add a vector and reassign

	Vector2 operator-(const Vector2& vToSub);	Overload to subtract two vectors and return a new vector
	void operator-=(const Vector2& vToSub);		Overload to subtract a vector and reassign

	Vector2 operator*(const float fScalar);		Overload to multiply a vector by a scalar and return a new vector
	void operator*=(const float fScalar);		Overload to multiply a vector by a scalar and reassign

	Vector2 operator/(const float fScalar);		Overload to divide a vector by a scalar and return a new vector
	void operator/=(const float fScalar);		Overload to divide a vector by a scalar and reassign

	float dot(const Vector2& vToDot);			Returns the dot product of two vectors
	float magnitude();							Returns the magnitude of the vector
	Vector2 normalise();						Returns the unit vector
	
	float operator[](int nIndex);				Overload that returns x at index [0] and y at index [1]*/
	//---------------------------------------------------------------------------------------

	Vector2();
	Vector2(float xpos, float ypos);
	~Vector2();
	//Vector2(Vector2& originalVector);

	Vector2 operator+(const Vector2& vToAdd);
	void operator+=(const Vector2& vToAdd);

	Vector2 operator-(const Vector2& vToSub);
	void operator-=(const Vector2& vToSub);

	Vector2 operator*(const float fScalar);
	void operator*=(const float fScalar);

	Vector2 operator/(const float fScalar);
	void operator/=(const float fScalar);

	float dot(const Vector2& vToDot);
	float magnitude();
	Vector2 normalise();
	float scalarRes(const Vector2& vDirecOf);

	float operator[](int nIndex);
	

//------------------------------------------------------------------------------------------------------------------------------

private:


};

//Overload to multiply a vector by a scalar (in reverse order) and return a new vector
Vector2 operator*(const float& fScalar, const Vector2& vToMult);