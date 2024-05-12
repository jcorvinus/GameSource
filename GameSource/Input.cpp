#include "Input.h"
#include "Vectors.h"
#include "Application.h"

#pragma region Mouse Input Stuff
void MouseInputData::SetScreenCoordinates(unsigned short x, unsigned short y)
{
	screenX = x;
	screenY = y;

	// convert window coordinates to screen coordinates
	// get our backbuffer dimensions?
	Vector2 screenDimensions = Application::instance().GetScreenDimensions();
	int windowWidth = Application::instance().GetWindowWidth();
	int windowHeight = Application::instance().GetWindowHeight();

	screenX -= (windowWidth - screenDimensions.x);
	screenY -= (windowHeight - screenDimensions.y);	

	// convert screen coordinates into normalized coordinates
	position.x = screenDimensions.x / screenX;
	position.y = screenDimensions.y / screenY;
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