#include <iostream>
#include "Vector4.h"

Vector4::Vector4()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector4::Vector4(float xpos, float ypos, float zpos, float wpos)
{
	x = xpos;
	y = ypos;
	z = zpos;
	w = wpos;
}

Vector4::~Vector4()
{
}

//Vector4::Vector4(Vector4& originalVector)
//{
//	x = originalVector.x;
//	y = originalVector.y;
//	z = originalVector.z;
//}


Vector4 Vector4::operator+(const Vector4& vToAdd)
{
	float newX = x + vToAdd.x;
	float newY = y + vToAdd.y;
	float newZ = z + vToAdd.z;
	float newW = w + vToAdd.w;
	Vector4 newV(newX, newY, newZ, newW);
	return newV;
}

void Vector4::operator+=(const Vector4& vToAdd)
{
	x = x + vToAdd.x;
	y = y + vToAdd.y;
	z = z + vToAdd.z;
	w = w + vToAdd.w;
}

Vector4 Vector4::operator-(const Vector4& vToSub)
{
	float newX = x - vToSub.x;
	float newY = y - vToSub.y;
	float newZ = z - vToSub.z;
	float newW = w - vToSub.w;
	Vector4 newV(newX, newY, newZ, newW);
	return newV;
}

void Vector4::operator-=(const Vector4& vToSub)
{
	x = x - vToSub.x;
	y = y - vToSub.y;
	z = z - vToSub.z;
	w = w - vToSub.w;
}

Vector4 Vector4::operator*(const float fScalar)
{
	float newX = x * fScalar;
	float newY = y * fScalar;
	float newZ = z * fScalar;
	float newW = w * fScalar;
	Vector4 newV(newX, newY, newZ, newW);
	return newV;
}

Vector4 operator*(const float& fScalar, const Vector4& vector)
{
	float newX = vector.x * fScalar;
	float newY = vector.y * fScalar;
	float newZ = vector.z * fScalar;
	float newW = vector.w * fScalar;
	Vector4 newV(newX, newY, newZ, newW);
	return newV;
}

void Vector4::operator*=(const float fScalar)
{
	x = x * fScalar;
	y = y * fScalar;
	z = z * fScalar;
	w = w * fScalar;
}

Vector4 Vector4::operator/(const float fScalar)
{
	assert(fScalar != 0);
	float newX = x / fScalar;
	float newY = y / fScalar;
	float newZ = z / fScalar;
	float newW = w / fScalar;
	Vector4 newV(newX, newY, newZ, newW);
	return newV;
}

void Vector4::operator/=(const float fScalar)
{
	assert(fScalar != 0);
	x = x / fScalar;
	y = y / fScalar;
	z = z / fScalar;
	w = w / fScalar;
}

bool Vector4::operator==(const Vector4& vToCompare)
{
	return x == vToCompare.x && y == vToCompare.y && z == vToCompare.z && w == vToCompare.w;
}

bool Vector4::operator!=(const Vector4& vToCompare)
{
	return x != vToCompare.x || y != vToCompare.y || z != vToCompare.z || w != vToCompare.w;
}

float Vector4::dot(const Vector4& vToDot)
{
	float newX = x * vToDot.x;
	float newY = y * vToDot.y;
	float newZ = z * vToDot.z;
	return newX + newY + newZ;
}

Vector4 Vector4::cross(const Vector4& vToCross)
{
	float newX = (y * vToCross.z) - (z * vToCross.y);
	float newY = (z * vToCross.x) - (x * vToCross.z);
	float newZ = (x * vToCross.y) - (y * vToCross.x);
	Vector4 newV(newX, newY, newZ, 0);
	return newV;
}

float Vector4::magnitude()
{
	//Square x, y, and z, add them, then square root
	return sqrtf((x * x) + (y * y) + (z * z));
}

void Vector4::normalise()
{
	float mag = magnitude();
	assert(mag != 0);
	//Divide x, y, and z by the magnitude
	x = x / mag;
	y = y / mag;
	z = z / mag;
}

Vector4 Vector4::unitVector()
{
	float mag = magnitude();
	assert(mag != 0);
	//Divide x, y, and z by the magnitude
	Vector4 newV(x / mag, y / mag, z / mag);
	return newV;
}

float Vector4::scalarRes(Vector4& vDirecOf)
{
	//Find the unit vector in direction of the parameter
	Vector4 vUnitVec = vDirecOf.unitVector();
	//Return the dot product of the vector and parameter unit vector, a*b^
	return dot(vUnitVec);
}

Vector4 Vector4::vectorRes(Vector4& vDirecOf)
{
	//Multiply the parameter unit vector by the scalar resolute, (a*b^)*b^
	return scalarRes(vDirecOf) * vDirecOf.unitVector();
}

Vector4 Vector4::perpRes(Vector4& vDirecOf)
{
	//Subtract the vector resolute from the vector, a-(a*b^)*b^
	Vector4 newV = *this - vectorRes(vDirecOf);
	return newV;
}

float& Vector4::operator[](int nIndex)
{
	switch (nIndex)
	{
	case 0: return x;
	case 1: return y;
	case 2: return z;
	case 3: return w;
	default: assert(0);
		return x; //Arbitrary return to please the compiler
	}
}

Vector4::operator float*()
{
	return &x;
}