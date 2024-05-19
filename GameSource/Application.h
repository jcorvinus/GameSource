#pragma once

#define no_init_all deprecated
//#include <iostream>
#include <Windows.h>
#include <windowsx.h>
#include <memory>
#include "Window.h"
#include "Renderer.h"
#include "Triangle.h"
#include "Vectors.h"
#include "Input.h"
#include "Entity.h"
#include "Cursor.h"

class Application
{
public: 
	static Application &instance() { static Application application; return application; }
	void Main();

	int GetWindowWidth();
	int GetWindowHeight();
	Vector2 GetScreenDimensions();
	MouseInputData GetMouseInputData();

	void AddEntity(std::shared_ptr<Entity> newEntity);
	void RemoveEntity(std::shared_ptr<Entity> removeEntity);

private:
	Window window;
	Renderer renderer;
	Triangle triangle;
	MouseInputData mouseData;
	Cursor* cursor;
	
	bool applicationHasFocus = false;

	std::shared_ptr<Entity> uiEntities[USHRT_MAX];

	Application();
};