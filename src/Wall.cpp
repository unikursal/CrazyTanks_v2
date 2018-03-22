#include "Wall.h"


Wall::Wall(int x, int y, Forma f) : Points(x, y, FORMA_WALL, LINE_LENGTH, f)
{
}


Wall::~Wall()
{
}
