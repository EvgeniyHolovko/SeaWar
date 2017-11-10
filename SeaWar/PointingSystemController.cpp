#include "PointingSystemController.h"



PointingSystemController::PointingSystemController(FlotillaZoneModel & friendlyField, FlotillaZoneModel & oponentField) : 
	friendlyField(friendlyField), oponentField(oponentField)
{
}

bool PointingSystemController::deployShip(const shipType shipType, const char orientation, const char charCoord, const int digitalCoord) const
{
	bool response;
	Coordinate &tempoCoord = *new Coordinate(charCoord, digitalCoord);
	Orientation tempoOrientation;
	if (orientation == 'h' || orientation == 'H')
	{
		tempoOrientation = HORIZONTAL;
	}
	else
	{
		tempoOrientation = VERTICAL;
	}
	response = friendlyField.deployShip(shipType, tempoCoord, tempoOrientation);
	delete &tempoCoord;
	return response;
}

HitResponse PointingSystemController::sendHit(const char charCoord, const int digitalCoord) const
{
	Coordinate &coord = *new Coordinate(charCoord, digitalCoord);
	HitResponse response = oponentField.takeHit(coord);
	delete &coord;
	return response;
}


PointingSystemController::~PointingSystemController()
{
}
