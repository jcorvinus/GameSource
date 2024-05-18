#pragma once

struct Vector2
{
	float x, y;

	Vector2()
	{
		x = 0;
		y = 0;
	}

	Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2 operator*(const float scale)
	{
		//this->x *= scale;
		//this->y *= scale;

		return Vector2(x * scale, y * scale);
	}
};