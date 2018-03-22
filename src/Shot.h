#pragma once

#include "Points.h"
#include "Util.h"

class Shot :
	public Points
{
public:
	Shot(int id, int x, int y, Direction);
	~Shot();

	void move();
	int getIdTank();
	Direction getDirection();

private:
	int idTank;
	Direction direction;

};

