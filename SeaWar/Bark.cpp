#include "Bark.h"
#include "Mast.h"
using namespace std;


Bark::Bark(const Coordinate &coord, const Orientation orient)
{
	for (int n = 0; n < AMOUNT_OF_BARK_MASTS; n++)
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

Bark::~Bark()
{
	for (Mast* mast:masts_)
	{
		delete mast;
	}
}



