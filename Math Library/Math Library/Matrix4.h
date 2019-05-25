#pragma once
#include <math.h>
#include "Vector4.h"

class Matrix4
{
public:
	float m[16];
	//	0, 4, 8,  12
	//	1, 5, 9,  13
	//	2, 6, 10, 14
	//	3, 7, 11, 15

	Matrix4();											//Default constructs an identity matrix
	Matrix4(float m0, float m1, float m2, float m3,		//Constructor
			float m4, float m5, float m6, float m7,		
			float m8, float m9, float m10, float m11,	
			float m12, float m13, float m14, float m15);
	~Matrix4();											//Destructor

	Matrix4 operator*(const Matrix4& mToMult);			//Multiplies two matrices and returns the matrix result
	Vector4 operator*(const Vector4& vToMult);			//Multiplies the matrix by a vector4 and returns the vector result
	Matrix4 operator*(const float fScalar);				//Multiplies all matrix elements by a scalar and returns the matrix result
	void operator*=(const float fScalar);				//Multiplies all matrix elements by a scalar

	Vector4& operator[](int nIndex);					//Returns a vector4 for the matrix column corresponding with the index (0-3)
	operator float*();									//Casts the matrix to a float pointer, which can be used like an array

	Matrix4 Transpose();								//Swaps values in the matrix diagonally, and returns the transposed matrix
	void TransposeCurrent();							//Swaps values in the matrix diagonally
	void Reset();										//Sets the matrix to be an identity matrix

	void setRotateX(float radians);						//Rotates the matrix around the x axis, resets any rotation/scale
	void setRotateY(float radians);						//Rotates the matrix around the y axis, resets any rotation/scale
	void setRotateZ(float radians);						//Rotates the matrix around the z axis, resets any rotation/scale
};