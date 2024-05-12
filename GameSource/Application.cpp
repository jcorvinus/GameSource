#include "Application.h"
Application::Application() : window(800,600), renderer(window), triangle(renderer)
{

}

void Application::Main()
{
	MSG msg = { 0 };
	while (true)
	{
		// process messages
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			bool shouldExit = false;

			USHORT xPos, yPos;

			switch (msg.message)
			{
			case(WM_QUIT):
				shouldExit = true;
				break;

			case(WM_SETFOCUS):
				applicationHasFocus = true;
				//std::cout << "Application gained focus!";
				break;

			case(WM_KILLFOCUS):
				applicationHasFocus = false;
				//std::cout << "Application lost focus!";
				break;

			case(WM_MOUSEMOVE):
				xPos = GET_X_LPARAM(msg.lParam);
				yPos = GET_Y_LPARAM(msg.lParam);
				mouseData.SetScreenCoordinates(xPos, yPos);
				break;

			default:
				break;
			}

			if (shouldExit) break;
		}

		// main loop

		// update

		// draw
		renderer.beginFrame();

		// render everything here
		triangle.draw(renderer);

		renderer.endFrame();

	}
}

int Application::GetWindowWidth()
{
	return window.GetWidth();
}

int Application::GetWindowHeight()
{
	return window.GetHeight();
}

Vector2 Application::GetScreenDimensions()
{
	return renderer.GetScreenDimensions();
}