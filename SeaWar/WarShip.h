#pragma once
#include "ShipRectangle.h"
#include <list>
#include "Mast.h"

using namespace std;

class WarShip
{
public:
	WarShip();
	virtual ShipRectangle &getRect() const;
	virtual ShipRectangle &getAroundRect() const;
	virtual HitResponse takeHit(const Coordinate& coord);
	virtual bool isDestroyed() const;
	virtual ~WarShip() = 0;
protected:
	list<Mast*> &masts_;
};

