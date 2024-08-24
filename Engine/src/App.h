#pragma once

#include "EngineMin.h"
#include <Windows.h>
#include "Renderer/Renderer.h"

namespace Engine {
	class DX_API App
	{
	public:
		App() = default;
		
		bool init();
		inline bool isRunning() { return pIsRunning; }
		void update();

		void OnCreate(HWND hwnd);
		void OnDestroy();

	private:
		bool pIsRunning = false;
		HWND pWindowHandle = nullptr;
		Renderer pRenderer;
	};
}
