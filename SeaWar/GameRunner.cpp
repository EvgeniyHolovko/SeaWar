#include "GameRunner.h"
#include "ShipFactory.h"
#include "Brig.h"
#include "Coordinate.h"
#include "ShipRectangle.h"
#include "WarShip.h"
#include "PointingSystemView.h"
#include "FlotillaZoneModel.h"
#include "Validator.h"
#include "Bot.h"
#include <iostream>

using namespace std;

GameRunner::GameRunner() : isGameOver(false)
{
}

void GameRunner::start()
{
	PointingSystemView &view = *new PointingSystemView();
	view.init();
	ShipFactory &factory = *new ShipFactory();
	FlotillaZoneModel &fzm = *new FlotillaZoneModel(true, factory, view);
	FlotillaZoneModel &botFzm = *new FlotillaZoneModel(false, factory, view);
	PointingSystemController &botController = *new PointingSystemController(botFzm, fzm);
	PointingSystemController &playerController = *new PointingSystemController(fzm, botFzm);
	Bot &bot = *new Bot(botController);

	bot.deploy();
	playerDeployCycle(view, playerController);
	battleCycle(view, playerController, bot);

	getchar();

	delete &botController;
	delete &playerController;
	delete &botFzm;
	delete &fzm;
	delete &view;
	delete &factory;
	delete &bot;
}


GameRunner::~GameRunner()
{
}

void GameRunner::playerDeployCycle(PointingSystemView &view, PointingSystemController &playerController)
{
	singleDeployCycle(BARK, BARKS_NEEDED, view, playerController);
	singleDeployCycle(CLIPPER, CLIPPERS_NEEDED, view, playerController);
	singleDeployCycle(BRIG, BRIGS_NEEDED, view, playerController);
	singleDeployCycle(DRAKKAR, DRAKKARS_NEEDED, view, playerController);
}

void GameRunner::battleCycle(PointingSystemView &view, PointingSystemController &playerController, Bot &bot)
{
	HitResponse finalResp = WRONG;
	wstring &tempoStr = *new wstring (L"Enter hit coordinate : ");
	while (finalResp != DEFEAT)
	{
		view.write(tempoStr);
		string str;
		cin >> str;
		vector<char> &coordData = *new vector<char>();
		if (parseHitData(str, coordData))
		{
			HitResponse tempoResp = playerController.sendHit(coordData[0], charDigitToInt(coordData[1]));
			if (tempoResp == MISS)
			{
				finalResp = bot.run();
				tempoStr.clear();
				tempoStr.insert(0, L"Now is your turn againg, focus and hit: ");
			}
			else if (tempoResp == REPEATED)
			{
				tempoStr.clear();
				tempoStr.insert(0, L"This coordinate is already checked, try again: ");
			}
			else if (tempoResp == DEFEAT)
			{
				finalResp = DEFEAT;
			}
		}
		delete &coordData;
	}
		delete &tempoStr;
}

bool GameRunner::parseDeployData(const string &str, vector<char> &coordData) const
{
	for (std::string::size_type i = 0; i < str.size(); ++i) 
	{
		if (((str[i] >= 'a' && str[i] <= 'j') || (str[i] >= 'A' && str[i] <= 'J')) || (str[i] >= '1' && str[i] <= '10') || str[i] == 'v' || str[i] == 'V')
		{
			if (str[i] == '1' && str[i+1] == '0')
			{
				coordData.push_back('0');				
			}
			else
			{
				coordData.push_back(str[i]);
			}			
		}
	}

	if (coordData.size() == 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GameRunner::parseHitData(const string &str, vector<char> &coordData) const
{
	for (std::string::size_type i = 0; i < str.size(); ++i)
	{
		if (((str[i] >= 'a' && str[i] <= 'j') || (str[i] >= 'A' && str[i] <= 'J')) || (str[i] >= '1' && str[i] <= '10'))
		{
			if (str[i] == '1' && str[i + 1] == '0')
			{
				coordData.push_back('0');
			}
			else
			{
				coordData.push_back(str[i]);
			}
		}
	}
	if (coordData.size() == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GameRunner::singleDeployCycle(const shipType shipType, const int shipsNeeded, PointingSystemView &view, PointingSystemController &playerController)
{
	int amountOfShipsDeployed = 0;
	vector<char> &coordData = *new  vector<char>();
	wstring tempoStr = L"Enter " + shipTypeToWstring(shipType) + L" coordinates and orientation: ";
	while (amountOfShipsDeployed < shipsNeeded)
	{	
		view.write(tempoStr);
		string str;
		cin >> str;
		if (parseDeployData(str, coordData) && playerController.deployShip(shipType, coordData[2], coordData[0], charDigitToInt(coordData[1])))
		{
			tempoStr = L"Enter another " + shipTypeToWstring(shipType) + L" coordinates and orientation: ";
			amountOfShipsDeployed++;
		}
		else
		{
			tempoStr = L"Data is wrong, try again: ";
		}
		coordData.clear();
	}
	delete &coordData;
}

wstring GameRunner::shipTypeToWstring(const shipType shipType) const
{
	switch (shipType)
	{
	case BARK:
	{
		return L"Bark";
	}

	case CLIPPER:
	{
		return L"Clipper";
	}

	case BRIG:
	{
		return L"Brig";
	}

	case DRAKKAR:
	{
		return L"Drakkar";
	}

	default:
		return L"Bark";
	}
}

int GameRunner::charDigitToInt(const char ch) const
{
	if (ch == '0') 
	{
		return 10;
	}
	else if (ch > '0' && ch < '10' )
	{
		return ch - ASCII_CHAR_DIGIT_TO_INT_SWIFT;
	}
	return 0;	
}
