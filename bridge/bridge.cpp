/*
* Criar projecto vazio
* em "Propriedades->Confifuration Propresties->General" mudar:
	* Configuration Type: Dynamic Library (.dll)
	* Character Set: Use Unicode Character Set
* em "Propriedades->Confifuration Propresties -> C/C++ -> Preprocessor" adicionar:
WIN32
_DEBUG
_CONSOLE
*/

/*
Este DLL interliga o GATEWAY com o Servidor
Memoria partilhada
* Zona de mensagens
* Zona de dados do jogo
*/

#include <windows.h>
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
			_tprintf(TEXT("\n1"));
		else
			_tprintf(TEXT("Bridge: pronta..."));
		break;
	case DLL_PROCESS_DETACH:
		if (tipo_declaracao == NULL)
			_tprintf(TEXT("\n3"));
		else
			_tprintf(TEXT("Bridge: terminou..."));
		break;
	}
	return 1;
}