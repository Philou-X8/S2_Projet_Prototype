#pragma once


#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include "maploader.h"
#include "mapgrid.h"
#include "inputmanager.h"

class GameManager
{
public:
	GameManager(InputManager *inManager);
	GameManager(int niveaux, InputManager* inManager);
	~GameManager();

	void gameUpdate(char inputKey);

	/******************** map display ********************/
	bool levelState();
	void levelSet(int lvl);
	void levelReload();
	void levelNext();
	void levelUpdateUI();


private:
	/******************** game objects ********************/
	Coords* p1; // player 1 coords
	Coords* p2; // player 2 coords

	MapGrid mapGrid;
	MapLoader mapLoader;

	/******************** input system ********************/
	InputManager* inputManager;
	void inputPlayerAction(char input);
	
	/******************** display func ********************/
	void showLvlProgress();

	/******************** console usage ********************/
	HANDLE consoleHandle;
	CONSOLE_CURSOR_INFO cursorInfo;
	void consoleXY(int x, int y);
	void consoleHideCursor(bool hide);

};

