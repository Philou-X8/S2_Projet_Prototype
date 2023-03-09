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
	GameManager(int niveaux);
	~GameManager();

	void gameUpdate(char inputKey);

	/******************** map display ********************/
	bool levelState(); 
	void levelReload();
	void levelNext();
	void levelUpdateUI();

	/******************** input system ********************/
	void inputPlayerAction(char input);
	MapLoader mapLoader;

private:
	/******************** game objects ********************/
	Coords* p1; // player 1 coords
	Coords* p2; // player 2 coords

	MapGrid mapGrid;
	
	/******************** display func ********************/
	void showLvlProgress();

	/******************** console usage ********************/
	HANDLE consoleHandle;
	CONSOLE_CURSOR_INFO cursorInfo;
	void consoleXY(int x, int y);
	void consoleHideCursor(bool hide);
};

