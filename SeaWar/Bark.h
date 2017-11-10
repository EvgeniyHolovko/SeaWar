#pragma once
#include "WarShip.h"
#include "Mast.h"

const int AMOUNT_OF_BARK_MASTS = 4;

class Bark : public WarShip
{	
public:
	Bark(const Coordinate &coor, const Orientation orient);
	virtual ~Bark();

};

