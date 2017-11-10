#include "Bot.h"
#include <ctime>
#include <algorithm>

Bot::Bot(PointingSystemController & botController) : botController(botController), deployCoordSet(*new set<Coordinate*>),
	hitCoordSet(*new set<Coordinate*>), deployCollar(*new vector<Coordinate*>), hitCollar(*new vector<Coordinate*>), mockShipFactory(*new ShipFactory())
{
}

HitResponse Bot::run()
{
	for (int i = 0; i < 90; i++)
	{
		HitResponse resp = hitRandomTerget();
		if (resp == MISS)
		{
			return MISS;
		}
		else if (resp == DEFEAT)
		{
			return DEFEAT;
		}
	}
}

void Bot::deploy()
{
	initShuffeledCollar(deployCollar);
	initShuffeledCollar(hitCollar);

	deployShipsWithRandomCoords(BARK, 1);
	deployShipsWithRandomCoords(CLIPPER, 2);
	deployShipsWithRandomCoords(BRIG, 3);
	deployShipsWithRandomCoords(DRAKKAR, 4);
}

Bot::~Bot()
{
	delete &mockShipFactory;

	for (Coordinate *coord : deployCoordSet)
	{
		delete coord;
	}

	for (Coordinate *coord : hitCoordSet)
	{
		delete coord;
	}

	for (Coordinate *coord : deployCollar)
	{
		delete coord;
	}

	for (Coordinate *coord : hitCollar)
	{
		delete coord;
	}

	delete &hitCoordSet;
	delete &deployCoordSet;
	delete &deployCollar;
	delete &hitCollar;
}

Coordinate &Bot::popRandomCoordinate(vector<Coordinate*> &collar)
{
	Coordinate &tempoCoord = *collar.back();
	collar.pop_back();
	return tempoCoord;
}

TCHAR Bot::getRandomLiteralSignOfOrientation() const
{
	TCHAR tempoOrient;
	int a = rand();
	
	if (a % 2 == 0)
	{
		tempoOrient = 'h';
	}
	else
	{
		tempoOrient = 'v';
	}
	
	return tempoOrient;
}

void Bot::addDeployUsedCoords(const shipType type, Coordinate &coord, const TCHAR literalOrient) const
{
	Orientation tempoOrient;
	if (literalOrient == 'h')
	{
		tempoOrient = HORIZONTAL;
	}
	else
	{
		tempoOrient = VERTICAL;
	}

	WarShip &mockShip = mockShipFactory.createShip(type, coord, tempoOrient);
	ShipRectangle &rect = mockShip.getAroundRect();


	for (int i = rect.getTopLeft().getX(); i <= rect.getBottomRight().getX(); i++)
	{
		for (int j = rect.getTopLeft().getY(); j <= rect.getBottomRight().getY(); j++)
		{
			deployCoordSet.insert(new Coordinate(i, j));
		}
	}

	delete &rect;
	delete &mockShip;
}

void Bot::deployShipsWithRandomCoords(const shipType typeOfShip, const int amount)
{
	for (int i = 0; i < amount; i++)
	{
		bool result = false;
		while (!result)
		{
			TCHAR tempoOrient = getRandomLiteralSignOfOrientation();
			Coordinate &tempoCoord = popRandomCoordinate(deployCollar);
			result = botController.deployShip(typeOfShip, tempoOrient, tempoCoord.getX(), tempoCoord.getY());
			if (result)
			{
				addDeployUsedCoords(typeOfShip, tempoCoord, tempoOrient);
			}
			delete &tempoCoord;
		}
	}
}

HitResponse Bot::hitRandomTerget()
{
	Coordinate &tempoCoord = popRandomCoordinate(hitCollar);
	HitResponse response = botController.sendHit(tempoCoord.getX(), tempoCoord.getY());
	delete &tempoCoord;
	return response;
}

void Bot::initShuffeledCollar (vector<Coordinate*> &collar)
{
	for (int i = 'a'; i <= ('a' + 9); i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			collar.push_back(new Coordinate(i, j));
		}
	}
	srand(time(NULL));
	random_shuffle(collar.begin(), collar.end());
}


