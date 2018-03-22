#pragma once

#include "Points.h"
#include "Util.h"

class Wall :
	public Points
{
public:
	Wall(int x, int y, Forma);
	~Wall();
};

