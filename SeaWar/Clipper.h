#pragma once
#include "WarShip.h"
#include "Mast.h"
const int AMOUNT_OF_CLIPPER_MASTS = 3;


class Clipper:public WarShip
{
public:
	Clipper(Coordinate &coord, Orientation orient);
	virtual ~Clipper();
	Rectangle& getRect() override;
	Rectangle& getAroundRect() override;

private:
	Mast masts_[AMOUNT_OF_CLIPPER_MASTS];
};