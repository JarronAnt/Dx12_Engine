#include "pch.h"
#include "App.h"
#include <stdio.h>
#include <windowsx.h>

namespace Engine {

	LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {

		switch (msg) {
		case WM_NCCREATE: {
			printf("TEST");
			break;
		}
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
		}

		return DefWindowProc(hwnd, msg, wparam, lparam);
	}
	
	bool App::init()
	{
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

		//Create the window...return to Lparam later
		pWindowHandle = CreateWindow(L"GeneralWindowClass", L"Dx12_EngineWindow", WS_OVERLAPPEDWINDOW, 200, 200, 1280, 720, 0, 0, 0, this);

		if (!pWindowHandle) {
			return false;
		}

		ShowWindow(pWindowHandle, SW_SHOW);
		UpdateWindow(pWindowHandle);

		//is running flag
		pIsRunning = true;
		return pIsRunning;
	}

	void App::update()
	{
	}

}
