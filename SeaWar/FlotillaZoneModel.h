#pragma once
#include "WarShip.h"
#include "ShipFactory.h"
#include "PointingSystemView.h"
#include <list>
#include <set>
using namespace std;
const int COORD_POSITIVE_FLAG = 1;
const int COORD_NEGATIVE_FLAG = 0;
const int BATTLEFIELD_SIZE = 10;


class FlotillaZoneModel
{
public:
	FlotillaZoneModel(bool isPlayer, ShipFactory &shipFactory, PointingSystemView &view);
	virtual ~FlotillaZoneModel();
	bool FlotillaZoneModel::deployShip(const shipType shipType, const Coordinate &coord, const Orientation orient) const;
	HitResponse takeHit(const Coordinate& coord);

private:
	bool isPlayer;
	list<WarShip*> &ships;
	list<Coordinate*> &usedCoords;
	ShipFactory &factory;
	Validator &validator;
	PointingSystemView &pointingView;
	bool isFlotDead() const;
	bool checkOverlap(const ShipRectangle &first, const ShipRectangle &second) const;
	int literalToDigit(const _TCHAR coordLiteral) const;
	void pourShipBorder(const WarShip &ship);
};

