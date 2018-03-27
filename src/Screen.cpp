#include "Screen.h"

Screen::Screen()
{
	arrayChar_ = new char*[HEIGHT];

	int i;
	for (i = 0; i < HEIGHT; i++)
		arrayChar_[i] = new char[WIDTH + 1];

	int j;
	for (i = 0; i < HEIGHT; i++){
		arrayChar_[i][WIDTH] = '\0';

		for (j = 0; j < WIDTH; j++)
			arrayChar_[i][j] = ' ';
	}
}


Screen::~Screen()
{
	int i;
	for (i = 0; i < HEIGHT; i++)
		delete[] arrayChar_[i];

	delete[] arrayChar_;
}

void
Screen::show(const Points& points)
{
	int i, j, x = points.getX(), y = points.getY(), width = points.getWidth(), height = points.getHeight();

	const char* arrChar = points.getChars();

	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
		arrayChar_[y + i][x + j] = arrChar[i * width + j];
}

void
Screen::clear()
{
	int i, j;
	for (i = 0; i < HEIGHT; i++)
		for (j = 0; j < WIDTH; j++){
			arrayChar_[i][j] = ' ';
		}
}

bool
Screen::canMove(const Points& points, Direction direction) const
{
	int width = points.getWidth(), height = points.getHeight();

	int x = points.getX(), y = points.getY(), i;

	switch (direction){
	case Direction::DOWN:
		if (y + height >= HEIGHT)
			return false;

		for (i = 0; i < width; i++)
			if (arrayChar_[y + height][x + i] != ' ')
				return false;
		break;
	case Direction::LEFT:
		if (x - 1 < 0 )
			return false;

		for (i = 0; i < height; i++)
			if (arrayChar_[y + i][x - 1] != ' ')
				return false;

		break;
	case Direction::RIGHT:
		if (x + width >= WIDTH )
			return false;

		for (i = 0; i < height; i++)
			if (arrayChar_[y + i][x + width] != ' ')
				return false;

		break;
	case Direction::UP:
		if (y - 1 < 0 )
			return false;

		for (i = 0; i < width; i++)
			if (arrayChar_[y - 1][x + i] != ' ')
				return false;
		break;
	}

	return true;
}

void
Screen::updateScreen(int usrLife, int numbTanks, int second) const
{
	COORD coord;
	coord.X = 0;
	coord.Y = 0;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	int i;
	for (i = 0; i < HEIGHT; i++)
		std::fputs(arrayChar_[i], stdout);

	std::cout << "\nNumber tanks : " << numbTanks << "\n";
	std::cout << "\nUser life : " << usrLife << "\n";
	std::cout << "\nSeconds : " << second << "\n";
}