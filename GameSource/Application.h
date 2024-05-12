#pragma once

#define no_init_all deprecated
//#include <iostream>
#include <Windows.h>
#include <windowsx.h>
#include "Window.h"
#include "Renderer.h"
#include "Triangle.h"
#include "Vectors.h"
#include "Input.h"

class Application
{
public: 
	static Application &instance() { static Application application; return application; }
	void Main();

private:
	Window window;
	Renderer renderer;
	Triangle triangle;
	MouseInputData mouseData;
	bool applicationHasFocus = false;

	Application();
};