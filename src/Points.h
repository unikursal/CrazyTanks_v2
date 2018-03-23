#ifndef POINTS_H
#define POINTS_H

#include<utility>

#include "Util.h"

class Points
{
public:
	Points(int x, int y, const char* ch, int n, Forma);
	virtual ~Points();

	const char* getChars() const;
	Forma getForma() const;
	int getX() const;
	int getY() const;
	bool intersect(const Points&) const;

protected:
	char chars_[9];
	Forma forma_;
	int x_, y_;
};
#endif POINTS_H
