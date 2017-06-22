#pragma once
#include "WarShip.h"
#include "Mast.h"
const int AMOUNT_OF_BARK_MASTS = 4;


class Bark : public WarShip
{	
public:
	Bark(Coordinate &coor, Orientation orient);
	virtual ~Bark();
	Rectangle& getRect() override;
	Rectangle& getAroundRect() override;
	

private:
	Mast masts_[AMOUNT_OF_BARK_MASTS];
};

