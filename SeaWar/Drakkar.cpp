#include "Drakkar.h"


Drakkar::Drakkar(Coordinate &coor, Orientation orient) : mast(*new Mast)
{
	
}


Drakkar::~Drakkar()
{
	delete &mast;
}

Rectangle& Drakkar::getRect()
{
	Rectangle& rect = *new Rectangle(mast.getPosition(), mast.getPosition());
	return rect;
}

Rectangle& Drakkar::getAroundRect()
{
	Rectangle& rect = *new Rectangle(mast.getPosition(), mast.getPosition());
	return rect;
}
