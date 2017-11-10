#pragma once
#include "PointingSystemView.h"
#include "PointingSystemController.h"
#include "Bot.h"
#include <vector>


const int BARKS_NEEDED = 1;
const int CLIPPERS_NEEDED = 2;
const int BRIGS_NEEDED = 3;
const int DRAKKARS_NEEDED = 4;
const int ASCII_CHAR_DIGIT_TO_INT_SWIFT = 48;

class GameRunner
{
public:
	GameRunner();
	void start();
	virtual ~GameRunner();

private:
	bool isGameOver;
	bool parseDeployData(const string &str, vector<char> &coordData) const;
	bool parseHitData(const string &str, vector<char> &coordData) const;
	void playerDeployCycle(PointingSystemView &view, PointingSystemController &playerController);
	void battleCycle(PointingSystemView &view, PointingSystemController &playerController, Bot &bot);

	void singleDeployCycle(const shipType shipType, const int shipsNeeded, PointingSystemView &view, PointingSystemController &playerController);
	wstring shipTypeToWstring(const shipType shipType) const;
	int charDigitToInt(const char ch) const;
};

