#include "Wall.h"


Wall::Wall(int x, int y, Forma f) : Points(x, y, FORMA_WALL, LINE_LENGTH, f)
{
	int i;
	for (i = 0; i < LINE_LENGTH; i++)
		strong_[i] = strongWall_;
}


Wall::~Wall()
{
}

void
Wall::attack(Shot shot)
{
	int n = x_ - shot.getX() == 0 ? y_ - shot.getY() : x_ - shot.getX();

	if (n >= LINE_LENGTH)
		return;

	if (n < 0)
		n *= -1;

	if (strong_[n] <= 0)
		return;

	strong_[n]--;

	if (strong_[n] <= 0)
		chars_[n] = ' ';
}

bool
Wall::intersect(const Points& inpPints) const
{
	int width, height, inpX = inpPints.getX(), inpY = inpPints.getY(), inpWidth, inpHeight;
	switch (forma_){
	case Forma::ONE:
		width = 1;
		height = 1;
		break;
	case Forma::LINE_HORIZONTAL:
		width = LINE_LENGTH;
		height = 1;
		break;
	case Forma::LINE_VERTICAL:
		width = 1;
		height = LINE_LENGTH;
		break;
	case Forma::SQUARE:
		width = SQUARE_LINE;
		height = SQUARE_LINE;
		break;
	}

	switch (inpPints.getForma()){
	case Forma::ONE:
		inpWidth = 1;
		inpHeight = 1;
		break;
	case Forma::LINE_HORIZONTAL:
		inpWidth = LINE_LENGTH;
		inpHeight = 1;
		break;
	case Forma::LINE_VERTICAL:
		inpWidth = 1;
		inpHeight = LINE_LENGTH;
		break;
	case Forma::SQUARE:
		inpWidth = SQUARE_LINE;
		inpHeight = SQUARE_LINE;
		break;
	}

	int i, j, k, l;

	for (i = y_; i < y_ + height; i++)
		for (j = x_; j < x_ + width; j++)
			for (k = inpY; k < inpY + inpHeight; k++)
				for (l = inpX; l < inpX + inpWidth; l++)
					if (i == k && j == l){
						int n = x_ - inpX == 0 ? y_ - inpY : x_ - inpX;

						if (n < 0)
							n *= -1;

						if (strong_[n] <= 0)
							return false;
						else
							return true;
					}

	return false;
}