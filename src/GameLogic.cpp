#include "GameLogic.h"

#include<iostream>

GameLogic::GameLogic(Strategy* strategy)
{
	screen = new Screen();

	this->strategy = strategy;

	int x = HEIGHT / 2, y = HEIGHT / 2;
	gold = new Gold(x, y);

	int i;
	for (i = 0; i < HEIGHT; i += LINE_LENGTH){
		walls.push_back(Wall(0, i, Forma::LINE_VERTICAL));
		walls.push_back(Wall(WIDTH - 1, i, Forma::LINE_VERTICAL));
	}

	for (i = 0; i < WIDTH; i += LINE_LENGTH){
		walls.push_back(Wall(i, 0, Forma::LINE_HORIZONTAL));
		walls.push_back(Wall(i, HEIGHT - 1, Forma::LINE_HORIZONTAL));
	}

	walls.push_back(Wall(x - 1, y - 2, Forma::LINE_VERTICAL));
	walls.push_back(Wall(x - 2, y - 2, Forma::LINE_VERTICAL));

	walls.push_back(Wall(x + 1, y - 2, Forma::LINE_VERTICAL));
	walls.push_back(Wall(x + 2, y - 2, Forma::LINE_VERTICAL));

	walls.push_back(Wall(x - 2, y - 3, Forma::LINE_HORIZONTAL));
	walls.push_back(Wall(x - 2, y - 4, Forma::LINE_HORIZONTAL));

	walls.push_back(Wall(x - 2, y + 3, Forma::LINE_HORIZONTAL));
	walls.push_back(Wall(x - 2, y + 4, Forma::LINE_HORIZONTAL));

	tanks.push_back(Tank(WIDTH / 2, HEIGHT - 10, FORMA_USER_TANK));
}


GameLogic::~GameLogic()
{
	delete screen;
	delete gold;
}

void
GameLogic::start()
{

}

void
GameLogic::moveTank(Direction direction)
{
	if (tanks[0].getHeadDirect() != direction){
		tanks[0].turn(direction);
	}
	else{
		if (screen->canMove(tanks[0], direction))
		tanks[0].move(direction);
	}
}

void
GameLogic::shoot()
{
	Shot sh = tanks[0].shoot();
	shots.push_back(sh);
}

void
GameLogic::update()
{
	int i;
	screen->clear();
	for (i = 0; i < walls.size(); i++)
		screen->show(walls[i]);

	for (i = 0; i < tanks.size(); i++)
		screen->show(tanks[i]);

	for (i = 0; i < shots.size(); i++)
		screen->show(shots[i]);

	for (i = 0; i < shots.size(); i++){
		if (screen->canMove(shots[i], shots[i].getDirection()))
			shots[i].move();
		else{
			shots.erase(shots.begin() + i);
			i--;
		}
			
	}

	screen->show(*gold);

	screen->updateScreen();

	strategy->logic(shots, walls, tanks, gold);
}

const std::vector<Tank>&
GameLogic::getTanks()
{
	return tanks;
}

const std::vector<Wall>&
GameLogic::getWalls()
{
	return walls;
}

const std::vector<Shot>&
GameLogic::getShots()
{
	return shots;
}

Gold*
GameLogic::getGold()
{
	return gold;
}