#pragma once
#include <tchar.h>

const _TCHAR minChar = L'A';
const _TCHAR maxChar = L'J';
const int maxDigit = 9;
enum Orientation {HORIZONTAL, VERTICAL};

class Coordinate
{
public:
	Coordinate();
	Coordinate(_TCHAR coord_x, int coord_y);
	void operator=(Coordinate coord);
	bool equal(Coordinate coord) const;
	_TCHAR getX() const;
	int getY() const;
	void setX(_TCHAR x);
	void setY(int y);
	~Coordinate();

private:
	_TCHAR charCoord_;
	int digitalCoord_;

};

