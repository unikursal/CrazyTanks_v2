#include "Shot.h"


Shot::Shot(int n, int x, int y, Direction dir) : Points(x, y, FORMA_SHOT, 1, Forma::ONE)
{
	
}


Shot::~Shot()
{
}

void
Shot::move()
{
	switch (direction){
	case Direction::DOWN:
		y++;
		break;
	case Direction::LEFT:
		x--;
		break;
	case Direction::RIGHT:
		x++;
		break;
	case Direction::UP:
		y--;
		break;
	}

}

int
Shot::getIdTank()
{
	return idTank;
}

Direction
Shot::getDirection()
{
	return direction;
}