#define no_init_all deprecated
#include "Renderer.h"

Renderer::Renderer(Window& window)
{
	createDevice(window);
	createRenderTarget();
}

void Renderer::createDevice(Window& window)
{
	// create our swap chain. A swap chain enables multibuffering. Swapping front and back buffer.
	DXGI_SWAP_CHAIN_DESC swapChainDesc = { 0 };
	swapChainDesc.BufferCount = 1; // 1 buffer is for back buffering
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = window.getHandle();
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.Windowed = true;

	// create the swapchain device, and context
	auto result = D3D11CreateDeviceAndSwapChain(
		nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0,
		nullptr, 0, D3D11_SDK_VERSION,
		&swapChainDesc, &m_pSwapChain,
		&m_pDevice, nullptr, &m_pDeviceContext
	);

	// check for errors
	if (result != S_OK)
	{
		MessageBox(nullptr, "Problem creating dx11", "Error", MB_OK);
		exit(0);
	}
}

void Renderer::createRenderTarget()
{
	ID3D11Texture2D* backBuffer;
	m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer);
	m_pDevice->CreateRenderTargetView(backBuffer, nullptr, &m_renderTargetView);

	backBuffer->GetDesc(&m_backbufferDesc);
	backBuffer->Release(); // it's using reference/instance counting
}

void Renderer::beginFrame()
{
	// bind render target
	m_pDeviceContext->OMSetRenderTargets(1, &m_renderTargetView, nullptr); // depth buffer is null because we're rendering 2d

	// set viewport
	auto viewport = CD3D11_VIEWPORT(0.0f, 0.0f, (float)m_backbufferDesc.Width, (float)m_backbufferDesc.Height);
	m_pDeviceContext->RSSetViewports(1, &viewport); // rs is rasterizer stage

	// set the background color!
	float clearColor[] = { 0, 0, 0, 1 };
	m_pDeviceContext->ClearRenderTargetView(m_renderTargetView, clearColor);
}

void Renderer::endFrame()
{
	// swap the buffer, showing to the viewer
	m_pSwapChain->Present(1, 0);
}

ID3D11Device* Renderer::getDevice()
{
	return m_pDevice;
}

ID3D11DeviceContext* Renderer::getDeviceContext()
{
	return m_pDeviceContext;
}

Vector2 Renderer::GetScreenDimensions()
{
	return Vector2(m_backbufferDesc.Width, m_backbufferDesc.Height);
}