#include "Bark.h"



Bark::Bark(Coordinate &coor, Orientation orient)
{
	for (int n = 0; n < AMOUNT_OF_BARK_MASTS; n++)
	{
		if (orient == HORIZONTAL)
		{
			masts_[n].setPosition(coor.getX() + n, coor.getY());
		}
		else
		{
			masts_[n].setPosition(coor.getX(), coor.getY() + n);
		}
	}
}


Bark::~Bark()
{
}

Rectangle& Bark::getRect()
{
	Rectangle& rect = *new Rectangle(masts_[0].getPosition(), masts_[AMOUNT_OF_BARK_MASTS - 1].getPosition());
	return rect;
}

Rectangle& Bark::getAroundRect()
{
	Rectangle rect = *new Rectangle(masts_[0].getPosition(), masts_[AMOUNT_OF_BARK_MASTS - 1].getPosition());
	return rect;

	//todo complete this crap
}


