#pragma once
#include "FlotillaZoneModel.h"
#include "PointingSystemController.h"
#include <set>
#include <vector>


class Bot
{
public:
	Bot(PointingSystemController &botController);
	HitResponse run();
	void deploy();
	virtual ~Bot();

private:
	set<Coordinate*> &deployCoordSet;
	set<Coordinate*> &hitCoordSet;

	vector<Coordinate*> &deployCollar;
	vector<Coordinate*> &hitCollar;

	ShipFactory &mockShipFactory;
	PointingSystemController &botController;
	Coordinate &popRandomCoordinate(vector<Coordinate*> &collar);
	TCHAR getRandomLiteralSignOfOrientation() const;
	void addDeployUsedCoords(const shipType type, Coordinate &coord, const TCHAR literalOrient) const;
	void deployShipsWithRandomCoords(const shipType typeOfShip, const int amount);
	HitResponse hitRandomTerget();

	void initShuffeledCollar(vector<Coordinate*> &collar);
};

