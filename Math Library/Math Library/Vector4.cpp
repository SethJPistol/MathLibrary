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
	float newx = x + vToAdd.x;
	float newy = y + vToAdd.y;
	float newz = z + vToAdd.z;
	Vector4 newV(newx, newy, newz);
	return newV;
}

void Vector4::operator+=(const Vector4& vToAdd)
{
	x = x + vToAdd.x;
	y = y + vToAdd.y;
	z = z + vToAdd.z;
}

Vector4 Vector4::operator-(const Vector4& vToSub)
{
	float newx = x - vToSub.x;
	float newy = y - vToSub.y;
	float newz = z - vToSub.z;
	Vector4 newV(newx, newy, newz);
	return newV;
}

void Vector4::operator-=(const Vector4& vToSub)
{
	x = x - vToSub.x;
	y = y - vToSub.y;
	z = z - vToSub.z;
}

Vector4 Vector4::operator*(const float fScalar)
{
	float newx = x * fScalar;
	float newy = y * fScalar;
	float newz = z * fScalar;
	Vector4 newV(newx, newy, newz);
	return newV;
}

Vector4 operator*(const float& fScalar, const Vector4& vector)
{
	float newx = vector.x * fScalar;
	float newy = vector.y * fScalar;
	float newz = vector.z * fScalar;
	Vector4 newV(newx, newy, newz);
	return newV;
}

void Vector4::operator*=(const float fScalar)
{
	x = x * fScalar;
	y = y * fScalar;
	z = z * fScalar;
}

Vector4 Vector4::operator/(const float fScalar)
{
	assert(fScalar != 0);
	float newx = x / fScalar;
	float newy = y / fScalar;
	float newz = z / fScalar;
	Vector4 newV(newx, newy, newz);
	return newV;
}

void Vector4::operator/=(const float fScalar)
{
	assert(fScalar != 0);
	x = x / fScalar;
	y = y / fScalar;
	z = z / fScalar;
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
	float newx = x * vToDot.x;
	float newy = y * vToDot.y;
	float newz = z * vToDot.z;
	return newx + newy + newz;
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
	return sqrt((x * x) + (y * y) + (z * z));
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
	}
}

Vector4::operator float*()
{
	return &x;
}