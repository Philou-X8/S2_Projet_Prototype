#include "position.h"

PlayerPos::PlayerPos() {
	x = 0;
	y = 0;
}
PlayerPos::PlayerPos(int xx, int yy) {
	x = xx;
	y = yy;
}

PlayerPos::PlayerPos(const PlayerPos& p2) {
	x = p2.x;
	y = p2.y;
}

bool PlayerPos::setPos(const int xx, const int yy) {
	x = xx;
	y = yy;
	return true;
}
bool PlayerPos::setPos(const PlayerPos& p2) {
	return setPos(p2.x, p2.y);
}
bool PlayerPos::move(const int dx, const int dy) {
	x += dx;
	y += dy;
	return true;
}
bool PlayerPos::move(const PlayerPos& delta) {
	move(delta.x, delta.y);
	return true;
}

bool PlayerPos::operator==(const PlayerPos& p2) {
	bool equal = true;
	if (x != p2.x) equal = false;
	if (y != p2.y) equal = false;
	return equal;
}
bool PlayerPos::operator!=(const PlayerPos& p2) {
	if (x != p2.x) return true;
	if (y != p2.y) return true;
	return false;
}

PlayerPos& PlayerPos::operator=(const PlayerPos& p2) {
	x = p2.x;
	y = p2.y;
	return *this;
}
/*
PlayerPos& PlayerPos::operator=(const PlayerPos* p2) {
	setPos(*p2);
	return *this;
}
*/
PlayerPos& PlayerPos::operator+=(const PlayerPos& p2) {
	move(p2);
	return *this;
}
PlayerPos& PlayerPos::operator-=(const PlayerPos& p2) {
	move(-p2.x, -p2.y);
	return *this;
}
PlayerPos PlayerPos::operator+(const PlayerPos& p2) {
	PlayerPos total(x + p2.x, y + p2.y);
	return total;
}
PlayerPos PlayerPos::operator-(const PlayerPos& p2) {
	PlayerPos total(x - p2.x, y - p2.y);
	return total;
}

int clampM(int& val) {
	if (val < 0) {
		val = 0;
		return val;
	}
	if (val > 19) {
		val = 19;
		return val;
	}
	return val;
}
int clampM(const int& val) {
	if (val < 0) {
		return 0;
	}
	if (val > 19) {
		return 19;
	}
	return val;
}

PlayerPos clampP(PlayerPos& pos) {
	clampM(pos.x);
	clampM(pos.y);
	return pos;
}