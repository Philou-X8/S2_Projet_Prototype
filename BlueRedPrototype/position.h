#pragma once

#define WALL 1
#define PATH 2
#define BOX 3
#define GOAL 4
#define SPAWN1 5
#define SPAWN2 6

const char UP = 'u';
const char DOWN = 'd';
const char RIGHT = 'r';
const char LEFT = 'l';

class PlayerPos
{
public:
	PlayerPos();
	PlayerPos(int xx, int yy);
	PlayerPos(const PlayerPos& p2);
	bool setPos(const int xx, const int yy);
	bool setPos(const PlayerPos& p2);
	bool move(const int dx, const int dy);
	bool move(const PlayerPos& p2);
	bool operator==(const PlayerPos& p2);
	bool operator!=(const PlayerPos& p2);
	PlayerPos& operator=(const PlayerPos& p2);
	PlayerPos& operator=(const PlayerPos* p2);
	PlayerPos& operator+=(const PlayerPos& p2);
	PlayerPos& operator-=(const PlayerPos& p2);
	PlayerPos operator+(const PlayerPos& p2);
	PlayerPos operator-(const PlayerPos& p2);

	int x, y;
};

int clampM(int& val); // clamp a value to the map dimentions
int clampM(const int& val); // clamp a value to the map dimentions

PlayerPos clampP(PlayerPos& pos); // clamp a position to the map dimentions