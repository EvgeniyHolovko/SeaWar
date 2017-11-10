#include "FlotillaZoneModel.h"
#include <list>
using namespace std;

FlotillaZoneModel::FlotillaZoneModel(bool isPlayer, ShipFactory &shipFactory, PointingSystemView &view) : isPlayer(isPlayer), ships(*new list<WarShip*>), 
	usedCoords(*new list<Coordinate*>),factory(shipFactory), pointingView(view), validator (*new Validator())
{
}

FlotillaZoneModel::~FlotillaZoneModel()
{
	for (WarShip* warship : ships)
	{
		delete warship;
	}

	for (Coordinate* coord : usedCoords)
	{
		delete coord;
	}

	delete &usedCoords;
	delete &ships;
	delete &validator;
}

bool FlotillaZoneModel::deployShip(const shipType shipType, const Coordinate &coord, const Orientation orient) const
{
	WarShip &tempoShip = factory.createShip(shipType, coord, orient);

	if (!validator.checkDeploy(tempoShip))
	{
		delete &tempoShip;
		return false;
	}

	for (WarShip *warShip : ships)
	{
		if (checkOverlap(warShip->getAroundRect(), tempoShip.getRect()))
		{
			delete &tempoShip;
			return false;
		}
	}
	ships.push_back(&tempoShip);
	pointingView.showDeploy(isPlayer, tempoShip);
	return true;
}

HitResponse FlotillaZoneModel::takeHit(const Coordinate &coord)
{
	if (!validator.checkLimit(coord))
	{
		return WRONG;
	}

	for (WarShip* warShip:ships)
	{
		HitResponse resp = warShip->takeHit(coord);
		if (resp == HIT || resp == DESTROYED)
		{
			if (isFlotDead())
			{
				return DEFEAT;
			}
			if (resp == DESTROYED)
			{
				pourShipBorder(*warShip);
				pointingView.showHit(isPlayer, coord);
				pointingView.showMissBorder(isPlayer, warShip);
				return DESTROYED;
			}
			pointingView.showHit(isPlayer, coord);
			return HIT;
		}
		else if (resp == REPEATED || validator.isCoordExist(coord, usedCoords))
		{
			return REPEATED;
		}
	}

	usedCoords.push_back(new Coordinate(coord));
	pointingView.showMiss(isPlayer, coord);
	return MISS;
}

bool FlotillaZoneModel::isFlotDead() const
{
	for (WarShip* warShip:ships)
	{
		if (!warShip->isDestroyed())
		{
			return false;
		}
	}
	return true;
}

bool FlotillaZoneModel::checkOverlap(const ShipRectangle &first, const ShipRectangle &second) const
{
	bool result = false;
	bool stopper = false;

	list<Coordinate*> firstList;
	list<Coordinate*> secondList;

	int firstLenghtX = first.getBottomRight().getX() - first.getTopLeft().getX() + 1;
	int firstLenghtY = first.getBottomRight().getY() - first.getTopLeft().getY() + 1;

	int secondLenghtX = second.getBottomRight().getX() - second.getTopLeft().getX() + 1;
	int secondLenghtY = second.getBottomRight().getY() - second.getTopLeft().getY() + 1;


	for (int i = 0; i < firstLenghtX; i++)
	{
		for (int j = 0; j < firstLenghtY; j++)
		{
			firstList.push_back(new Coordinate(first.getTopLeft().getX() + i, first.getTopLeft().getY() + j));
		}
	}

	for (int i = 0; i < secondLenghtX; i++)
	{
		for (int j = 0; j < secondLenghtY; j++)
		{
			secondList.push_back(new Coordinate(second.getTopLeft().getX() + i, second.getTopLeft().getY() + j));
		}
	}

	for (Coordinate* firstListcoord:firstList)
	{
		for (Coordinate* secondListcoord:secondList)
		{
			if (firstListcoord->equal(*secondListcoord))
			{
				result = true;
				stopper = true;
				break;
			}
		}
		if (stopper)
		{
			break;
		}
	}


	for (Coordinate* coord:firstList)
	{
		delete coord;
	}
	
	for (Coordinate* coord : secondList)
	{
		delete coord;
	}

	return result;
}

int FlotillaZoneModel::literalToDigit(const _TCHAR coordLiteral) const
{
	if (coordLiteral == 'A' || coordLiteral == 'a')
	{
		return 0;
	}
	else if (coordLiteral == 'B' || coordLiteral == 'b')
	{
		return 1;
	}
	else if (coordLiteral == 'C' || coordLiteral == 'c')
	{
		return 2;
	}
	else if (coordLiteral == 'D' || coordLiteral == 'd')
	{
		return 3;
	}
	else if (coordLiteral == 'E' || coordLiteral == 'e')
	{
		return 4;
	}
	else if (coordLiteral == 'F' || coordLiteral == 'f')
	{
		return 5;
	}
	else if (coordLiteral == 'G' || coordLiteral == 'g')
	{
		return 6;
	}
	else if (coordLiteral == 'H' || coordLiteral == 'h')
	{
		return 7;
	}
	else if (coordLiteral == 'I' || coordLiteral == 'i')
	{
		return 8;
	}
	else if (coordLiteral == 'J' || coordLiteral == 'j')
	{
		return 9;
	}
	return -1;
}

void FlotillaZoneModel::pourShipBorder(const WarShip &ship)
{
	for (int i = ship.getAroundRect().getTopLeft().getX(); i <= ship.getAroundRect().getBottomRight().getX(); i++)
	{
		for (int j = ship.getAroundRect().getTopLeft().getY(); j <= ship.getAroundRect().getBottomRight().getY(); j++)
		{
			Coordinate *tempoCoord = new Coordinate(i, j);
			if (validator.checkLimit(*tempoCoord))
			{
				usedCoords.push_back(tempoCoord);
			}
			else
			{
				delete tempoCoord;
			}
		}
	}
}


