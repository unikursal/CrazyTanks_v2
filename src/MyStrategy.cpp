#include "MyStrategy.h"


MyStrategy::MyStrategy()
{
}


MyStrategy::~MyStrategy()
{
}

void
MyStrategy::logic(std::vector<Shot>& shots, std::vector<Wall>& walls, std::vector<Tank>&, Gold* gold)
{

}

bool
MyStrategy::canShoot(std::vector<Tank>&, std::vector<Wall>&, Gold*)
{
	return false;
}