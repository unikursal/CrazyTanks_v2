#pragma once

#include "Points.h"
#include "Util.h"
#include "Shot.h"

class Tank :
	public Points
{
public:
	Tank(int x, int y, const char*);
	~Tank();

	Shot shoot();
	void move(Direction);
	Direction getHeadDirect();
	void turn(Direction);
	int getId();

private:
	int id;
	Direction headDirect;
};

