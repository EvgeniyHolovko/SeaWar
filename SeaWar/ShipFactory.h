#pragma once
#include "WarShip.h"
#include <string>
using namespace std;

class ShipFactory
{
public:
	WarShip& createShip(string shipType, Coordinate &coor, Orientation orient) const;
	ShipFactory();
	virtual ~ShipFactory();
};

