#pragma once
#include "Renderer.h"
#include "Entity.h"

struct CursorVertex
{
	Vector2 position;
	float r, g, b;
};

class Cursor : public Entity
{
public: 
	Cursor();
	~Cursor();
	void Init();
	void Draw();

private:
	void CreateMesh();
	void CreateShaders();

	//virtual void Start();
	virtual void PreUpdate();

	bool hasInit = false;
	ID3D11Buffer* vertexBuffer = nullptr;
	ID3D11VertexShader* vertexShader = nullptr;
	ID3D11PixelShader* pixelShader = nullptr;
	ID3D11InputLayout* inputLayout = nullptr;

	const byte vertexCount = 6;
	CursorVertex vertices[6] =
	{
		// left triangle
		{ // upper left vertex
			{ -0.5, 0.5, }, // xy
			0, 0, 1 // rgb
		},
		{ // upper right vertex
			{ 0.5, 0.5 },
			1, 1 , 1 // rgb
		},
		{ // lower left vertex
			{ -0.5 , -0.5 },
			1, 0, 0 // rgb
		},

		// right triangle
		{ // upper right vertex
			{ 0.5, 0.5 },
			1, 1 , 1 // rgb
		},
		{ // lower right vertex
			{0.5, -0.5},
			1, 1, 1 // rgb
		},
		{ // lower left vertex
			{ -0.5 , -0.5 },
			1, 0, 0 // rgb
		}
	};

	CD3D11_BUFFER_DESC vertexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData = { 0 };
};