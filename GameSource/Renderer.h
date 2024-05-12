#pragma once
#include "Window.h"
#include <d3d11.h>

class Renderer
{
public:
	Renderer(Window& window);
	void beginFrame();
	void endFrame();
	ID3D11Device* getDevice();
	ID3D11DeviceContext* getDeviceContext();

private:
	void createDevice(Window& window);
	void createRenderTarget();

	// device stuff
	IDXGISwapChain* m_pSwapChain = nullptr;
	ID3D11Device* m_pDevice = nullptr;
	ID3D11DeviceContext* m_pDeviceContext = nullptr;

	// render target
	ID3D11RenderTargetView* m_renderTargetView = nullptr; // view is 2 components, one is the texture, one is the output?? lok into this more
	D3D11_TEXTURE2D_DESC m_backbufferDesc;
};