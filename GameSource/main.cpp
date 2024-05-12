#define no_init_all deprecated
#include <iostream>
#include <Windows.h>
#include "Application.h"

int CALLBACK WinMain(HINSTANCE appInstance, HINSTANCE prevInstance, LPSTR comdLine, int cmdCount)
{
	Application::instance().Main();
	return 0;
}