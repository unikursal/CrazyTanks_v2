#pragma once

#include<utility>

#include "Util.h"

class Points
{
public:
	Points(int x, int y, const char* ch, int n, Forma);
	virtual ~Points();

	const char* getChars();
	Forma getForma();
	int getX();
	int getY();

protected:
	char chars[9];
	Forma forma;
	int x, y;
};

