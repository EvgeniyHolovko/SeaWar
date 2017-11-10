#include "ShipFactory.h"
#include "Drakkar.h"
#include "Brig.h"
#include "Clipper.h"
#include "Bark.h"


WarShip &ShipFactory::createShip(const shipType shipType, const Coordinate &coord, const Orientation orient) const
{	
	if (shipType == DRAKKAR)
	{
		return *new Drakkar(coord);
	}
	else if (shipType == BRIG)
	{
		return *new Brig(coord, orient);
	}
	else if (shipType == CLIPPER)
	{
		return *new Clipper(coord, orient);
	}
	else if (shipType == BARK)
	{
		return *new Bark(coord, orient);
	}
	else
	{
		return *new Drakkar(coord);
	}
}

ShipFactory::ShipFactory()
{
}


ShipFactory::~ShipFactory()
{
}
