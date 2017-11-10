// SeaWar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameRunner.h"


int _tmain(int argc, _TCHAR* argv[])
{
	GameRunner &runner = *new GameRunner();
	runner.start();
	
	delete &runner;
	return 0;
}

