/*
* Criar projecto vazio
* em "Propriedades->Confifuration Propresties->General" mudar:
* Character Set: Use Unicode Character Set
* em "Propriedades->Confifuration Propresties -> C/C++ -> Preprocessor" adicionar:
WIN32
_DEBUG
_CONSOLE
* em "Propriedades->Confifuration Propresties -> Linker -> Input -> Addicional Dependencies" adicionar:
../Debug/bridge.lib
*/

#include <windows.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>

#include "cliente.h"

// #include "DLL.h"
#include "../bridge/bridge.h" // adicionar ao linker: ../Debug/bridge.lib

int _tmain(int argc, TCHAR *argv[]) {

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif
	_tprintf(TEXT("\nCliente: pronto..."));

	//Chamar a funcao da Dll
	Teste();
	_tprintf(TEXT("\Valor: %d"), UmValor(30));

	_tprintf(TEXT("\nCliente: terminou...\n"));
	return 0;
}