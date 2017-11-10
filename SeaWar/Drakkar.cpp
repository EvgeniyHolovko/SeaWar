#include "Drakkar.h"


Drakkar::Drakkar(const Coordinate &coor)
{
	masts_.push_back(new Mast(*new Coordinate (coor)));
}

Drakkar::~Drakkar()
{
	for (Mast* mast : masts_)
	{
		delete mast;
	}
}