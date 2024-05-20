#include "Input.h"
#include "Vectors.h"
#include "Application.h"

#pragma region Mouse Input Stuff
void MouseInputData::SetScreenCoordinates(short x, short y)
{
	pixelX = x;
	pixelY = y;

	// convert window coordinates to screen coordinates
	// get our backbuffer dimensions?
	Vector2 screenDimensions = Application::instance().GetScreenDimensions();
	int windowWidth = Application::instance().GetWindowWidth();
	int windowHeight = Application::instance().GetWindowHeight();

	//screenX -= (windowWidth - screenDimensions.x);
	//screenY -= (windowHeight - screenDimensions.y);

	screenPosition.x = 2 * (pixelX / (screenDimensions.x - 1)) - 1;
	screenPosition.y = (2 * (pixelY / (screenDimensions.y - 1)) -1) * -1;
}

short MouseInputData::GetPixelX()
{
	return pixelX;
}

short MouseInputData::GetPixelY()
{
	return pixelY;
}

Vector2 MouseInputData::GetScreenPosition()
{
	return screenPosition;
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