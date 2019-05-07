#pragma once

class Vector3
{
public:
	Vector3(float xpos, float ypos, float zpos)
	{
		x = xpos;
		y = ypos;
		z = zpos;
	}

	~Vector3()
	{

	}

private:
	float x;
	float y;
	float z;
};