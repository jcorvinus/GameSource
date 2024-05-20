#include "Input.h"
#include "Vectors.h"
#include "Application.h"

#pragma region Mouse Input Stuff
void MouseInputData::SetScreenCoordinates(short x, short y)
{
	screenX = x;
	screenY = y;

	// convert window coordinates to screen coordinates
	// get our backbuffer dimensions?
	Vector2 screenDimensions = Application::instance().GetScreenDimensions();
	int windowWidth = Application::instance().GetWindowWidth();
	int windowHeight = Application::instance().GetWindowHeight();

	//screenX -= (windowWidth - screenDimensions.x);
	//screenY -= (windowHeight - screenDimensions.y);

	// convert screen coordinates into normalized coordinates
	//position.x = screenX / screenDimensions.x;
	//position.y = screenY / screenDimensions.y;

	position.x = 2 * (screenX / (screenDimensions.x - 1)) - 1;
	position.y = (2 * (screenY / (screenDimensions.y - 1)) -1) * -1;
}

short MouseInputData::GetScreenX()
{
	return screenX;
}

short MouseInputData::GetScreenY()
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