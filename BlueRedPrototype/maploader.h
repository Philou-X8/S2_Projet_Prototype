/*
*
*   MAKING A GAME PROTOTYPE FOR SCHOOL
*
*/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "position.h"

using namespace std;

class MapLoader
{
public:
	MapLoader();
	~MapLoader();
	bool resetLvl(int(*arr)[20][20], PlayerPos* p1, PlayerPos* p2);
	bool nextLvl(int(*arr)[20][20], PlayerPos* p1, PlayerPos* p2);
	bool loadMap(int (*arr)[20][20], PlayerPos* p1, PlayerPos* p2);

	void blankMap(); // creat a blank map for manual editing
private:
	ifstream rFile;
	string lvlPathName;
	int lvlProgress;
	string lvlExtension;
};

