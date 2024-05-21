#pragma once
#include "Renderer.h"

class Triangle
{
public:
	Triangle();
	~Triangle();
	void draw();

	void Init();

private:
	void createMesh();
	void createShaders();

	bool hasInit = false;

	ID3D11Buffer* m_vertexBuffer = nullptr;
	ID3D11VertexShader* m_vertexShader = nullptr;
	ID3D11PixelShader* m_pixelShader = nullptr;
	ID3D11InputLayout* m_inputLayout = nullptr;
};