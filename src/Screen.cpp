#include "Screen.h"


Screen::Screen()
{
	arrayChar = new char*[HEIGHT];

	int i;
	for (i = 0; i < HEIGHT; i++)
		arrayChar[i] = new char[WIDTH + 1];

	int j;
	for (i = 0; i < HEIGHT; i++){
		arrayChar[i][WIDTH] = '\0';

		for (j = 0; j < WIDTH; j++)
			arrayChar[i][j] = ' ';
	}
}


Screen::~Screen()
{
	int i;
	for (i = 0; i < HEIGHT; i++)
		delete[] arrayChar[i];

	delete[] arrayChar;
}

void
Screen::show(Points points)
{
	int i, j, x, y;
	const char* arrChar = points.getChars();

	switch (points.getForma()){
	case Forma::LINE_VERTICAL :
		y = points.getY();
		x = points.getX();

		for (i = 0; i < LINE_LENGTH; i++)
			arrayChar[y + i][x] = arrChar[i];

		break;
	case Forma::LINE_HORIZONTAL:
		y = points.getY();
		x = points.getX();

		for (i = 0; i < LINE_LENGTH; i++)
			arrayChar[y][x + i] = arrChar[i];
			
		break;
	case Forma::ONE :
		arrayChar[points.getY()][points.getX()] = arrChar[0];

		break;
	case Forma::SQUARE :
		x = points.getX();
		y = points.getY();

		for (i = 0; i < SQUARE_LINE; i++)
			for (j = 0; j < SQUARE_LINE; j++)
				arrayChar[y + i][x + j] = arrChar[i * 3 + j];

		break;
	}
}

void
Screen::clear()
{
	int i, j;
	for (i = 0; i < HEIGHT; i++)
		for (j = 0; j < WIDTH; j++){
			arrayChar[i][j] = ' ';
		}
}

bool
Screen::canMove(Points points, Direction direction)
{
	int width, height;
	switch (points.getForma()){
		case Forma::ONE:
			width = 1;
			height = 1;
			break;
		case Forma::SQUARE:
			width = SQUARE_LINE;
			height = SQUARE_LINE;
			break;
		default:
			return false;
	}

	int x = points.getX(), y = points.getY(), i;

	switch (direction){
	case Direction::DOWN:
		if (y + height >= HEIGHT)
			return false;

		for (i = 0; i < width; i++)
			if (arrayChar[y + height][x + i] != ' ')
				return false;
		break;
	case Direction::LEFT:
		if (x - 1 < 0 )
			return false;

		for (i = 0; i < height; i++)
			if (arrayChar[y + i][x - 1] != ' ')
				return false;

		break;
	case Direction::RIGHT:
		if (x + width >= WIDTH )
			return false;

		for (i = 0; i < height; i++)
			if (arrayChar[y + i][x + width] != ' ')
				return false;

		break;
	case Direction::UP:
		if (y - 1 < 0 )
			return false;

		for (i = 0; i < width; i++)
			if (arrayChar[y - 1][x + i] != ' ')
				return false;
		break;
	}

	return true;
}

void
Screen::updateScreen() const
{
	COORD coord;
	coord.X = 0;
	coord.Y = 0;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	int i;
	for (i = 0; i < HEIGHT; i++)
		std::fputs(arrayChar[i], stdout);
}