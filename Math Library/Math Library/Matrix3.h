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

	Matrix3();
	Matrix3(float m0, float m1, float m2,
			float m3, float m4, float m5,
			float m6, float m7, float m8);
	~Matrix3();

	Matrix3 operator*(const Matrix3& mToMult);
	Vector3 operator*(const Vector3& vToMult);

	Vector3& operator[](int nIndex);
	operator float*();

	void setRotateX(float radians);
	void setRotateY(float radians);
	void setRotateZ(float radians);

	void setPosition(float x, float y);
	void setPosition(Vector2 pos);
	Vector2 getPosition();

	//Wipes any rotation, creates a scale matrix
	void setScale(float x, float y);
	void setScale(Vector2 scale);
};