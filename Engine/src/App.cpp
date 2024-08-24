#include "pch.h"
#include "App.h"
#include <iostream>
#include <windowsx.h>

#include "Renderer/DirectX12/Debug/DXGIDebug.h"


namespace Engine {

	//callback to execute windows msgs (Win32 API stuff)
	LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {

		switch (msg) {
		case WM_NCCREATE: {
			LPCREATESTRUCT param = reinterpret_cast<LPCREATESTRUCT>(lparam);
			App* pointer = reinterpret_cast<App*>(param->lpCreateParams);
			SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pointer));
			std::cout << "Sent create message" << std::endl;
			break;
		}
		case WM_CREATE: {
			App* pointer = reinterpret_cast<App*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
			pointer->OnCreate(hwnd);
			break;
		}
		case WM_DESTROY: {
			App* pointer = reinterpret_cast<App*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
			pointer->OnDestroy();
			PostQuitMessage(0);
			break;
		}
			
		}
		return DefWindowProc(hwnd, msg, wparam, lparam);
	}
	bool App::init()
	{
		//setup window class
		WNDCLASS wndClass = {};
		wndClass.lpszClassName = L"GeneralWindowClass";
		wndClass.style = 0;
		wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wndClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
		wndClass.lpszMenuName = 0;
		wndClass.hInstance = 0;
		wndClass.lpfnWndProc = WndProc;
		wndClass.cbClsExtra = 0;
		wndClass.cbWndExtra = 0;

		RegisterClass(&wndClass);

		//Create the window
		pWindowHandle = CreateWindow(L"GeneralWindowClass", L"Dx12_EngineWindow", WS_OVERLAPPEDWINDOW, 200, 200, 1280, 720, 0, 0, 0, this);

		if (!pWindowHandle) {
			return false;
		}

		//show and update window
		ShowWindow(pWindowHandle, SW_SHOWDEFAULT);
		UpdateWindow(pWindowHandle);

		//is running flag
		pIsRunning = true;
		return pIsRunning;
	}

	void App::update()
	{
		MSG message;
		//handle msgs
		while (PeekMessage(&message, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&message);
			DispatchMessage(&message);

		}
	}

	void App::OnCreate(HWND hwnd)
	{
		//create the renderer 
		std::cout << "Created the actual window" << std::endl;
		pRenderer.init(hwnd);
	}

	void App::OnDestroy()
	{
		std::cout << "Closed the window - shutting down application" << std::endl;
		DXGIDebug::Get().getLiveObjects();
		pIsRunning = false;
	}

}
