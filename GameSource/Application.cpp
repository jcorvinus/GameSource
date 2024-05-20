#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Application.h"

Application::Application() : window(800,600), renderer(window), triangle(renderer)
{
	AllocConsole();

	FILE* original_stdin = stdin;
	FILE* original_stdout = stdout;
	FILE* original_stderr = stderr;

	if (freopen_s(&original_stdin, "conin$", "r", original_stdin) ||
		freopen_s(&original_stdout, "conout$", "w", original_stdout) ||
		freopen_s(&original_stderr, "conout$", "w", original_stderr))
	{
		// handle the error, as the allocation failed
		exit(1);
	}

	printf("Debugging Window:\n");
}

void Application::Main()
{
	Cursor newCursor = Cursor(renderer);
	cursor = &newCursor;

	MSG msg = { 0 };

	clock_t previousTicks;
	float previousTime=0;
	
	while (true)
	{
		clock_t currentTimeTicks = clock();
		clock_t cps = CLOCKS_PER_SEC;

		time = (float)currentTimeTicks / (float)cps;
		deltaTime = time - previousTime;
		//std::cout << "dt: " << deltaTime << std::endl;

		// process messages
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			bool shouldExit = false;

			short xPos, yPos;

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

		// --  main loop --

		// update
		cursor->Update();

		// draw
		renderer.beginFrame();

		// render everything here
		triangle.draw(renderer);
		cursor->Draw();

		renderer.endFrame();

		// -- end main loop --
		previousTicks = currentTimeTicks;
		previousTime = time;
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

MouseInputData Application::GetMouseInputData()
{
	return mouseData;
}

float Application::Time()
{
	return time;
}

float Application::DeltaTime()
{
	return deltaTime;
}