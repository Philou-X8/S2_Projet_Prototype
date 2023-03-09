/*
*
*   MAKING A GAME PROTOTYPE FOR SCHOOL
*
*/
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <mmsystem.h>
#include "maploader.h"
#include "mapgrid.h"
#include "gamemanager.h"
#include "menu.h"

#pragma comment(lib, "Winmm.lib")

using namespace std;

/*
void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void ShowCursor(bool show) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = show;
	SetConsoleCursorInfo(out, &cursorInfo);
}
*/

void main() {

	MENU menu;
	menu.menu();



}