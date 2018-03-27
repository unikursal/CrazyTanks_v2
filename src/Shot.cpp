#include "Shot.h"

Shot::Shot(int idTank, int x, int y, Direction direction) : Points(x, y, FORMA_SHOT, POINT_LENGTH, POINT_LENGTH)
{
	idTank_ = idTank;
	direction_ = direction;
}


Shot::~Shot()
{
}

void
Shot::move()
{
	switch (direction_){
	case Direction::DOWN:
		y_++;
		break;
	case Direction::LEFT:
		x_--;
		break;
	case Direction::RIGHT:
		x_++;
		break;
	case Direction::UP:
		y_--;
		break;
	}

}

int
Shot::getIdTank() const
{
	return idTank_;
}

Direction
Shot::getDirection() const
{
	return direction_;
}