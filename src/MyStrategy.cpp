#include "MyStrategy.h"


MyStrategy::MyStrategy()
{
}


MyStrategy::~MyStrategy()
{
}

void
MyStrategy::logic(std::vector<Shot>& shots, const std::vector<Wall>& walls, std::vector<Tank>& tanks, Gold* gold)
{
	srand(time(0));

	int i;
	for (i = 1; i < tanks.size(); i++){
		int direct = canShoot(i, tanks, walls, gold);

		int attemt = rand() % NUMBER_ATTEMPT;

		if (direct != -1 && attemt == GOOD_ATTEMPT){
			tanks[i].turn(static_cast<Direction>(direct));

			Shot sh = tanks[i].shoot();
			shots.push_back(sh);
		}
	}


	bool isSpeed = false;
	for (i = 1; i < tanks.size(); i++){

		if (tmpSpeed_ == SPEED){
			int j;

			Tank t = tanks[i];
			t.move();

			if (t.getX() < 0 || t.getY() < 0 || t.getX() + 3 >= WIDTH || t.getY() + 3 >= HEIGHT){
				tanks[i].turn();
				goto m;
			}

			for (j = 0; j < walls.size(); j++)
				if (walls[j].intersect(t)){
					tanks[i].turn();
					goto m;
				}

			for (j = 0; j < tanks.size(); j++)
				if (i != j && tanks[j].intersect(t)){
					tanks[i].turn();
					goto m;
				}

			tanks[i].move();

		m:;
			isSpeed = true;
		}
	}

	if (isSpeed)
		tmpSpeed_ = 0;

	tmpSpeed_++;

}

int
MyStrategy::canShoot(int n, std::vector<Tank>& tanks, const std::vector<Wall>& walls, Gold* gold)
{
	Direction direction[4] = { Direction::DOWN, Direction::LEFT, Direction::RIGHT, Direction::UP };

	int x = tanks[n].getX(), y = tanks[n].getY(), usrTankX = tanks[0].getX(), usrTankY = tanks[0].getY();

	if (x + 1 >= usrTankX && x + 1 <= usrTankX + 2){
		if (usrTankY < y)
			return static_cast<int>(Direction::UP);
		else
			return static_cast<int>(Direction::DOWN);
	}

	if (y + 1 >= usrTankY && y + 1 <= usrTankY + 2){
		if (x > usrTankX)
			return static_cast<int>(Direction::LEFT);
		else
			return static_cast<int>(Direction::RIGHT);
	}

	int goldX = gold->getX(), goldY = gold->getY();

	if (x + 1 == goldX){
		if (goldY < y)
			return static_cast<int>(Direction::UP);
		else
			return static_cast<int>(Direction::DOWN);
	}

	if (y + 1 == goldY){
		if (x > goldX)
			return static_cast<int>(Direction::LEFT);
		else
			return static_cast<int>(Direction::RIGHT);
	}

	return -1;
}