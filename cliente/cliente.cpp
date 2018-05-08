/*
* Criar um projecto vazio
* Projecto: "Properties -> Configuration: All Configurations" e "Platform: All Platforms" mudar:
	* "Configuration Properties->General" 
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

#include "cliente.h"


int _tmain(int argc, TCHAR *argv[]) {

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif
	system("cls");
	_tprintf(TEXT("\nCliente: pronto..."));

	_tprintf(TEXT("\nestado inicial - carregue numa tecla..."));
	_gettch();

	_tprintf(TEXT("\nCliente: terminou...\n"));
	return 0;
}