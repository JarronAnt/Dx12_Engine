#include "pch.h"
#include "DXGIDebug.h"

namespace Engine {
	DXGIDebug DXGIDebug::pInstance;

	 
	void DXGIDebug::Enable()
	{
		getInterface();
		
	}
	void DXGIDebug::getLiveObjects()
	{
		getInterface();
		Get()->ReportLiveObjects(DXGI_DEBUG_ALL, (DXGI_DEBUG_RLO_FLAGS)(DXGI_DEBUG_RLO_DETAIL | DXGI_DEBUG_RLO_IGNORE_INTERNAL));
	}
	void DXGIDebug::getInterface()
	{
		if (!Get()) {
			DX_EVAL_HR(DXGIGetDebugInterface1(0,IID_PPV_ARGS(GetAddressOf())), "Error getting dxgi debug interface");
		}
	}
}