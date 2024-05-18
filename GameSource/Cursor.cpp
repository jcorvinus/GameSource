
#include "Cursor.h"

Cursor::Cursor(Renderer& renderer) : m_renderer{ renderer }
{
	CreateMesh();
	CreateShaders();
}

Cursor::~Cursor()
{

}

void Cursor::CreateMesh()
{
	// scale our vertices
	for (int i = 0; i < vertexCount; i++)
	{
		vertices[i].position = vertices[i].position * 0.1f;
	}

	// create our vertex buffer
	vertexBufferDesc = CD3D11_BUFFER_DESC(sizeof(vertices),
		D3D11_BIND_VERTEX_BUFFER);
	vertexData.pSysMem = vertices;
	m_renderer.getDevice()->CreateBuffer(&vertexBufferDesc, &vertexData, &vertexBuffer);
}

void Cursor::CreateShaders()
{

}

void Cursor::Draw()
{
	auto deviceContext = m_renderer.getDeviceContext();

	// we should update our vertices here instead of doing it in the shader

	CursorVertex _vertices[6];
	for (int i = 0; i < 6; i++)
	{
		_vertices[i] = vertices[i];
		//_vertices[]
	}

	// bind shaders

	// set vertex buffer

	// draw

	// release resources
	vertexBuffer->Release();
	vertexShader->Release();
	pixelShader->Release();
	inputLayout->Release();
}