#pragma once
#include "WarShip.h"
#include <list>
using namespace std;

enum {MISS, HIT, LETHAL, REPEAT, DEFEAT};

class FlotillaZoneModel
{
public:
	FlotillaZoneModel(bool isPlayer);
	virtual ~FlotillaZoneModel();

private:
	bool isPlayer;
	list<WarShip*> &ships_;
};

