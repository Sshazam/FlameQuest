#pragma once
#include "necrogen.h"

bool inFail() {
	if (std::cin.good()) {
		return false;
	}
	else {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		return true;
	}
}
void coutOps(std::vector<std::string> ops, int& tot) {
	std::vector<std::string>::iterator itr;
	tot = 0;
	for (itr = ops.begin(); itr != ops.end(); itr++) {
		tot++;
		std::cout << tot << ". " << *itr << std::endl;
	}
}
void clrscr() {
	HANDLE hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD count;
	DWORD cellCount;
	COORD homeCoords = { 0,0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;
	if (!FillConsoleOutputCharacter(hStdOut, (TCHAR)' ', cellCount, homeCoords, &count)) return;
	SetConsoleCursorPosition(hStdOut, homeCoords);
}