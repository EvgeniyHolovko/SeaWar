#pragma once
#include "WarShip.h"
#include "Mast.h"
const int AMOUNT_OF_BRIG_MASTS = 2;

class Brig : public WarShip
{
public:


	Brig(Coordinate &coord, Orientation orient);
	virtual ~Brig();
	Rectangle& getRect() override;
	Rectangle& getAroundRect() override;

private:

	Mast masts_[AMOUNT_OF_BRIG_MASTS];
};
