#pragma once
#include "Vectors.h"

class Transform
{
public:
	Vector2 GetPosition();
	void SetPosition(Vector2 newPosition);

private:
	Vector2 position;
};