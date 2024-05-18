#pragma once
#include "Renderer.h"
#include "Entity.h"

struct CursorVertex
{
	Vector2 position;
	float r, g, b;
};

class Cursor
{
public: 
	Cursor(Renderer& renderer);
	~Cursor();
	void Draw();

private:
	void CreateMesh();
	void CreateShaders();

	Renderer& m_renderer;
	ID3D11Buffer* vertexBuffer = nullptr;
	ID3D11VertexShader* vertexShader = nullptr;
	ID3D11PixelShader* pixelShader = nullptr;
	ID3D11InputLayout* inputLayout = nullptr;

	const byte vertexCount = 6;
	CursorVertex vertices[6] =
	{
		// left triangle
		{ // lower left vertex
			{ 0, -1, }, // xy
			1, 1, 1 // rgb
		},
		{ // upper left vertex
			{ 0 , 1 },
			1, 1, 1 // rgb
		},
		{ // lower right vertex
			{ -1, 1 },
			1, 1 , 1 // rgb
		},

		// right triangle
		{ // lower right vertex
			{ -1, 1 },
			1, 1, 1 // rgb
		},
		{ // upper left vertex
			{0, 1},
			1, 1, 1 // rgb
		},
		{ // upper right vertex
			{1, 1},
			1, 1, 1
		}
	};

	CD3D11_BUFFER_DESC vertexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData = { 0 };
};