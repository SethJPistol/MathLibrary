#pragma once
#include <math.h>
#include "Vector2.h"
#include "Vector3.h"

class Matrix3
{
public:
	float m[9];
	//	0, 3, 6
	//	1, 4, 7
	//	2, 5, 8

	Matrix3();									//Default constructs an identity matrix
	Matrix3(float m0, float m1, float m2,		//Constructor
			float m3, float m4, float m5,
			float m6, float m7, float m8);
	~Matrix3();									//Destructor

	Matrix3 operator*(const Matrix3& mToMult);	//Multiplies two matrices and returns the matrix result
	Vector3 operator*(const Vector3& vToMult);	//Multiplies the matrix by a vector3 and returns the vector result
	Matrix3 operator*(const float fScalar);		//Multiplies all matrix elements by a scalar and returns the matrix result
	void operator*=(const float fScalar);		//Multiplies all matrix elements by a scalar
	void operator=(const Matrix3& mToEqual);	//Sets all matrix elements equal to the parameter matrix

	Vector3& operator[](int nIndex);			//Returns a vector3 for the matrix column corresponding with the index (0-2)
	operator float*();							//Casts the matrix to a float pointer, which can be used like an array

	Matrix3 Transpose();						//Swaps values in the matrix diagonally, and returns the transposed matrix
	void TransposeCurrent();					//Swaps values in the matrix diagonally
	Matrix3 Inverse();							//Finds the inverse matrix of the matrix and returns it
	void Reset();								//Sets the matrix to be an identity matrix

	void setRotateX(float radians);				//Rotates the matrix around the x axis, resets any rotation/scale
	void setRotateY(float radians);				//Rotates the matrix around the y axis, resets any rotation/scale
	void setRotateZ(float radians);				//Rotates the matrix around the z axis, resets any rotation/scale
	void addRotateZ(float radians);				//Rotates the matrix around the z axis, doesn't reset any rotation/scale

	void setPosition(float x, float y);			//Uses two floats to set the position
	void setPosition(Vector2 pos);				//Uses a vector2 to set the position
	Vector2 getPosition();						//Returns a vector2 containing the position

	void setScale(float x, float y);			//Uses two floats to set the scale, resets any rotation/scale
	void setScale(Vector2 scale);				//Uses a vector2 to set the scale, resets any rotation/scale
	Vector2 getScale();							//Returns a vector2 containing the scale
};