#include "Points.h"


Points::Points(int x, int y, const char* ch, int n, Forma f)
{
	this->x = x;
	this->y = y;

	forma = f;

	int i;
	for (i = 0; i < n; i++)
		chars[i] = ch[i];
}


Points::~Points()
{
}

const char*
Points::getChars()
{
	return chars;
}

Forma
Points::getForma()
{
	return forma;
}

int
Points::getX()
{
	return x;
}

int
Points::getY()
{
	return y;
}
