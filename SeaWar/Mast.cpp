#include "Mast.h"


Mast::Mast():isDestroyed_(false), position_(*new Coordinate)
{
}


Coordinate& Mast::getPosition()
{
	return position_;
}

Mast::~Mast()
{
	delete& position_;
}
