#pragma once
#include "Vectors.h"

struct MouseInputData
{
	Vector2 GetPosition();
	bool GetLeftIsDown();
	void SetLeftIsDown(bool value);
	bool GetRightIsDown();
	void SetRightIsDown(bool value);
	void SetScreenCoordinates(unsigned short x, unsigned short y);
	unsigned short GetScreenX();
	unsigned short GetScreenY();

private: 
	unsigned short screenX, screenY;
	bool leftIsDown;
	bool rightIsDown;
	Vector2 position;
};