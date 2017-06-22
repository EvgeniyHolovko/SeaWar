#include "PointingSystemView.h"

#include <gdiplus.h>
using namespace Gdiplus;




PointingSystemView::PointingSystemView()
{
	hScreen = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);	
}

void PointingSystemView::init()
{
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hScreen, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(hScreen, &cursorInfo);

	plotField();

	SetConsoleActiveScreenBuffer(hScreen);

}

void PointingSystemView::showDeploy(WarShip& ship) const
{
	
}

void PointingSystemView::drawMast(Mast& mast)
{
	COORD tempCoord = coordConverter(mast.getPosition(), true);
	fillRect(STUFF_CHAR, FOREGROUND_RED | FOREGROUND_INTENSITY, setRefCoord(tempCoord.X, tempCoord.Y), 
		setRefCoord(tempCoord.X + X_STEP, tempCoord.Y), true);
}

void PointingSystemView::showMiss(const Coordinate &coord) const
{
	COORD tempCoord = coordConverter(coord, true);
	fillRect(HORIZONT_LINE, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY, setRefCoord(tempCoord.X, tempCoord.Y),
		setRefCoord(tempCoord.X + X_STEP, tempCoord.Y), true);
}

PointingSystemView::~PointingSystemView()
{
	CloseHandle(hScreen);
}

void PointingSystemView::fillRect(const TCHAR fillChar, WORD attr, COORD topLeft, COORD bottomRight, bool useAttr) const
{
	DWORD amountOfWrittenChars;	
	for (COORD coord = topLeft; coord.Y <= bottomRight.Y; ++coord.Y) {
		FillConsoleOutputCharacter(hScreen, fillChar, bottomRight.X - topLeft.X, coord, &amountOfWrittenChars);
		if (useAttr) {
			FillConsoleOutputAttribute(hScreen, attr, bottomRight.X - topLeft.X, coord, &amountOfWrittenChars);
		}
	}
}

void PointingSystemView::plotField() const
{
	int counter = 0;

	for (int i = 0; i < 33; i+=3)
	{ 
		fillRect(VERTICAL_LINE, FOREGROUND_GREEN | FOREGROUND_INTENSITY, setRefCoord(i, 1), setRefCoord(i + 1, 19), true);
	}

	for (int i = 0; i < 22; i+=2)
	{ 
		fillRect(HORIZONT_LINE, FOREGROUND_GREEN | FOREGROUND_INTENSITY, setRefCoord(1, i), setRefCoord(30, i), true);
	}

	for (int i = 3; i < 30; i+=3)
	{
		fillRect(LIKE_T_SIGN_DOWN, FOREGROUND_GREEN | FOREGROUND_INTENSITY, setRefCoord(i, 0), setRefCoord(i + 1, 0), true);
	}

	for (int i = 3; i < 30; i += 3)
	{
		fillRect(LIKE_T_SING_UP, FOREGROUND_GREEN | FOREGROUND_INTENSITY, setRefCoord(i, 20), setRefCoord(i + 1, 20), true);
	}

	for (int i = 2; i < 20; i += 2)
	{
		fillRect(VERTICAL_LINE_RIGHT_SHOOT, FOREGROUND_GREEN | FOREGROUND_INTENSITY, setRefCoord(0, i), setRefCoord(1, i), true);
	}
	
	for (int i = 2; i < 20; i += 2)
	{
		fillRect(VERTICAL_LINE_LEFT_SHOOT, FOREGROUND_GREEN | FOREGROUND_INTENSITY, setRefCoord(30, i), setRefCoord(31, i), true);
	}

	for (int i = 2; i < 20; i+=2)
	{
		for (int j = 3; j < 30; j+=3)
		{
			fillRect(CROSS, FOREGROUND_GREEN | FOREGROUND_INTENSITY, setRefCoord(j, i), setRefCoord(j+1, i), true);
		}	
	}

	fillRect(TOP_LEFT_CORNER, FOREGROUND_GREEN | FOREGROUND_INTENSITY, setRefCoord(0, 0), setRefCoord(1, 0), true);
	fillRect(TOP_RIGHT_CORNER, FOREGROUND_GREEN | FOREGROUND_INTENSITY, setRefCoord(30, 0), setRefCoord(31, 0), true);
	fillRect(BOTTOM_RIGHT_CORNER, FOREGROUND_GREEN | FOREGROUND_INTENSITY, setRefCoord(30, 20), setRefCoord(31, 20), true);
	fillRect(BOTTOM_LEFT_CORNER, FOREGROUND_GREEN | FOREGROUND_INTENSITY, setRefCoord(0, 20), setRefCoord(1, 20), true);

	for (int i = 1; i < 18; i+=2)
	{
		counter++;
		fillRect(ZERO_DIGIT + counter, FOREGROUND_GREEN | FOREGROUND_INTENSITY, setRefCoord(-1, i), setRefCoord(0, i), true);		
	}
	fillRect(ONE_DIGIT, FOREGROUND_GREEN | FOREGROUND_INTENSITY, setRefCoord(-2, 19), setRefCoord(-1, 19), true);
	fillRect(ZERO_DIGIT, FOREGROUND_GREEN | FOREGROUND_INTENSITY, setRefCoord(-1, 19), setRefCoord(-0, 19), true);

	counter = 0;
	for (int i = 1; i < 30; i += 3)
	{
		fillRect(A_LITERAL + counter, FOREGROUND_GREEN | FOREGROUND_INTENSITY, setRefCoord(i, -1), setRefCoord(i + 1, -1), true);
		counter++;
	}

}

COORD PointingSystemView::coordConverter(const Coordinate& coordinate, const bool isPlayer) const
{
	COORD consoleCoord = { 0, 0 };
	if (isPlayer){
		switch (coordinate.getX())
		{
		case 'a': consoleCoord.X = 1;
			break;
		case 'b': consoleCoord.X = 4;
			break;
		case 'c': consoleCoord.X = 7;
			break;
		case 'd': consoleCoord.X = 10;
			break;
		case 'e': consoleCoord.X = 13;
			break;
		case 'f': consoleCoord.X = 16;
			break;
		case 'g': consoleCoord.X = 19;
			break;
		case 'h': consoleCoord.X = 22;
			break;
		case 'i': consoleCoord.X = 25;
			break;
		case 'j': consoleCoord.X = 28;
			break;
		default:  consoleCoord.X = 1;
			break;
		}

		switch (coordinate.getY())
		{

		case 1: consoleCoord.Y = 1;
			break;
		case 2: consoleCoord.Y = 3;
			break;
		case 3: consoleCoord.Y = 5;
			break;
		case 4: consoleCoord.Y = 7;
			break;
		case 5: consoleCoord.Y = 9;
			break;
		case 6: consoleCoord.Y = 11;
			break;
		case 7: consoleCoord.Y = 13;
			break;
		case 8: consoleCoord.Y = 15;
			break;
		case 9: consoleCoord.Y = 17;
			break;
		case 10: consoleCoord.Y = 20;
			break;
		default:  consoleCoord.Y = 1;
			break;
		}
	}
	return consoleCoord;
}
