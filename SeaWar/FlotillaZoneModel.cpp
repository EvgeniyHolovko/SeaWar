#include "FlotillaZoneModel.h"
#include <list>
using namespace std;

FlotillaZoneModel::FlotillaZoneModel(bool isPlayer) : isPlayer(isPlayer), ships_(*new list<WarShip*>)
{
}

FlotillaZoneModel::~FlotillaZoneModel()
{
	for (WarShip* warship : ships_)
	{
		delete warship;
	}

	delete &ships_;
}

bool FlotillaZoneModel::checkOverlap(Rectangle &first, Rectangle &second)
{
	int firstCoordMatrix[BATTLEFIELD_SIZE][BATTLEFIELD_SIZE];
	int secondCoordMatrix[BATTLEFIELD_SIZE][BATTLEFIELD_SIZE];

	int top_X_Left_OfFirstCoord = literalToDigit(first.getTopLeft().getX());
	int top_Y_Left_OfFirstCoord = first.getTopLeft().getY() - 1;
	int bottom_X_Right_OfFirstCoord = literalToDigit(first.getBottomRight().getX());
	int bottom_Y_Right_OfFirstCoord = first.getBottomRight().getY() - 1;

	int top_X_Left_OfSecondCoord = literalToDigit(second.getTopLeft().getX());
	int top_Y_Left_OfSecondCoord = second.getTopLeft().getY() - 1;
	int bottom_X_Right_OfSecondCoord = literalToDigit(second.getBottomRight().getX());
	int bottom_Y_Right_OfSecondCoord = second.getBottomRight().getY() - 1;

	for (int i = top_X_Left_OfFirstCoord; i < bottom_X_Right_OfFirstCoord; i++)
	{
		for (int j = top_Y_Left_OfFirstCoord; j < bottom_Y_Right_OfFirstCoord; j++)
		{
			firstCoordMatrix[i][j] = COORD_POSITIVE_FLAG;
		}
	}

	for (int i = top_X_Left_OfSecondCoord; i < bottom_X_Right_OfSecondCoord; i++)
	{
		for (int j = top_Y_Left_OfSecondCoord; j < bottom_Y_Right_OfSecondCoord; j++)
		{
			secondCoordMatrix[i][j] = COORD_POSITIVE_FLAG;
		}
	}

	for (int i = 0; i < BATTLEFIELD_SIZE; i++)
	{
		for (int j = 0; j < BATTLEFIELD_SIZE; j++)
		{
			if (firstCoordMatrix[i][j] == secondCoordMatrix[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

int FlotillaZoneModel::literalToDigit(_TCHAR coordLiteral)
{
	if (coordLiteral == 'A' || coordLiteral == 'a')
	{
		return 0;
	}
	else if (coordLiteral == 'B' || coordLiteral == 'b')
	{
		return 1;
	}
	else if (coordLiteral == 'C' || coordLiteral == 'c')
	{
		return 2;
	}
	else if (coordLiteral == 'D' || coordLiteral == 'd')
	{
		return 3;
	}
	else if (coordLiteral == 'E' || coordLiteral == 'e')
	{
		return 4;
	}
	else if (coordLiteral == 'F' || coordLiteral == 'f')
	{
		return 5;
	}
	else if (coordLiteral == 'G' || coordLiteral == 'g')
	{
		return 6;
	}
	else if (coordLiteral == 'H' || coordLiteral == 'h')
	{
		return 7;
	}
	else if (coordLiteral == 'I' || coordLiteral == 'i')
	{
		return 8;
	}
	else if (coordLiteral == 'J' || coordLiteral == 'j')
	{
		return 9;
	}

	return -1;
}


