#pragma once
static class StatisticStorage
{
public:
	StatisticStorage();
	virtual ~StatisticStorage();
	void run();
	void stop();

private:
	int finalAmountOfTime_;
	int amountOfEnemyShipsDestroyed_;
	int amountOfFriendlyShipsDestroyed_;
};

