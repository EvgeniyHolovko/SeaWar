#pragma once
#include "WarShip.h"
//const int AMOUNT_OF_MASTS = 1;

class Drakkar : public WarShip
{
public:
	Drakkar(Coordinate &coor, Orientation orient);
	virtual ~Drakkar();
	Rectangle& getRect() override;
	Rectangle& getAroundRect() override;

private:
	Mast &mast;
};

