#pragma once

#include <windows.h>
#include <tchar.h>

#ifdef bridge // em "Configuration Properties -> C/C++ -> Preprocessor" adicionar: BRIDGE_EXPORTS 
#define BRIDGE_EXPORTS __declspec(dllexport)
#else
#define BRIDGE_EXPORTS __declspec(dllimport)
#endif

extern "C" // usar em C ou C++
{
	//extern BRIDGE_EXPORTS int nDLL;

	BRIDGE_EXPORTS int Teste(void);
	BRIDGE_EXPORTS int UmValor(int v);
	BRIDGE_EXPORTS int patrao();
	BRIDGE_EXPORTS int empregado();
}
