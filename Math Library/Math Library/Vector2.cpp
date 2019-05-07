#include <iostream>
#include "Vector2.h"

Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(float xpos, float ypos)
{
	x = xpos;
	y = ypos;
}

Vector2::~Vector2()
{
}

//Vector2::Vector2(Vector2& originalVector)
//{
//	x = originalVector.x;
//	y = originalVector.y;
//}


Vector2 Vector2::operator+(const Vector2& vToAdd)
{
	float newx = x + vToAdd.x;
	float newy = y + vToAdd.y;
	Vector2 newV(newx, newy);
	return newV;
}

void Vector2::operator+=(const Vector2& vToAdd)
{
	x = x + vToAdd.x;
	y = y + vToAdd.y;
}

Vector2 Vector2::operator-(const Vector2& vToSub)
{
	float newx = x - vToSub.x;
	float newy = y - vToSub.y;
	Vector2 newV(newx, newy);
	return newV;
}

void Vector2::operator-=(const Vector2& vToSub)
{
	x = x - vToSub.x;
	y = y - vToSub.y;
}

Vector2 Vector2::operator*(const float fScalar)
{
	float newx = x * fScalar;
	float newy = y * fScalar;
	Vector2 newV(newx, newy);
	return newV;
}

Vector2 operator*(const float& fScalar, const Vector2& vector)
{
	float newx = vector.x * fScalar;
	float newy = vector.y * fScalar;
	Vector2 newV(newx, newy);
	return newV;
}

void Vector2::operator*=(const float fScalar)
{
	x = x * fScalar;
	y = y * fScalar;
}

Vector2 Vector2::operator/(const float fScalar)
{
	float newx = x / fScalar;
	float newy = y / fScalar;
	Vector2 newV(newx, newy);
	return newV;
}

void Vector2::operator/=(const float fScalar)
{
	x = x / fScalar;
	y = y / fScalar;
}

float Vector2::dot(const Vector2& vToDot)
{
	float newx = x * vToDot.x;
	float newy = y * vToDot.y;
	return newx + newy;
}

float Vector2::magnitude()
{
	return sqrt((x * x) + (y * y));
}

Vector2 Vector2::normalise()
{
	float newx = x / magnitude();
	float newy = y / magnitude();
	Vector2 newV(newx, newy);
	return newV;
}

float Vector2::scalarRes(const Vector2& vDirecOf)
{
	float newx = x * vDirecOf.normalise();
}

float Vector2::operator[](int nIndex)
{
	switch (nIndex)
	{
	case 0: return x;
	case 1: return y;
	default: assert(0);
	}
}