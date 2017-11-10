#include "Validator.h"


bool Validator::checkLimit(const Coordinate &coord) const
{
	if (((coord.getX() >= 'a' && coord.getX() <= 'j') || (coord.getX() >= 'A' && coord.getX() <= 'J')) && (coord.getY() >= 1 && coord.getY() <= 10))
	{
		return true;
	}
	return false;
}

bool Validator::checkDeploy(const WarShip &ship) const
{
	Coordinate &tl = *new Coordinate (ship.getRect().getTopLeft());
	Coordinate &br = *new Coordinate(ship.getRect().getBottomRight());
	
	bool result = checkLimit(tl) && checkLimit(br);
	
	delete &tl;
	delete &br;

	return result;
}

bool Validator::isCoordExist(const Coordinate &coord, const list<Coordinate*> coords) const
{
	for (Coordinate *tempoCoord : coords)
	{
		if (tempoCoord->equal(coord))
		{
			return true;
		}
	}
	return false;
}


Validator::Validator()
{
}


Validator::~Validator()
{
}
