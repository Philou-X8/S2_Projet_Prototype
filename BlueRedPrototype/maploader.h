/*
*
*   MAKING A GAME PROTOTYPE FOR SCHOOL
*
*/
#pragma once
#include <iostream>
#include <fstream>
#include "position.h"

using namespace std;

class MapLoader
{
public:
	MapLoader();
	~MapLoader();
	bool loadMap(int (*arr)[20][20], PlayerPos* p1, PlayerPos* p2);

	void blankMap(); // creat a blank map for further editing
private:
	ifstream rFile;
	string filePath;
	int lvlProgress;
};

