/*
* Criar um projecto vazio
* Projecto: "Properties -> Configuration: All Configurations" e "Platform: All Platforms" mudar:
	* "Configuration Properties->General":
		* Character Set: Use Unicode Character Set
		* em "Configuration Properties -> C/C++ -> Preprocessor" adicionar:
			WIN32
			_DEBUG
			_CONSOLE
	* "Configuration Properties -> Linker -> Input -> Addicional Dependencies" adicionar:
		* ter ATENÇÃO x86:
			* "Properties -> Configuration: All Configurations" mudar para: Debug e adicionar:
				$(SolutionDir)Debug\bridge.lib
			* "Properties -> Configuration: All Configurations" mudar para: Release e adicionar:
				$(SolutionDir)Release\bridge.lib
		* ter ATENÇÃO x64:
			* "Properties -> Configuration: All Configurations" mudar para: Debug e adicionar:
				$(SolutionDir)x64\Debug\bridge.lib
			* "Properties -> Configuration: All Configurations" mudar para: Release e adicionar:
				$(SolutionDir)x64\Release\bridge.lib
*/

#include <windows.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>

#include "gateway.h"

// #include "DLL.h"
#include "../bridge/bridge.h" // Adicionar o ficheiro .lib aoa Linker, ver comentarios inciais

int _tmain(int argc, TCHAR *argv[]) {

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif
	_tprintf(TEXT("\nGateway: pronto..."));

	_tprintf(TEXT("\nGateway: TESTE1..."));

	//Chamar a funcao da Dll
	Teste();
	_tprintf(TEXT("\nGateway: TESTE2..."));
	_tprintf(TEXT("\nValor: %d"), UmValor(120));

	_tprintf(TEXT("\nGateway: terminou...\n"));
	return 0;
}