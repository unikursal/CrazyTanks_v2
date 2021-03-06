#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include<vector>
#include<ctime>

#include "Util.h"
#include "Tank.h"
#include "Shot.h"
#include "Gold.h"
#include "Wall.h"
#include "Strategy.h"
#include "Screen.h"
#include "Util.h"

class GameLogic
{
public:
	GameLogic(Strategy*);
	~GameLogic();

	void shoot();
	void moveUserTank(Direction);
	void start();
	void finish();

	int update();
private:
	int userTankId_;
	int userLife_;
	Gold gold_;
	Screen screen_;

	std::clock_t timeStart_;

	std::vector<Tank> tanks_;
	std::vector<Shot> shots_;
	std::vector<Wall> walls_;

	Strategy* strategy_;
};

#endif GAMELOGIC_H

