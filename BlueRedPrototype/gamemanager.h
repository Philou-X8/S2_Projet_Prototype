#pragma once


#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include "maploader.h"
#include "mapgrid.h"

class GameManager
{
public:
	GameManager();

	void gameUpdate(char input);

	/******************** map display ********************/
	void levelReload();
	void levelNext();
	void levelUpdateUI();
	bool levelState();

	/******************** input system ********************/
	//char getInput();
	void inputManager(char input);
	void inputPlayerAction(char input);
	void inputMapAction(char input);
	void inputMenuAction(char input);

private:
	// game related objects
	PlayerPos* p1; // player 1 coords
	PlayerPos* p2; // player 2 coords
	MapLoader mapLoader;
	MapGrid grid;

	/******************** console usage ********************/
	HANDLE consoleHandle;
	PCONSOLE_CURSOR_INFO cursorInfo;
	void consoleXY(int x, int y);
	void consoleHideCursor(bool hide);
};

