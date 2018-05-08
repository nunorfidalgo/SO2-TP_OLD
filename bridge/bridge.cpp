/*
* Criar um projecto vazio
* Projecto: "Properties -> Configuration: All Configurations" e "Platform: All Platforms" mudar:
	* "Configuration Properties->General":
		* Configuration Type: Dynamic Library (.dll)
		* Character Set: Use Unicode Character Set
	* "Configuration Properties -> C/C++ -> Preprocessor" adicionar:
			WIN32
			_DEBUG
			_CONSOLE
			BRIDGE_EXPORTS
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



Este DLL interliga o GATEWAY com o Servidor
Memoria partilhada
* Zona de mensagens
* Zona de dados do jogo
*/

#include <windows.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>

#include "bridge.h" //DLL.h"

// Estrutura de dados
typedef struct {
	int tamanho;
	int x;
	int y;
} NAVES;

typedef struct {
	int tamanho;
	int x;
	int y;
} TIROS;

typedef struct {
	int tamanho;
	int x;
	int y;
} POWERUPS;

int Teste(void) {
	_tprintf(TEXT("\nbridge: texto de teste...\n"));
	return 0;
}

int UmValor(int v) {
	return v;
}

BOOL WINAPI DllMain(HANDLE hInstance, DWORD razao, LPVOID tipo_declaracao) {
	switch (razao) {
	case DLL_PROCESS_ATTACH:
		if (tipo_declaracao == NULL)
			_tprintf(TEXT("\Bridge: Ocorreu um erro ao iniciar a DLL!"));
		else
			_tprintf(TEXT("Bridge: pronto..."));
		break;
	case DLL_PROCESS_DETACH:
		if (tipo_declaracao == NULL)
			_tprintf(TEXT("Bridge: Ocorreu um erro a terminar!"));
		else
			_tprintf(TEXT("Bridge: terminou..."));
		break;
	}
	return 1;
}