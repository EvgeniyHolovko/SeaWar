#pragma once
#include "WarShip.h"
#include "Mast.h"

const int AMOUNT_OF_BRIG_MASTS = 2;

class Brig : public WarShip
{
public:
	Brig(const Coordinate &coord, const Orientation orient);
	virtual ~Brig();
};
