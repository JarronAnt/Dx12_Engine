#pragma once


#ifdef ENGINE_EXPORTS

#define DX_API __declspec(dllexport)

#else 

#define DX_API __declspec(dllimport)

#endif 
