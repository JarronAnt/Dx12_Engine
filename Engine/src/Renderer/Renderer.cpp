#include "pch.h"
#include "Renderer.h"

#include "DirectX12/DXGI/DXGIFactory.h"
#include "DirectX12/DXGI/DXGIAdapter.h"

#include "DirectX12/Debug/D12Debug.h"


namespace Engine {

	Renderer::~Renderer()
	{
		if (pDevice.Get()) {

			pDevice.Reset();

		}
	}

	void Renderer::init(HWND hwnd)
	{

		D12Debug::Get().Enable();

		//initalize the adapter as our d12 device 
		DXGIFactory factory;
		DXGIAdapter adapter = factory.GetAdapter();

		DXGI_ADAPTER_DESC desc;
		adapter->GetDesc(&desc);


		PRINT_W_N("Selected device " << desc.Description);

		pDevice.Init(adapter.Get());

		pDevice->SetName(L"Main virtual device");

	}

}