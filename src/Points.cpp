#include "Points.h"

Points::Points(int x, int y, const char* ch, int width, int height)
{
	x_ = x;
	y_ = y;

	width_ = width;
	height_ = height;

	int i, n = width * height;
	for (i = 0; i < n; i++){
		chars_[i] = ch[i];
	}
}


Points::~Points()
{
}

const char*
Points::getChars() const
{
	return chars_;
}

int
Points::getWidth() const
{
	return width_;
}

int
Points::getHeight() const
{
	return height_;
}

int
Points::getX() const
{
	return x_;
}

int
Points::getY() const
{
	return y_;
}

bool
Points::intersect(const Points& inpPoints) const
{
	int inpX = inpPoints.getX(), inpY = inpPoints.getY(), inpWidth = inpPoints.getWidth(), inpHeight = inpPoints.getHeight();

	return intersect(inpX, inpY, inpWidth, inpHeight);
}

bool
Points::intersect(int inpX, int inpY, int inpWidth, int inpHeight) const
{
	int i, j, k, l;

	for (i = y_; i < y_ + height_; i++)
		for (j = x_; j < x_ + width_; j++)
			for (k = inpY; k < inpY + inpHeight; k++)
				for (l = inpX; l < inpX + inpWidth; l++)
					if (i == k && j == l)
						return true;

	return false;
}
