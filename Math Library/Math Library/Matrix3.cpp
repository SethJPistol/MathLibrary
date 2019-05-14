#include "Matrix3.h"

Matrix3::Matrix3()
{
	//Identity matrix
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 1;
	m[5] = 0;
	m[6] = 0;
	m[7] = 0;
	m[8] = 1;
}

Matrix3::Matrix3(float m0, float m1, float m2,
				float m3, float m4, float m5,
				float m6, float m7, float m8)
{
	m[0] = m0;
	m[1] = m1;
	m[2] = m2;
	m[3] = m3;
	m[4] = m4;
	m[5] = m5;
	m[6] = m6;
	m[7] = m7;
	m[8] = m8;
}
Matrix3::~Matrix3()
{

}

Matrix3 Matrix3::operator*(const Matrix3& mToMult)
{
	Matrix3 newM;
	newM.m[0] = (m[0] * mToMult.m[0]) + (m[3] * mToMult.m[1]) + (m[6] * mToMult.m[2]);
	newM.m[1] = (m[1] * mToMult.m[0]) + (m[4] * mToMult.m[1]) + (m[7] * mToMult.m[2]);
	newM.m[2] = (m[2] * mToMult.m[0]) + (m[5] * mToMult.m[1]) + (m[8] * mToMult.m[2]);

	newM.m[3] = (m[0] * mToMult.m[3]) + (m[3] * mToMult.m[4]) + (m[6] * mToMult.m[5]);
	newM.m[4] = (m[1] * mToMult.m[3]) + (m[4] * mToMult.m[4]) + (m[7] * mToMult.m[5]);
	newM.m[5] = (m[2] * mToMult.m[3]) + (m[5] * mToMult.m[4]) + (m[8] * mToMult.m[5]);

	newM.m[6] = (m[0] * mToMult.m[6]) + (m[3] * mToMult.m[7]) + (m[6] * mToMult.m[8]);
	newM.m[7] = (m[1] * mToMult.m[6]) + (m[4] * mToMult.m[7]) + (m[7] * mToMult.m[8]);
	newM.m[8] = (m[2] * mToMult.m[6]) + (m[5] * mToMult.m[7]) + (m[8] * mToMult.m[8]);
	return newM;
}

Vector3 Matrix3::operator*(const Vector3& vToMult)
{
	Vector3 newV;
	newV.x = (m[0] * vToMult.x) + (m[3] * vToMult.y) + (m[6] * vToMult.z);
	newV.y = (m[1] * vToMult.x) + (m[4] * vToMult.y) + (m[7] * vToMult.z);
	newV.z = (m[2] * vToMult.x) + (m[5] * vToMult.y) + (m[8] * vToMult.z);
	return newV;
}

Vector3& Matrix3::operator[](int nIndex)
{
	//Find the address of the column, cast it to a vector3 pointer,
	//then dereference to return the address of that new vector3
	return *((Vector3*)&m[nIndex * 3]);
}

Matrix3::operator float*()
{
	return m;
}

void Matrix3::setRotateX(float radians)
{
	float cosValue = cosf(radians);
	float sinValue = sinf(radians);

	m[4] = cosValue;
	m[5] = sinValue;

	m[7] = -sinValue;
	m[8] = cosValue;
}

void Matrix3::setRotateY(float radians)
{
	float cosValue = cosf(radians);
	float sinValue = sinf(radians);

	m[0] = cosValue;
	m[2] = -sinValue;

	m[6] = sinValue;
	m[8] = cosValue;
}

void Matrix3::setRotateZ(float radians)
{
	float cosValue = cosf(radians);
	float sinValue = sinf(radians);

	m[0] = cosValue;
	m[1] = sinValue;

	m[3] = -sinValue;
	m[4] = cosValue;
}

void Matrix3::setPosition(float x, float y)
{
	m[6] = x;
	m[7] = y;
}

void Matrix3::setPosition(Vector2 pos)
{
	setPosition(pos.x, pos.y);
}

Vector2 Matrix3::getPosition()
{
	Vector2 pos(m[6], m[7]);

	return pos;
}

void Matrix3::setScale(float x, float y)
{
	m[0] = x;
	m[1] = 0;
	m[3] = 0;
	m[4] = y;
}

void Matrix3::setScale(Vector2 scale)
{
	setScale(scale.x, scale.y);
}