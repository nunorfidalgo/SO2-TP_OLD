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