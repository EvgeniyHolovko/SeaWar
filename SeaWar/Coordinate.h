#pragma once
#include <tchar.h>

const _TCHAR MIN_CHAR = L'A';
const _TCHAR MAX_CHAR = L'J';
const int MAX_DIGIT = 9;
enum Orientation {HORIZONTAL, VERTICAL};

class Coordinate
{
public:
	Coordinate();
	Coordinate(const _TCHAR coord_x, const int coord_y);
	void operator=(const Coordinate coord);
	bool equal(const Coordinate coord) const;
	_TCHAR getX() const;
	int getY() const;
	void setX(const _TCHAR x);
	void setY(const int y);
	~Coordinate();

private:
	_TCHAR charCoord_;
	int digitalCoord_;

};

