#include "FlotillaZoneModel.h"
#include <list>
using namespace std;

FlotillaZoneModel::FlotillaZoneModel(bool isPlayer) : isPlayer(isPlayer), ships_(*new list<WarShip*>)
{
}

FlotillaZoneModel::~FlotillaZoneModel()
{
}
