#include "Points.h"


Points::Points(int x, int y, const char* ch, int n, Forma forma)
{
	x_ = x;
	y_ = y;

	forma_ = forma;

	int i;
	for (i = 0; i < n; i++)
		chars_[i] = ch[i];
}


Points::~Points()
{
}

const char*
Points::getChars() const
{
	return chars_;
}

Forma
Points::getForma() const
{
	return forma_;
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
Points::intersect(const Points& inpPints) const
{
	int width, height, inpX = inpPints.getX(), inpY = inpPints.getY(), inpWidth, inpHeight;
	switch (forma_){
	case Forma::ONE :
		width = 1;
		height = 1;
		break;
	case Forma::LINE_HORIZONTAL :
		width = LINE_LENGTH;
		height = 1;
		break;
	case Forma::LINE_VERTICAL :
		width = 1;
		height = LINE_LENGTH;
		break;
	case Forma::SQUARE :
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
					if (i == k && j == l)
						return true;

	return false;

}