#include "Brig.h"


Brig::Brig(const Coordinate &coord, const Orientation orient)
{
	for (int n = 0; n < AMOUNT_OF_BRIG_MASTS; n++)
	{

		if (orient == HORIZONTAL)
		{
			masts_.push_back(new Mast(*new Coordinate(coord.getX() + n, coord.getY())));
		}
		else
		{
			masts_.push_back(new Mast(*new Coordinate(coord.getX(), coord.getY() + n)));
		}
	}
}


Brig::~Brig()
{
	for (Mast* mast : masts_)
	{
		delete mast;
	}
}

