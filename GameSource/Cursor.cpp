#include "Application.h"
#include "Input.h"
#include "Cursor.h"
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

Cursor::Cursor(Renderer& renderer) : m_renderer{ renderer }
{
	CreateMesh();
	CreateShaders();
}

Cursor::~Cursor()
{
	inputLayout->Release();
}

void Cursor::PreUpdate()
{
	MouseInputData mouseData = Application::instance().GetMouseInputData();
	Vector2 position = mouseData.GetScreenPosition();
	transform->SetPosition(position);

	//cout << "x: " << position.x << " y: " << position.y << endl;
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
	ifstream vsFile("SpriteVertexShader.cso", ios::binary);
	ifstream psFile("SpritePixelShader.cso", ios::binary);

	vector<char> vsData = { istreambuf_iterator<char>(vsFile), istreambuf_iterator<char>() };
	vector<char> psData = { istreambuf_iterator<char>(psFile), istreambuf_iterator<char>() };

	m_renderer.getDevice()->CreateVertexShader(vsData.data(), vsData.size(), nullptr, &vertexShader);
	m_renderer.getDevice()->CreatePixelShader(psData.data(), psData.size(), nullptr, &pixelShader);

	D3D11_INPUT_ELEMENT_DESC layout[] = {
				{ "POSITION", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};

	m_renderer.getDevice()->CreateInputLayout(layout, 2, vsData.data(), vsData.size(), &inputLayout);
}

void Cursor::Draw()
{
	auto deviceContext = m_renderer.getDeviceContext();

	// we should update our vertices here instead of doing it in the shader

	CursorVertex _vertices[6];
	for (int i = 0; i < 6; i++)
	{
		_vertices[i] = vertices[i];
		_vertices[i].position = _vertices[i].position + transform->GetPosition();
	}

	vertexData.pSysMem = _vertices;

	// bind shaders
	deviceContext->IASetInputLayout(inputLayout);
	deviceContext->VSSetShader(vertexShader, nullptr, 0);
	deviceContext->PSSetShader(pixelShader, nullptr, 0);

	// set vertex buffer
	UINT stride = sizeof(CursorVertex);
	UINT offset = 0;

	m_renderer.getDevice()->CreateBuffer(&vertexBufferDesc, &vertexData, &vertexBuffer);

	deviceContext->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset); // IA refers to the first stage in the pipeline

	// draw
	deviceContext->Draw(6, 0);

	// release resources
	vertexBuffer->Release();
	vertexShader->Release();
	pixelShader->Release();
}