#pragma once

#include<vector>

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
	void moveTank(Direction);
	void start();

	void update();

	const std::vector<Tank>& getTanks();
	const std::vector<Wall>& getWalls();
	const std::vector<Shot>& getShots();
	Gold* getGold();
private:
	std::vector<Tank> tanks;
	std::vector<Shot> shots;
	std::vector<Wall> walls;
	Gold *gold;

	Screen* screen;

	Strategy* strategy;
};

