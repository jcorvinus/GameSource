#pragma once
#include "Vectors.h"

struct MouseInputData
{
	Vector2 GetPosition();
	bool GetLeftIsDown();
	void SetLeftIsDown(bool value);
	bool GetRightIsDown();
	void SetRightIsDown(bool value);
	void SetScreenCoordinates(short x, short y);
	short GetScreenX();
	short GetScreenY();

private: 
	unsigned short screenX, screenY;
	bool leftIsDown;
	bool rightIsDown;
	Vector2 position;
};