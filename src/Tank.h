#ifndef TANK_H
#define TANK_H

#include<ctime>

#include "Points.h"
#include "Util.h"
#include "Shot.h"

class Tank :
	public Points
{
public:
	Tank(int id, int x, int y, const char*);
	~Tank();

	Shot shoot();
	void move(Direction);
	void move();
	Direction getHeadDirect() const;
	void turn(Direction);
	void turn();
	int getId() const;

private:
	int id_;
	Direction headDirect_;
};
#endif TANK_H
