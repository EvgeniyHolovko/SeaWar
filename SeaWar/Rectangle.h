#pragma once
#include "Coordinate.h"

class Rectangle
{
public:
	Rectangle(Coordinate& tl, Coordinate& br);
	Rectangle(const Rectangle& rect);
	const Coordinate& getTopLeft() const;
	const Coordinate& getBottomRight() const;
	~Rectangle();

private:
	Coordinate& topLeft_;
	Coordinate& bottomRight_;
};

