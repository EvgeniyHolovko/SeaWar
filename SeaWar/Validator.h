#pragma once
#include "Coordinate.h"
#include "WarShip.h"

class Validator
{
public:
	Validator();

	bool checkLimit(const Coordinate &coord) const;
	bool checkDeploy(const WarShip &ship) const;
	bool isCoordExist(const Coordinate &coord, const list<Coordinate*> coords) const;

	virtual ~Validator();
};

