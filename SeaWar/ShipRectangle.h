#pragma once
#include "Coordinate.h"
class ShipRectangle
{
public:
	ShipRectangle(Coordinate& tl, Coordinate& br);
	ShipRectangle(const ShipRectangle& rect);
	const Coordinate &getTopLeft() const;
	const Coordinate &getBottomRight() const;
	~ShipRectangle();

private:
	Coordinate &topLeft_;
	Coordinate &bottomRight_;
};
