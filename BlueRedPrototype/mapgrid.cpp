#include "mapgrid.h"

MapGrid::MapGrid() {
	for (int i(0); i < 20; i++) {
		for (int j(0); j < 20; j++) {
			mapGrid[i][j] = 0;
		}
	}
	p1 = new PlayerPos();
	p2 = new PlayerPos();
	goalP1 = false;
	goalP2 = false;
}
MapGrid::MapGrid(PlayerPos* p1pos, PlayerPos* p2pos) {
	for (int i(0); i < 20; i++) {
		for (int j(0); j < 20; j++) {
			mapGrid[i][j] = 0;
		}
	}
	p1 = p1pos;
	p2 = p2pos;
	goalP1 = false;
	goalP2 = false;
}

int& MapGrid::getGrid(int x, int y) {
	return mapGrid[x][y];
}

void MapGrid::newGrid(int arr[20][20]) {
	for (int i(0); i < 20; i++) {
		for (int j(0); j < 20; j++) {
			mapGrid[i][j] = arr[i][j];
		}
	}
	goalP1 = false;
	goalP2 = false;
}

void MapGrid::placePlayers(PlayerPos* p1pos, PlayerPos* p2pos) {
	p1 = p1pos;
	p2 = p2pos;
}

int MapGrid::moveP1(PlayerPos dir) {
	goalP1 = false;
	PlayerPos newPos(*p1 + dir);
	switch (mapGrid[newPos.x][newPos.y]) {
	case WALL:
		return 0;
	case SPAWN1:
	case SPAWN2:
	case PATH:
		*p1 += dir;
		return 1;
	case BOX:
		return actionRed(dir);
	case GOAL:
		*p1 += dir;
		goalP1 = true;
		return 2;
	}
	return 1;
}
int MapGrid::moveP2(PlayerPos dir) {
	goalP2 = false;
	PlayerPos newPos(*p2 + dir);
	switch (mapGrid[newPos.x][newPos.y]) {
	case WALL:
		return 0;
	case SPAWN1:
	case SPAWN2:
	case PATH:
		*p2 += dir;
		return 1;
	case BOX:
		return actionBlue(dir);
	case GOAL:
		*p2 += dir;
		goalP2 = true;
		return 2;
	}
	return 1;
}

int MapGrid::actionRed(PlayerPos dir) {
	PlayerPos posBox(*p1 + dir);
	PlayerPos posBehindBox(posBox + dir);
	if (mapGrid[posBehindBox.x][posBehindBox.y] == PATH) {
		mapGrid[posBehindBox.x][posBehindBox.y] = BOX;
		mapGrid[posBox.x][posBox.y] = PATH;
		*p1 += dir;
		return 1;
	}
	return 0;
}
int MapGrid::actionBlue(PlayerPos dir) {
	PlayerPos posBox(*p2 + dir);
	PlayerPos posBehindPly(*p2 - dir);
	if (mapGrid[posBehindPly.x][posBehindPly.y] == PATH) {
		mapGrid[p2->x][p2->y] = BOX;
		mapGrid[posBox.x][posBox.y] = PATH;
		*p2 -= dir;
		return 1;
	}
	return 0;
}

bool MapGrid::mapSolved() {
	return goalP1 && goalP2;
}

ostream& operator <<(ostream& s, MapGrid& grid) {
	for (int y(19); y >= 0; y--) { // print top of grid first
		for (int x(0); x < 20; x++) {
			if (x == grid.p1->x && y == grid.p1->y) {
				s << "(1)";
			}
			else if (x == grid.p2->x && y == grid.p2->y) {
				s << "(2)";
			}
			else {

				switch (grid.getGrid(x, y)) {
				case WALL:
					s << char(219) << char(219) << char(219);
					break;
				case PATH:
					s << " . ";
					break;
				case BOX:
					s << " " << char(254) << " ";
					break;
				case GOAL:
					s << char(177) << char(177) << char(177);
					break;
				case SPAWN1:
					s << " . ";
					break;
				case SPAWN2:
					s << " . ";
					break;
				}
			}
		}
		s << endl;
	}
	return s;
}