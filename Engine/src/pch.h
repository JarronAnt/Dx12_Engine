// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

#include <iostream>

//DirectX headers:
#include <d3d12.h>
#include <dxgi1_6.h>
#include <dxgidebug.h>

//compiled lib files for d12

#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "D3D12.lib")
#pragma comment(lib, "dxguid.lib")


#include "EngineMin.h"
#include "Helpers.h"

#endif //PCH_H
