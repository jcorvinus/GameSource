#pragma once
#include <Windows.h>

class Window 
{
public:
	Window(int width, int height);
	HWND getHandle();

	int GetWidth();
	int GetHeight();

private:
	HWND m_handle;
	int width, height;
};