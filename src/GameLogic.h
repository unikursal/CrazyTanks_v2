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
	int userTankId_ = 0;
	int userLife_ = 3;
	std::clock_t timeStart_;

	std::vector<Tank> tanks_;
	std::vector<Shot> shots_;
	std::vector<Wall> walls_;
	Gold *gold_;

	Screen* screen_;

	Strategy* strategy_;
};

#endif GAMELOGIC_H

