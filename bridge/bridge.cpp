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
		* ter ATEN��O x86:
			* "Properties -> Configuration: All Configurations" mudar para: Debug e adicionar:
				$(SolutionDir)Debug\bridge.lib
			* "Properties -> Configuration: All Configurations" mudar para: Release e adicionar:
				$(SolutionDir)Release\bridge.lib
		* ter ATEN��O x64:
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

//#define TAM 80

// Estrutura de dados
//typedef struct {
//	int tamanho;
//	int x;
//	int y;
//} NAVES;
//
//typedef struct {
//	int tamanho;
//	int x;
//	int y;
//} TIROS;
//
//typedef struct {
//	int tamanho;
//	int x;
//	int y;
//} POWERUPS;

BOOL WINAPI DllMain(HANDLE hInstance, DWORD razao, LPVOID tipo_declaracao) {
	switch (razao) {
	case DLL_PROCESS_ATTACH:
		if (tipo_declaracao == NULL)
			_tprintf(TEXT("\nBridge: Ocorreu um erro ao iniciar a DLL!"));
		else
			_tprintf(TEXT("\nBridge: pronto..."));
		break;
	case DLL_PROCESS_DETACH:
		if (tipo_declaracao == NULL)
			_tprintf(TEXT("\nBridge: Ocorreu um erro a terminar a DLL!"));
		else
			_tprintf(TEXT("\nBridge: terminou..."));
		break;
	}
	return TRUE;
}

extern "C" {
int Teste(void) {
	_tprintf(TEXT("\nbridge: texto de teste...\n"));
	return 0;
}

int UmValor(int v) {
	return v;
}

int patrao(){
	_tprintf(TEXT("Patrao: "));
	//HANDLE	hEvent;
	//TCHAR *cmd;

	//HANDLE hFile, hMap;

	//// Abrir ficheiro... (RW)
	//hFile = CreateFile(TEXT("memdados.txt"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	////hMap = CreateFileMapping(INVALID_HANDLE_VALUE, ..., TAM * sizeof(TCHAT));
	////hMap = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, TAM * sizeof(TCHAR), NULL);
	//LARGE_INTEGER t;
	//t.QuadPart = TAM * sizeof(TCHAR);
	//hMap = CreateFileMapping(hFile, NULL, PAGE_READWRITE, t.HighPart, t.LowPart, TEXT("shm"));
	////cmd = (TCHAR *) MapViewOfFile(hMap, FILE_MAP_WRITE, 0, 0, TAM * sizeof(TCHAR));
	//cmd = (TCHAR *)MapViewOfFile(hMap, FILE_MAP_WRITE, 0, 0, (SIZE_T)t.QuadPart);

	//// Event
	//hEvent = CreateEvent(NULL, true, false, TEXT("evento"));
	//if (hEvent == NULL) {
	//	_tprintf(TEXT("CreateEvent error: %d\n"), GetLastError());
	//	return 1;
	//}
	//do {
	//	_tprintf(TEXT("CMD: "));
	//	_fgetts(cmd, TAM, stdin);
	//	cmd[_tcslen(cmd) - 1] = TEXT('\0');
	//	_tprintf(TEXT("Escrevi %d bytes: '%s'\n"), (_tcslen(cmd) + 1), cmd);
	//	SetEvent(hEvent);
	//	ResetEvent(hEvent);
	//} while (_tcsncmp(cmd, TEXT("fim"), 3) != 0);

	//CloseHandle(hEvent);
	//// Fechar ficheiro
	//CloseHandle(hFile);
	//UnmapViewOfFile(cmd);
	//CloseHandle(hMap);

	//_tprintf(TEXT("\nfim"));
	return 0;
}

int empregado() {
	_tprintf(TEXT("Empregado: "));
	//HANDLE	hEvent;
	//TCHAR *cmd;

	//HANDLE hMap;

	//LARGE_INTEGER t;
	//t.QuadPart = TAM * sizeof(TCHAR);

	////hFile = CreateFile(TEXT("dados.txt"), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	//hMap = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READONLY, t.HighPart, t.LowPart, TEXT("shm"));
	//cmd = (TCHAR *)MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, (SIZE_T)t.QuadPart);

	//// Event
	//hEvent = OpenEvent(SYNCHRONIZE, true, TEXT("evento"));
	//if (hEvent == NULL) {
	//	_tprintf(TEXT("CreateSemaphore error: %d\n"), GetLastError());
	//	return 1;
	//}
	//do {
	//	WaitForSingleObject(hEvent, INFINITE);
	//	_tprintf(TEXT("Li '%s' (%d bytes)\n"), cmd, _tcslen(cmd) + 1);

	//} while (_tcsncmp(cmd, TEXT("fim"), 3) != 0);

	//CloseHandle(hEvent);
	//// Fechar ficheiro
	////CloseHandle(hFile);
	//UnmapViewOfFile(cmd);
	//CloseHandle(hMap);
	return 0;
}
}

