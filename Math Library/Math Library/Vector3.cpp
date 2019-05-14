#include <iostream>
#include "Vector3.h"

Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(float xpos, float ypos, float zpos)
{
	x = xpos;
	y = ypos;
	z = zpos;
}

Vector3::~Vector3()
{
}

//Vector3::Vector3(Vector3& originalVector)
//{
//	x = originalVector.x;
//	y = originalVector.y;
//	z = originalVector.z;
//}


Vector3 Vector3::operator+(const Vector3& vToAdd)
{
	float newx = x + vToAdd.x;
	float newy = y + vToAdd.y;
	float newz = z + vToAdd.z;
	Vector3 newV(newx, newy, newz);
	return newV;
}

void Vector3::operator+=(const Vector3& vToAdd)
{
	x = x + vToAdd.x;
	y = y + vToAdd.y;
	z = z + vToAdd.z;
}

Vector3 Vector3::operator-(const Vector3& vToSub)
{
	float newx = x - vToSub.x;
	float newy = y - vToSub.y;
	float newz = z - vToSub.z;
	Vector3 newV(newx, newy, newz);
	return newV;
}

void Vector3::operator-=(const Vector3& vToSub)
{
	x = x - vToSub.x;
	y = y - vToSub.y;
	z = z - vToSub.z;
}

Vector3 Vector3::operator*(const float fScalar)
{
	float newx = x * fScalar;
	float newy = y * fScalar;
	float newz = z * fScalar;
	Vector3 newV(newx, newy, newz);
	return newV;
}

Vector3 operator*(const float& fScalar, const Vector3& vector)
{
	float newx = vector.x * fScalar;
	float newy = vector.y * fScalar;
	float newz = vector.z * fScalar;
	Vector3 newV(newx, newy, newz);
	return newV;
}

void Vector3::operator*=(const float fScalar)
{
	x = x * fScalar;
	y = y * fScalar;
	z = z * fScalar;
}

Vector3 Vector3::operator/(const float fScalar)
{
	assert(fScalar != 0);
	float newx = x / fScalar;
	float newy = y / fScalar;
	float newz = z / fScalar;
	Vector3 newV(newx, newy, newz);
	return newV;
}

void Vector3::operator/=(const float fScalar)
{
	assert(fScalar != 0);
	x = x / fScalar;
	y = y / fScalar;
	z = z / fScalar;
}

bool Vector3::operator==(const Vector3& vToCompare)
{
	return x == vToCompare.x && y == vToCompare.y && z == vToCompare.z;
}

bool Vector3::operator!=(const Vector3& vToCompare)
{
	return x != vToCompare.x || y != vToCompare.y || z != vToCompare.z;
}

float Vector3::dot(const Vector3& vToDot)
{
	float newx = x * vToDot.x;
	float newy = y * vToDot.y;
	float newz = z * vToDot.z;
	return newx + newy + newz;
}

Vector3 Vector3::cross(const Vector3& vToCross)
{
	float newX = (y * vToCross.z) - (z * vToCross.y);
	float newY = (z * vToCross.x) - (x * vToCross.z);
	float newZ = (x * vToCross.y) - (y * vToCross.x);
	Vector3 newV(newX, newY, newZ);
	return newV;
}

float Vector3::magnitude()
{
	//Square x, y, and z, add them, then square root
	return sqrtf((x * x) + (y * y) + (z * z));
}

void Vector3::normalise()
{
	float mag = magnitude();
	assert(mag != 0);
	//Divide x, y, and z by the magnitude
	x = x / mag;
	y = y / mag;
	z = z / mag;
}

Vector3 Vector3::unitVector()
{
	float mag = magnitude();
	assert(mag != 0);
	//Divide x, y, and z by the magnitude
	Vector3 newV(x / mag, y / mag, z / mag);
	return newV;
}

float Vector3::scalarRes(Vector3& vDirecOf)
{
	//Find the unit vector in direction of the parameter
	Vector3 vUnitVec = vDirecOf.unitVector();
	//Return the dot product of the vector and parameter unit vector, a*b^
	return dot(vUnitVec);
}

Vector3 Vector3::vectorRes(Vector3& vDirecOf)
{
	//Multiply the parameter unit vector by the scalar resolute, (a*b^)*b^
	return scalarRes(vDirecOf) * vDirecOf.unitVector();
}

Vector3 Vector3::perpRes(Vector3& vDirecOf)
{
	//Subtract the vector resolute from the vector, a-(a*b^)*b^
	Vector3 newV = *this - vectorRes(vDirecOf);
	return newV;
}

float& Vector3::operator[](int nIndex)
{
	switch (nIndex)
	{
	case 0: return x;
	case 1: return y;
	case 2: return z;
	default: assert(0);
	}
}

Vector3::operator float*()
{
	return &x;
}