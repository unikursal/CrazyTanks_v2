#pragma once

#include "Strategy.h"

class MyStrategy:
	public Strategy
{
public:
	MyStrategy();
	~MyStrategy();

	void logic(std::vector<Shot>&, std::vector<Wall>&, std::vector<Tank>&, Gold*);
	bool canShoot(std::vector<Tank>&, std::vector<Wall>&, Gold*);
};

