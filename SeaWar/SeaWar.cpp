// SeaWar.cpp : Defines the entry point for the console application.
//

#include "ShipFactory.h"
#include "Brig.h"
#include "Coordinate.h"



#include "stdafx.h"
#include "PointingSystemView.h"

int _tmain(int argc, _TCHAR* argv[])
{

	PointingSystemView &view = *new PointingSystemView();
	

	Mast &mast = *new Mast();
	Mast &mast1 = *new Mast();
	Mast &mast2 = *new Mast();

	mast.setPosition('b', 8);
	mast1.setPosition('c', 8);
	mast2.setPosition('d', 8);


	view.init();
	view.drawMast(mast);
	view.drawMast(mast1);
	view.drawMast(mast2);

	Coordinate &coordinate = *new Coordinate();
	coordinate.setX('g');
	coordinate.setY(5);

	view.showMiss(coordinate);

	getchar();

	delete &coordinate;
	delete &mast;
	delete &view;
	return 0;
}

