#include "ShipFactory.h"
#include "Drakkar.h"
#include "Brig.h"
#include "Clipper.h"
#include "Bark.h"


WarShip &ShipFactory::createShip(string shipType, Coordinate &coord, Orientation orient) const
{	
	if (shipType == "Drakkar")
	{
		return *new Drakkar(coord, orient);
	}
	else if (shipType == "Brig")
	{
		return *new Brig(coord, orient);
	}
	else if (shipType == "Clipper")
	{
		return *new Clipper(coord, orient);
	}
	else if (shipType == "Bark")
	{
		return *new Bark(coord, orient);
	}
	else
	{
		return *new Drakkar(coord, orient);
	}
}

ShipFactory::ShipFactory()
{
}


ShipFactory::~ShipFactory()
{
}
