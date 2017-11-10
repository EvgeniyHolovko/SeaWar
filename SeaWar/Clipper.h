#pragma once
#include "WarShip.h"
#include "Mast.h"

const int AMOUNT_OF_CLIPPER_MASTS = 3;

class Clipper:public WarShip
{
public:
	Clipper(const Coordinate &coord, const Orientation orient);
	virtual ~Clipper();
};