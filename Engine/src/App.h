#pragma once

#include "EngineMin.h"
#include <Windows.h>

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
	};
}
