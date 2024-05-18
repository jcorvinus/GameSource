#pragma once
#include "Vectors.h"
#include "Updateable.h"

class Transform : public Updateable
{
public:
	Vector2 GetPosition();
	void SetPosition(Vector2 newPosition);

private:
	Vector2 position;
};