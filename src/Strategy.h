#pragma once

#include<vector>

#include "Tank.h"
#include "Wall.h"
#include "Gold.h"
#include "Shot.h"

class Strategy
{
public:
	Strategy();
	virtual ~Strategy();

	virtual void logic(std::vector<Shot>&, std::vector<Wall>&, std::vector<Tank>&, Gold*) = 0;
	virtual bool canShoot(std::vector<Tank>&, std::vector<Wall>&, Gold*) = 0;
};

