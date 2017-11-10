#include "Mast.h"


Mast::Mast():destroyed(false), position(*new Coordinate)
{
}

Mast::Mast(Coordinate &coord):destroyed(false), position(coord)
{
}


bool Mast::isDestroyed() const
{
	return destroyed;
}

void Mast::setDestroyed(bool destroyed)
{
	destroyed = destroyed;
}

Coordinate& Mast::getPosition()
{
	return position;
}

Mast::~Mast()
{
	delete& position;
}
