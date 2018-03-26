#ifndef MYSTRATEGY_H
#define MYSTRATEGY_H

#include<ctime>

#include "Strategy.h"
#include "Screen.h"

class MyStrategy:
	public Strategy
{
public:
	const int SPEED = 5;
	const int GOOD_ATTEMPT = 1, NUMBER_ATTEMPT = 4;

	MyStrategy();
	~MyStrategy();

	void logic(std::vector<Shot>&, const std::vector<Wall>&, std::vector<Tank>&, const Gold&);
	int canShoot(int n, std::vector<Tank>&, const std::vector<Wall>&, const Gold&);

private:
	int tmpSpeed_ = 0;

};

#endif MYSTRATEGY_H

