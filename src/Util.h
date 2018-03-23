#ifndef UTIL_H
#define UTIL_H

static const int WIDTH = 80, HEIGHT = 40, LINE_LENGTH = 5, SQUARE_LINE = 3;

static const int LOSE = 1, WIN = 2;

static const  char FORMA_USER_TANK[9] = { ' ', '0', ' ', '0', '0', '0', '0', ' ', '0' };
static const  char FORMA_TANK[9] = { ' ', '#', ' ', '#', '#', '#', '#', ' ', '#' };
static const char FORMA_WALL[6] = { '|', '|', '|', '|', '|' };
static const char FORMA_SHOT[1] = { '*' };
static const char FORMA_GOLD[1] = { '+' };

enum Direction{ UP = 1, LEFT = 3, RIGHT = 5, DOWN = 7 };
enum Forma{LINE_HORIZONTAL, LINE_VERTICAL, SQUARE, ONE};

#endif UTIL_H