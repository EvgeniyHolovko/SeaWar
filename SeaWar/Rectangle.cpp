#include "Rectangle.h"


Rectangle::Rectangle(Coordinate tl, Coordinate br):topLeft_(tl), bottomRight_(br)
{
}

Rectangle::Rectangle(const Rectangle& rect)
{
	topLeft_ = rect.topLeft_;
	bottomRight_ = rect.bottomRight_;
}

const Coordinate& Rectangle::getTopLeft() const
{
	return topLeft_;
}

const Coordinate& Rectangle::getBottomRight() const
{
	return bottomRight_;
}

Rectangle::~Rectangle()
{
}
