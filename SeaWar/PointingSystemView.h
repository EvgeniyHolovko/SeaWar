#pragma once
#include "WarShip.h"
#include "Validator.h"
#include <Windows.h>

const int X_STEP = 2;
const int Y_STEP = 2;

const TCHAR BLANK = L' ';
const int BLANK_LENGHT = 80;


const TCHAR TEST = 0x0039;
const TCHAR STUFF_CHAR = 0x2588;                                
const TCHAR TOP_LEFT_CORNER = 0x250C;
const TCHAR HORIZONT_LINE = 0x2500;
const TCHAR TOP_RIGHT_CORNER = 0x2510;
const TCHAR VERTICAL_LINE = 0x2502;
const TCHAR VERTICAL_LINE_RIGHT_SHOOT = 0x251C;
const TCHAR VERTICAL_LINE_LEFT_SHOOT = 0x2524;
const TCHAR BOTTOM_LEFT_CORNER = 0x2514;
const TCHAR BOTTOM_RIGHT_CORNER = 0x2518;
const TCHAR LIKE_T_SING_UP = 0x2534;
const TCHAR LIKE_T_SIGN_DOWN = 0x252C;
const TCHAR CROSS = 0x253C;
const TCHAR A_LITERAL = 0x0041;
const TCHAR ZERO_DIGIT = 0x0030;
const TCHAR ONE_DIGIT = 0x0031;

const COORD BOT_POINT_OF_REFERENCE{ 40, 2 };
const COORD PLAYER_POINT_OF_REFERENCE{ 2, 2 };

const int DOT_SIZE = 5;
const int MISSING_PIXEL = 1;
enum FieldType { DOT, POURING_FIELD, EMPTY_FIELD };



static class PointingSystemView
{
public : 
	PointingSystemView();
	void init();
	void drawMast(const bool isPlayer, const Coordinate &coord, const bool isDestroyed);
	void showDeploy(const bool isPlayer, const WarShip& ship);

	void showMissBorder(const bool isPlayer, WarShip *warship);
	void showHit(const bool isPalyer, const Coordinate &coord);
	void showMiss(const bool isPlayer, const Coordinate &coord) const;
	void write(wstring str);

	virtual ~PointingSystemView();

private:
	HANDLE hScreen;
	Validator &validator;

	inline COORD setRefCoord(const bool isPlayer, const int x, const int y) const
	{
		COORD tempCoord;
		if (isPlayer)
		{
			tempCoord = PLAYER_POINT_OF_REFERENCE;
		}
		else
		{
			tempCoord = BOT_POINT_OF_REFERENCE;
		}		
		tempCoord.X += x;
		tempCoord.Y += y;
		return tempCoord;
	}

	void fillRect(const TCHAR fillChar, WORD attr, COORD topLeft, COORD bottomRight, bool useAttr) const;
	void plotField(const bool isPlayer) const;

	COORD coordConverter(const Coordinate& coordinate, const bool isPlayer) const;

};

