#pragma once

#include <windows.h>
#include <tchar.h>

#ifdef BRIDGE_EXPORTS // em "Configuration Properties -> C/C++ -> Preprocessor" adicionar: BRIDGE_EXPORTS 
#define BRIDGE_API __declspec(dllexport)
#else
#define BRIDGE_API __declspec(dllimport)
#endif

extern "C" // usar em C ou C++
{
	extern BRIDGE_API int nDLL;

	BRIDGE_API int Teste(void);
	BRIDGE_API int UmValor(int v);
}
