#include "Tank.h"


Tank::Tank(int id, int x, int y, const char* points) : Points(x, y, points, SQUARE_LENGTH, SQUARE_LENGTH)
{
	id_ = id;
	headDirect_ = Direction::UP;
}

Tank::~Tank()
{
}

Shot
Tank::shoot()
{
	switch (headDirect_){
	case 1:
		return Shot(id_, x_ + 1, y_ - 1, headDirect_);
		break;
	case 3:
		return Shot(id_, x_ - 1, y_ + 1, headDirect_);
		break;
	case 5:
		return Shot(id_, x_ + 3, y_ + 1, headDirect_);
		break;
	case 7:
		return Shot(id_, x_ + 1, y_ + 3, headDirect_);
		break;
	}
}

void
Tank::move(Direction direction)
{
	switch (direction){
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

Direction
Tank::getHeadDirect() const
{
	return headDirect_;
}

void
Tank::turn(Direction dir)
{
	char head[3], middle[3], end[3];

	switch (headDirect_){
	case Direction::UP:
		head[0] = chars_[0];
		head[1] = chars_[1];
		head[2] = chars_[2];

		middle[0] = chars_[3];
		middle[1] = chars_[4];
		middle[2] = chars_[5];

		end[0] = chars_[6];
		end[1] = chars_[7];
		end[2] = chars_[8];
		break;
	case Direction::LEFT:
		head[0] = chars_[0];
		head[1] = chars_[3];
		head[2] = chars_[6];

		middle[0] = chars_[1];
		middle[1] = chars_[4];
		middle[2] = chars_[7];

		end[0] = chars_[2];
		end[1] = chars_[5];
		end[2] = chars_[8];
		break;
	case Direction::RIGHT:
		head[0] = chars_[2];
		head[1] = chars_[5];
		head[2] = chars_[8];

		middle[0] = chars_[1];
		middle[1] = chars_[4];
		middle[2] = chars_[7];

		end[0] = chars_[0];
		end[1] = chars_[3];
		end[2] = chars_[6];
		break;
	case Direction::DOWN:
		head[0] = chars_[6];
		head[1] = chars_[7];
		head[2] = chars_[8];

		middle[0] = chars_[3];
		middle[1] = chars_[4];
		middle[2] = chars_[5];

		end[0] = chars_[0];
		end[1] = chars_[1];
		end[2] = chars_[2];
		break;
	}

	switch (dir){
	case Direction::DOWN:
		chars_[6] = head[0];
		chars_[7] = head[1];
		chars_[8] = head[2];

		chars_[3] = middle[0];
		chars_[4] = middle[1];
		chars_[5] = middle[2];

		chars_[0] = end[0];
		chars_[1] = end[1];
		chars_[2] = end[2];
		break;
	case Direction::LEFT:
		chars_[0] = head[0];
		chars_[3] = head[1];
		chars_[6] = head[2];

		chars_[1] = middle[0];
		chars_[4] = middle[1];
		chars_[7] = middle[2];

		chars_[2] = end[0];
		chars_[5] = end[1];
		chars_[8] = end[2];
		break;
	case Direction::RIGHT:
		chars_[2] = head[0];
		chars_[5] = head[1];
		chars_[8] = head[2];

		chars_[1] = middle[0];
		chars_[4] = middle[1];
		chars_[7] = middle[2];

		chars_[0] = end[0];
		chars_[3] = end[1];
		chars_[6] = end[2];
		break;
	case Direction::UP:
		chars_[0] = head[0];
		chars_[1] = head[1];
		chars_[2] = head[2];

		chars_[3] = middle[0];
		chars_[4] = middle[1];
		chars_[5] = middle[2];

		chars_[6] = end[0];
		chars_[7] = end[1];
		chars_[8] = end[2];
		break;
	}

	headDirect_ = dir;
}

int
Tank::getId() const
{
	return id_;
}

void
Tank::turn()
{
	Direction directs[4] = { Direction::DOWN, Direction::UP, Direction::LEFT, Direction::RIGHT };

	int n, i;

	for (i = 0; i < 10; i++){
		n = rand() % 4;

		if (directs[n] != headDirect_){
			turn(directs[n]);
			break;
		}
	}
}

void
Tank::move()
{
	move(headDirect_);
}