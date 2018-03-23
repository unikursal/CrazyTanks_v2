#ifndef STRATEGY_H
#define STRATEGY_H

#include<vector>

#include "Tank.h"
#include "Wall.h"
#include "Gold.h"
#include "Shot.h"
#include "Screen.h"

class Strategy
{
public:
	Strategy();
	virtual ~Strategy();

	virtual void logic(std::vector<Shot>&, const std::vector<Wall>&, std::vector<Tank>&, Gold*);
	virtual int canShoot(int n, std::vector<Tank>&, const std::vector<Wall>&, Gold*);
};
#endif STRATEGY_H
