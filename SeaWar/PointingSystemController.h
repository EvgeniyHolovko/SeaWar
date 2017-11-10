#pragma once
#include "FlotillaZoneModel.h"

class PointingSystemController
{
public:
	PointingSystemController(FlotillaZoneModel &friendlyField, FlotillaZoneModel &oponentField);

	bool deployShip(const shipType shipType, const char orientation, const char charCoord, const int digitalCoord) const;
	HitResponse sendHit(const char charCoord, const int digitalCoord) const;

	virtual ~PointingSystemController();

private:
	FlotillaZoneModel &friendlyField;
	FlotillaZoneModel &oponentField;
};

