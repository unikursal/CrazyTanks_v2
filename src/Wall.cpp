#include "Wall.h"


Wall::Wall(int x, int y, int width, int height) : Points(x, y, FORMA_WALL, width, height)
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
Wall::intersect(const Points& inpPoints) const
{
	int inpX = inpPoints.getX(), inpY = inpPoints.getY(), inpWidth = inpPoints.getWidth(), inpHeight = inpPoints.getHeight();

	int i, j, k, l;

	for (i = y_; i < y_ + height_; i++)
		for (j = x_; j < x_ + width_; j++)
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