#include "Clipper.h"


Clipper::Clipper(Coordinate &coord, Orientation orient)
{
	for (int n = 0; n < AMOUNT_OF_CLIPPER_MASTS; n++)
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


Clipper::~Clipper()
{
}

Rectangle& Clipper::getRect()
{
	Rectangle rect = *new Rectangle(masts_[0].getPosition(), masts_[AMOUNT_OF_CLIPPER_MASTS - 1].getPosition());
	return rect;
}

Rectangle& Clipper::getAroundRect()
{
	Rectangle rect = *new Rectangle(masts_[0].getPosition(), masts_[AMOUNT_OF_CLIPPER_MASTS - 1].getPosition());
	return rect;
}

