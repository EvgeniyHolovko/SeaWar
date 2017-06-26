#pragma once
#include "WarShip.h"
#include <list>
using namespace std;
const int COORD_POSITIVE_FLAG = 1;
const int COORD_NEGATIVE_FLAG = 0;
const int BATTLEFIELD_SIZE = 10;


enum {MISS, HIT, LETHAL, REPEAT, DEFEAT};

class FlotillaZoneModel
{
public:
	FlotillaZoneModel(bool isPlayer);
	virtual ~FlotillaZoneModel();

private:
	bool isPlayer;
	list<WarShip*> &ships_;

	bool checkOverlap(Rectangle &first, Rectangle &second);
	int literalToDigit(_TCHAR coordLiteral);
};

