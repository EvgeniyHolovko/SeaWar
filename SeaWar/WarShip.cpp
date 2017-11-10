#include "WarShip.h"
#include "Coordinate.h"


WarShip::WarShip() : masts_ (*new list<Mast*>)
{
}


WarShip::~WarShip()
{
	delete& masts_;
}

ShipRectangle &WarShip::getRect() const
{
	return *new ShipRectangle(masts_.front()->getPosition(), masts_.back()->getPosition());
}

ShipRectangle &WarShip::getAroundRect() const
{
	Coordinate &tl = *new Coordinate(masts_.front()->getPosition().getX() - 1, masts_.front()->getPosition().getY() - 1);
	Coordinate &br = *new Coordinate(masts_.back()->getPosition().getX() + 1, masts_.back()->getPosition().getY() + 1);
	return *new ShipRectangle(tl, br);
}


HitResponse WarShip::takeHit(const Coordinate & coord)
{
	for (Mast* mast:masts_)
	{
		if (mast->getPosition().equal(coord))
		{
			if (mast->isDestroyed())
			{
				return REPEATED;
			}
			mast->setDestroyed(true);

			if (isDestroyed())
			{
				return DESTROYED;
			}

			return HIT;
		}
	}
	return MISS;
}

bool WarShip::isDestroyed() const
{
	for (Mast* mast:masts_)
	{
		if (!mast->isDestroyed())
		{
			return false;
		}
	}
	return true;
}