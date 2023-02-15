/*
*
*   MAKING A GAME PROTOTYPE FOR SCHOOL
*
*/
#pragma once

#include <iostream>
#include <Windows.h>
#include "position.h"

using namespace std;

class MapGrid
{
public:
	MapGrid();
	MapGrid(PlayerPos* p1pos, PlayerPos* p2pos);
	int& getGrid(int x, int y);
	void newGrid(int arr[20][20]);
	void placePlayers(PlayerPos* p1pos, PlayerPos* p2pos);
	int moveP1(PlayerPos dir);
	int moveP2(PlayerPos dir);
	int actionRed(PlayerPos dir);
	int actionBlue(PlayerPos dir);
	bool mapSolved();
	friend ostream& operator <<(ostream& s, MapGrid& grid);

private:
	
	int mapGrid[20][20];
	PlayerPos* p1;
	PlayerPos* p2;
};
