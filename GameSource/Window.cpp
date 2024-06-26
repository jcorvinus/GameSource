#define no_init_all deprecated
#include <Windows.h>
#include "Window.h"

LRESULT CALLBACK WinProc(HWND handle, UINT msg, WPARAM wparam, LPARAM lparam)
{
	if (msg == WM_DESTROY ||
		msg == WM_CLOSE)
	{
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(handle, msg, wparam, lparam);
}

Window::Window(int width, int height)
{
	this->width = width;
	this->height = height;

	// define window style
	WNDCLASS wc = { 0 };
	wc.style = CS_OWNDC; // this tells the device context cache that we want our device context to be persistent
	wc.lpfnWndProc = WinProc; // subscribing to an update event
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.lpszClassName = "DX11Game";
	RegisterClass(&wc);

	// create the window
	m_handle = CreateWindow("DX11Game", "Game",
		WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_VISIBLE,
		100, 100, width, height,
		nullptr, nullptr, nullptr, nullptr);
}

HWND Window::getHandle()
{
	return m_handle;
}

int Window::GetWidth()
{
	return width;
}

int Window::GetHeight()
{
	return height;
}