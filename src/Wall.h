#ifndef WALL_H
#define WALL_H

#include "Points.h"
#include "Shot.h"
#include "Util.h"

class Wall :
	public Points
{
public:
	Wall(int x, int y, int width, int height);
	~Wall();

	void attack(Shot);
	bool intersect(const Points& inpPints) const;

private:
	const int strongWall_ = 8;
	unsigned char strong_[LINE_LENGTH];
};
#endif WALL_H

