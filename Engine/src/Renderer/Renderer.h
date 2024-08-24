#pragma once
#include "EngineMin.h"
#include <Windows.h>


#include "DirectX12/Base/D12Device.h"

namespace Engine {

	class DX_API Renderer
	{

	public:
		Renderer() = default;
		~Renderer();

		void init(HWND hwnd);


	private:

		D12Device pDevice;
	};
}