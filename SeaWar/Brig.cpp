#include "Brig.h"


Brig::Brig(Coordinate &coord, Orientation orient)
{
	for (int n = 0; n < AMOUNT_OF_BRIG_MASTS; n++)
	{
		if (orient == HORIZONTAL)
		{
			masts_[n].setPosition(coord.getX() + n, coord.getY());
		}
		else
		{
			masts_[n].setPosition(coord.getX(), coord.getY() + n);
		}
	}
}


Brig::~Brig()
{
}

Rectangle& Brig::getRect()
{
	Rectangle& rect = *new Rectangle(masts_[0].getPosition(), masts_[AMOUNT_OF_BRIG_MASTS - 1].getPosition());
	return rect;
}

Rectangle& Brig::getAroundRect()
{
	Rectangle& rect = *new Rectangle(masts_[0].getPosition(), masts_[AMOUNT_OF_BRIG_MASTS - 1].getPosition());
	return rect;
}
