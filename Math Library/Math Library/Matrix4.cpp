#include "Matrix4.h"

Matrix4::Matrix4()
{
	//Identity matrix
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 0;
	m[5] = 1;
	m[6] = 0;
	m[7] = 0;
	m[8] = 0;
	m[9] = 0;
	m[10] = 1;
	m[11] = 0;
	m[12] = 0;
	m[13] = 0;
	m[14] = 0;
	m[15] = 1;
}

Matrix4::Matrix4(float m0, float m1, float m2, float m3,
				float m4, float m5, float m6, float m7,
				float m8, float m9, float m10, float m11,
				float m12, float m13, float m14, float m15)
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
	m[9] = m9;
	m[10] = m10;
	m[11] = m11;
	m[12] = m12;
	m[13] = m13;
	m[14] = m14;
	m[15] = m15;
}
Matrix4::~Matrix4()
{

}

Matrix4 Matrix4::operator*(const Matrix4& mToMult)
{
	Matrix4 newM;
	newM.m[0] = (m[0] * mToMult.m[0]) + (m[4] * mToMult.m[1]) + (m[8] * mToMult.m[2]) + (m[12] * mToMult.m[3]);
	newM.m[1] = (m[1] * mToMult.m[0]) + (m[5] * mToMult.m[1]) + (m[9] * mToMult.m[2]) + (m[13] * mToMult.m[3]);
	newM.m[2] = (m[2] * mToMult.m[0]) + (m[6] * mToMult.m[1]) + (m[10] * mToMult.m[2]) + (m[14] * mToMult.m[3]);
	newM.m[3] = (m[3] * mToMult.m[0]) + (m[7] * mToMult.m[1]) + (m[11] * mToMult.m[2]) + (m[15] * mToMult.m[3]);

	newM.m[4] = (m[0] * mToMult.m[4]) + (m[4] * mToMult.m[5]) + (m[8] * mToMult.m[6]) + (m[12] * mToMult.m[7]);
	newM.m[5] = (m[1] * mToMult.m[4]) + (m[5] * mToMult.m[5]) + (m[9] * mToMult.m[6]) + (m[13] * mToMult.m[7]);
	newM.m[6] = (m[2] * mToMult.m[4]) + (m[6] * mToMult.m[5]) + (m[10] * mToMult.m[6]) + (m[14] * mToMult.m[7]);
	newM.m[7] = (m[3] * mToMult.m[4]) + (m[7] * mToMult.m[5]) + (m[11] * mToMult.m[6]) + (m[15] * mToMult.m[7]);

	newM.m[8] = (m[0] * mToMult.m[8]) + (m[4] * mToMult.m[9]) + (m[8] * mToMult.m[10]) + (m[12] * mToMult.m[11]);
	newM.m[9] = (m[1] * mToMult.m[8]) + (m[5] * mToMult.m[9]) + (m[9] * mToMult.m[10]) + (m[13] * mToMult.m[11]);
	newM.m[10] = (m[2] * mToMult.m[8]) + (m[6] * mToMult.m[9]) + (m[10] * mToMult.m[10]) + (m[14] * mToMult.m[11]);
	newM.m[11] = (m[3] * mToMult.m[8]) + (m[7] * mToMult.m[9]) + (m[11] * mToMult.m[10]) + (m[15] * mToMult.m[11]);

	newM.m[12] = (m[0] * mToMult.m[12]) + (m[4] * mToMult.m[13]) + (m[8] * mToMult.m[14]) + (m[12] * mToMult.m[15]);
	newM.m[13] = (m[1] * mToMult.m[12]) + (m[5] * mToMult.m[13]) + (m[9] * mToMult.m[14]) + (m[13] * mToMult.m[15]);
	newM.m[14] = (m[2] * mToMult.m[12]) + (m[6] * mToMult.m[13]) + (m[10] * mToMult.m[14]) + (m[14] * mToMult.m[15]);
	newM.m[15] = (m[3] * mToMult.m[12]) + (m[7] * mToMult.m[13]) + (m[11] * mToMult.m[14]) + (m[15] * mToMult.m[15]);
	return newM;
}

Vector4 Matrix4::operator*(const Vector4& vToMult)
{
	Vector4 newV;
	newV.x = (m[0] * vToMult.x) + (m[4] * vToMult.y) + (m[8] * vToMult.z) + (m[12] * vToMult.w);
	newV.y = (m[1] * vToMult.x) + (m[5] * vToMult.y) + (m[9] * vToMult.z) + (m[13] * vToMult.w);
	newV.z = (m[2] * vToMult.x) + (m[6] * vToMult.y) + (m[10] * vToMult.z) + (m[14] * vToMult.w);
	newV.w = (m[3] * vToMult.x) + (m[7] * vToMult.y) + (m[11] * vToMult.z) + (m[15] * vToMult.w);
	return newV;
}

Matrix4 Matrix4::operator*(const float fScalar)
{
	Matrix4 newM;
	for (int i = 0; i < 16; ++i)
	{
		newM.m[i] = m[i] * fScalar;
	}
	return newM;
}

void Matrix4::operator*=(const float fScalar)
{
	for (int i = 0; i < 16; ++i)
	{
		m[i] *= fScalar;
	}
}

Vector4& Matrix4::operator[](int nIndex)
{
	//Find the address of the column, cast it to a Vector4 pointer,
	//then dereference to return the address of that new Vector4
	return *((Vector4*)&m[nIndex * 4]);
}

Matrix4::operator float*()
{
	return m;
}

Matrix4 Matrix4::Transpose()
{
	return Matrix4(m[0], m[4], m[8], m[12], 
					m[1], m[5], m[9], m[13], 
					m[2], m[6], m[10], m[14],
					m[3], m[7], m[11], m[15]);
}

void Matrix4::TransposeCurrent()
{
	float temp = m[1];
	m[1] = m[4];
	m[4] = temp;

	temp = m[2];
	m[2] = m[8];
	m[8] = temp;

	temp = m[3];
	m[3] = m[12];
	m[12] = temp;

	temp = m[6];
	m[6] = m[9];
	m[9] = temp;

	temp = m[7];
	m[7] = m[13];
	m[13] = temp;

	temp = m[11];
	m[11] = m[14];
	m[14] = temp;
}

void Matrix4::Reset()
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 0;
	m[5] = 1;
	m[6] = 0;
	m[7] = 0;
	m[8] = 0;
	m[9] = 0;
	m[10] = 1;
	m[11] = 0;
	m[12] = 0;
	m[13] = 0;
	m[14] = 0;
	m[15] = 1;
}

void Matrix4::setRotateX(float radians)
{
	float cosValue = cosf(radians);
	float sinValue = sinf(radians);

	m[5] = cosValue;
	m[6] = sinValue;

	m[9] = -sinValue;
	m[10] = cosValue;
}

void Matrix4::setRotateY(float radians)
{
	float cosValue = cosf(radians);
	float sinValue = sinf(radians);

	m[0] = cosValue;
	m[2] = -sinValue;

	m[8] = sinValue;
	m[10] = cosValue;
}

void Matrix4::setRotateZ(float radians)
{
	float cosValue = cosf(radians);
	float sinValue = sinf(radians);

	m[0] = cosValue;
	m[1] = sinValue;

	m[4] = -sinValue;
	m[5] = cosValue;
}