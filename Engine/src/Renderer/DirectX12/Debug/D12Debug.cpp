#include "pch.h"
#include "D12Debug.h"


namespace Engine {
	D12Debug D12Debug::pInstance;
	void D12Debug::Enable()
	{
		getInterface();
		Get()->EnableDebugLayer();
	}
	void D12Debug::getInterface()
	{
		if (!Get()) {
			DX_EVAL_HR(D3D12GetDebugInterface(IID_PPV_ARGS(GetAddressOf())), "Error getting debug interface");
		}
	}
}