#include "Application.h"
#include "Triangle.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

struct TriangleVertex
{
	float x, y;
	float r, g, b;
};

Triangle::Triangle()
{

}

Triangle::~Triangle()
{
	m_vertexBuffer->Release();
	m_vertexShader->Release();
	m_pixelShader->Release();
	m_inputLayout->Release();
}

void Triangle::draw()
{
	ID3D11DeviceContext* deviceContext = Application::instance().Renderer()->getDeviceContext();

	// bind shaders
	deviceContext->IASetInputLayout(m_inputLayout);
	deviceContext->VSSetShader(m_vertexShader, nullptr, 0);
	deviceContext->PSSetShader(m_pixelShader, nullptr, 0);

	// bind our vertex buffer
	UINT stride = sizeof(TriangleVertex);
	UINT offset = 0;

	deviceContext->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset); // IA refers to the first stage in the pipeline
	deviceContext->Draw(3, 0);
}

void Triangle::createMesh()
{
	// define our vertices
	TriangleVertex vertices[] = {
		{ -0.1, -0.1, 
		1, 0, 0 }, // red

		{ 0, 0.1,
		0, 1, 0 }, // green

		{ 0.1, -0.1, 
		0, 0, 1 } // blue
	};

	// create our vertex buffer
	auto vertexBufferDesc = CD3D11_BUFFER_DESC(sizeof(vertices),
		D3D11_BIND_VERTEX_BUFFER);

	D3D11_SUBRESOURCE_DATA vertexData = { 0 };
	vertexData.pSysMem = vertices;

	Application::instance().Renderer()->getDevice()->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer); // normally you'd do error checks here
}

void Triangle::createShaders()
{
	// create shaders
	ifstream vsFile("TriangleVertexShader.cso", ios::binary); //if is input file. output = ofstream
	ifstream psFile("TrianglePixelShader.cso", ios::binary);

	vector<char> vsData = { istreambuf_iterator<char>(vsFile), istreambuf_iterator<char>() };
	vector<char> psData = { istreambuf_iterator<char>(psFile), istreambuf_iterator<char>() };

	Application::instance().Renderer()->getDevice()->CreateVertexShader(vsData.data(), vsData.size(), nullptr, &m_vertexShader);
	Application::instance().Renderer()->getDevice()->CreatePixelShader(psData.data(), psData.size(), nullptr, &m_pixelShader);

	// create input layouts
	D3D11_INPUT_ELEMENT_DESC layout[] = {
		{ "POSITION", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};

	Application::instance().Renderer()->getDevice()->CreateInputLayout(layout, 2, vsData.data(), vsData.size(), &m_inputLayout);
}

void Triangle::Init()
{
	if (hasInit)
	{
		cout << "Can't initialize Triangle class more than once! Exiting!" << endl;
		exit(2);
	}
	else
	{
		createMesh();
		createShaders();
		hasInit = true;
	}
}