#include "Input.h"
#include "Vectors.h"

#pragma region Mouse Input Stuff
void MouseInputData::SetScreenCoordinates(unsigned short x, unsigned short y)
{
	screenX = x;
	screenY = y;

	// convert window coordinates to screen coordinates

	// convert screen coordinates into normalized coordinates
}

unsigned short MouseInputData::GetScreenX()
{
	return screenX;
}

unsigned short MouseInputData::GetScreenY()
{
	return screenY;
}

Vector2 MouseInputData::GetPosition()
{
	return position;
}

bool MouseInputData::GetLeftIsDown()
{
	return leftIsDown;
}

void MouseInputData::SetLeftIsDown(bool value)
{
	leftIsDown = value;
}

bool MouseInputData::GetRightIsDown()
{
	return rightIsDown;
}

void MouseInputData::SetRightIsDown(bool value)
{
	rightIsDown = value;
}
#pragma endregion Mouse Input Stuff