#include "Tank.h"


Tank::Tank(int x, int y, const char* points) : Points(x, y, points, 9, Forma::SQUARE)
{
	headDirect = Direction::UP;
}

Tank::~Tank()
{
}

Shot
Tank::shoot()
{
	switch (headDirect){
	case 1:
		return Shot(id, x + 1, y - 1, headDirect);
		break;
	case 3:
		return Shot(id, x - 1, y + 1, headDirect);
		break;
	case 5:
		return Shot(id, x + 3, y + 1, headDirect);
		break;
	case 7:
		return Shot(id, x + 1, y + 3, headDirect);
		break;
	}
}

void
Tank::move(Direction direction)
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

Direction
Tank::getHeadDirect()
{
	return headDirect;
}

void
Tank::turn(Direction dir)
{
	char head[3], middle[3], end[3];

	switch (headDirect){
	case Direction::UP:
		head[0] = chars[0];
		head[1] = chars[1];
		head[2] = chars[2];

		middle[0] = chars[3];
		middle[1] = chars[4];
		middle[2] = chars[5];

		end[0] = chars[6];
		end[1] = chars[7];
		end[2] = chars[8];
		break;
	case Direction::LEFT:
		head[0] = chars[0];
		head[1] = chars[3];
		head[2] = chars[6];

		middle[0] = chars[1];
		middle[1] = chars[4];
		middle[2] = chars[7];

		end[0] = chars[2];
		end[1] = chars[5];
		end[2] = chars[8];
		break;
	case Direction::RIGHT:
		head[0] = chars[2];
		head[1] = chars[5];
		head[2] = chars[8];

		middle[0] = chars[1];
		middle[1] = chars[4];
		middle[2] = chars[7];

		end[0] = chars[0];
		end[1] = chars[3];
		end[2] = chars[6];
		break;
	case Direction::DOWN:
		head[0] = chars[6];
		head[1] = chars[7];
		head[2] = chars[8];

		middle[0] = chars[3];
		middle[1] = chars[4];
		middle[2] = chars[5];

		end[0] = chars[0];
		end[1] = chars[1];
		end[2] = chars[2];
		break;
	}

	switch (dir){
	case Direction::DOWN:
		chars[6] = head[0];
		chars[7] = head[1];
		chars[8] = head[2];

		chars[3] = middle[0];
		chars[4] = middle[1];
		chars[5] = middle[2];

		chars[0] = end[0];
		chars[1] = end[1];
		chars[2] = end[2];
		break;
	case Direction::LEFT:
		chars[0] = head[0];
		chars[3] = head[1];
		chars[6] = head[2];

		chars[1] = middle[0];
		chars[4] = middle[1];
		chars[7] = middle[2];

		chars[2] = end[0];
		chars[5] = end[1];
		chars[8] = end[2];
		break;
	case Direction::RIGHT:
		chars[2] = head[0];
		chars[5] = head[1];
		chars[8] = head[2];

		chars[1] = middle[0];
		chars[4] = middle[1];
		chars[7] = middle[2];

		chars[0] = end[0];
		chars[3] = end[1];
		chars[6] = end[2];
		break;
	case Direction::UP:
		chars[0] = head[0];
		chars[1] = head[1];
		chars[2] = head[2];

		chars[3] = middle[0];
		chars[4] = middle[1];
		chars[5] = middle[2];

		chars[6] = end[0];
		chars[7] = end[1];
		chars[8] = end[2];
		break;
	}

	headDirect = dir;

}
