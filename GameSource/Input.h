#pragma once
#include "Vectors.h"

struct MouseInputData
{
	Vector2 GetScreenPosition();
	bool GetLeftIsDown();
	void SetLeftIsDown(bool value);
	bool GetRightIsDown();
	void SetRightIsDown(bool value);
	void SetScreenCoordinates(short x, short y);
	short GetPixelX();
	short GetPixelY();

private: 
	unsigned short pixelX, pixelY;
	bool leftIsDown;
	bool rightIsDown;
	Vector2 screenPosition;
};