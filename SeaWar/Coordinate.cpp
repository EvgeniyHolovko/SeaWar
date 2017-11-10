#include "Coordinate.h"


Coordinate::Coordinate()
{
}

Coordinate::Coordinate(const _TCHAR coord_x, const int coord_y)
{
	charCoord_ = coord_x;
	digitalCoord_ = coord_y;
}

void Coordinate::operator=(const Coordinate coord)
{
	charCoord_ = coord.charCoord_;
	digitalCoord_ = coord.digitalCoord_;
}

bool Coordinate::equal(const Coordinate coord) const
{
	return coord.charCoord_ == charCoord_ && coord.digitalCoord_ == digitalCoord_;
}

_TCHAR Coordinate::getX() const
{
	return charCoord_;
}

int Coordinate::getY() const
{
	return digitalCoord_;
}

void Coordinate::setX(const _TCHAR x)
{
	charCoord_ = x;
}

void Coordinate::setY(const int y)
{
	digitalCoord_ = y;
}


Coordinate::~Coordinate()
{
}
