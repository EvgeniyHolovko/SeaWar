#pragma once
#include "WarShip.h"
#include <string>
using namespace std;

enum shipType {BARK, CLIPPER, BRIG, DRAKKAR};

class ShipFactory
{
public:
	WarShip& createShip(const shipType shipType, const Coordinate &coord, const Orientation orient) const;
	ShipFactory();
	virtual ~ShipFactory();
};

