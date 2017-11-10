#include "ShipRectangle.h"

ShipRectangle::ShipRectangle(Coordinate& tl, Coordinate& br) :topLeft_(tl), bottomRight_(br)
{
}

ShipRectangle::ShipRectangle(const ShipRectangle& rect) : topLeft_(rect.topLeft_), bottomRight_(rect.bottomRight_)
{
}

const Coordinate &ShipRectangle::getTopLeft() const
{
	return topLeft_;
}

const Coordinate &ShipRectangle::getBottomRight() const
{
	return bottomRight_;
}

ShipRectangle::~ShipRectangle()
{
}
