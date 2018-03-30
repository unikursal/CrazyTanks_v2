#include "GameLogic.h"

GameLogic::GameLogic(Strategy* strategy)
{
	screen_ = new Screen();

	strategy_ = strategy;
}


GameLogic::~GameLogic()
{
	delete screen_;
	delete gold_;
}

void
GameLogic::start()
{
	userLife_ = 3;
	timeStart_ = std::clock();

	{
		int x = HEIGHT / 2, y = HEIGHT / 2;
		gold_ = new Gold(x, y);

		int i;
		for (i = 0; i < HEIGHT; i += LINE_LENGTH){
			walls_.push_back(Wall(0, i, Forma::LINE_VERTICAL));
			walls_.push_back(Wall(WIDTH - 1, i, Forma::LINE_VERTICAL));
		}

		for (i = 0; i < WIDTH; i += LINE_LENGTH){
			walls_.push_back(Wall(i, 0, Forma::LINE_HORIZONTAL));
			walls_.push_back(Wall(i, HEIGHT - 1, Forma::LINE_HORIZONTAL));
		}

		walls_.push_back(Wall(x - 1, y - 2, Forma::LINE_VERTICAL));
		walls_.push_back(Wall(x - 2, y - 2, Forma::LINE_VERTICAL));

		walls_.push_back(Wall(x + 1, y - 2, Forma::LINE_VERTICAL));
		walls_.push_back(Wall(x + 2, y - 2, Forma::LINE_VERTICAL));

		walls_.push_back(Wall(x - 2, y - 3, Forma::LINE_HORIZONTAL));
		walls_.push_back(Wall(x - 2, y - 4, Forma::LINE_HORIZONTAL));

		walls_.push_back(Wall(x - 2, y + 3, Forma::LINE_HORIZONTAL));
		walls_.push_back(Wall(x - 2, y + 4, Forma::LINE_HORIZONTAL));

		tanks_.push_back(Tank(tanks_.size(), WIDTH / 2, HEIGHT - 10, FORMA_USER_TANK));
	}

	srand(time(0));

	Forma arr[2] = { LINE_VERTICAL, LINE_HORIZONTAL };
	int i, x, y, f, j, notLoop = 0;
	bool addWall = true;

	for (i = 0; i < 20; i++){
		addWall = true;
		x = rand() % (WIDTH - 20) + 10;
		y = rand() % (HEIGHT - 15) + 10;

		f = rand() % 2;
		Wall w(x, y, arr[f]);

		for (j = 0; j < walls_.size(); j++)
			if (w.intersect(walls_[j]) || w.intersect(tanks_[0])){
				i--;
				addWall = false;
				break;
			}

		if (addWall)
			walls_.push_back(w);

		notLoop++;
		if (notLoop == 1000){
			break;
		}
	}

	bool addTank = true;

	for (i = 0; i < 5; i++){
		addTank = true;
		x = rand() % (WIDTH - 5) + 1;
		y = rand() % (HEIGHT - 5) + 1;

		Tank t(tanks_.size(), x, y, FORMA_TANK);

		for (j = 0; j < tanks_.size(); j++){
			if (x > tanks_[j].getX() - 5 && x < tanks_[j].getX() + 5 && y > tanks_[j].getY() - 5 && y < tanks_[j].getY() + 5){
				addTank = false;
				i--;

				break;
			}
		}

		if (addTank == false)
			continue;

		for (j = 0; j < walls_.size(); j++){
			if (walls_[j].intersect(t) || tanks_[0].intersect(t)){
				i--;

				addTank = false;
				break;
			}
		}

		Direction directs[4] = { Direction::DOWN, Direction::LEFT, Direction::RIGHT, Direction::UP };
		if (addTank){
			int d = rand() % 4;
			t.turn(directs[d]);
			tanks_.push_back(t);
		}
	}
}

void
GameLogic::finish()
{
	walls_.clear();
	tanks_.clear();
	shots_.clear();
}

void
GameLogic::moveUserTank(Direction direction)
{
	if (tanks_[0].getHeadDirect() != direction){
		tanks_[0].turn(direction);
	}
	else{
		if (screen_->canMove(tanks_[0], direction))
		tanks_[0].move(direction);
	}
}

void
GameLogic::shoot()
{
	Shot sh = tanks_[0].shoot();

	int i;
	for (i = 0; i < walls_.size(); i++)
		if (sh.intersect(walls_[i]))
			return;

	for (i = 0; i < tanks_.size(); i++)
		if (sh.intersect(tanks_[i]))
			return;

	shots_.push_back(sh);
}

int
GameLogic::update()
{
	int i;
	screen_->clear();
	for (i = 0; i < walls_.size(); i++)
		screen_->show(walls_[i]);

	screen_->show(*gold_);

	std::vector<Shot>::iterator it = shots_.begin();
	bool erase = false;
	for (; it != shots_.end();){
		erase = false;

		it->move();

		if (it->getX() < 0 || it->getX() >= WIDTH || it->getY() < 0 || it->getY() >= HEIGHT){
			it = shots_.erase(it);
			continue;
		}

		for (i = 0; i < walls_.size(); i++)
			if (walls_[i].intersect(*it)){
				walls_[i].attack(*it);

				it = shots_.erase(it);

				erase = true;
				break;
			}

		if (erase == true)
			continue;

		std::vector<Tank>::iterator tankIt = tanks_.begin();
		for (; tankIt != tanks_.end(); ){
			if (tankIt->intersect(*it)){
				if (it->getIdTank() == userTankId_ && tankIt->getId() != userTankId_){
					tankIt = tanks_.erase(tankIt);

					it = shots_.erase(it);
					erase = true;
					break;
				}
				
				if (it->getIdTank() != userTankId_ && tankIt->getId() == userTankId_){
					userLife_--;

					if (userLife_ <= 0)
						return LOSE;

					it = shots_.erase(it);
					erase = true;
					break;
				}
			}

			tankIt++;
		}

		if (tanks_.size() == 1)
			return WIN;

		if (erase)
			continue;

		if (gold_->intersect(*it) && it->getIdTank() != userTankId_)
			return LOSE;

		if (!erase)
			it++;
	}

	strategy_->logic(shots_, walls_, tanks_, gold_);

	for (i = 0; i < shots_.size(); i++)
		screen_->show(shots_[i]);

	for (i = 0; i < tanks_.size(); i++)
		screen_->show(tanks_[i]);


	double duration = (std::clock() - timeStart_) / (double)CLOCKS_PER_SEC;
	screen_->updateScreen(userLife_, tanks_.size() - 1, static_cast<int>(duration));

	return 0;
}