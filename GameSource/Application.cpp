#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Application.h"

Application::Application() : window(800,600), triangle(),
	deltaTime(0), time(0)
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

Renderer* Application::Renderer()
{
	return &renderer;
}

void Application::Main()
{
	renderer.Init(window);

	Cursor newCursor = Cursor();
	cursor = &newCursor;
	newCursor.Init();
	//triangle.Init();

	MSG msg = { 0 };

	clock_t previousTicks;
	float previousTime=0;
	
	while (true)
	{
		// todo: fix your timestep (https://gafferongames.com/post/fix_your_timestep/)
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
		//triangle.draw();
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

void Application::AddEntity(std::shared_ptr<Entity> newEntity)
{
	std::cout << "AddEntity not yet implemented!" << std::endl;
}

void Application::RemoveEntity(std::shared_ptr<Entity> removeEntity)
{
	std::cout << "RemoveEnitty not yet implemented!" << std::endl;
}