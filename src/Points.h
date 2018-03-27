#ifndef POINTS_H
#define POINTS_H

#include<utility>

#include "Util.h"

class Points
{
public:
	Points(int x, int y, const char* ch, int width, int height);
	~Points();

	const char* getChars() const;
	int getX() const;
	int getY() const;
	int getWidth() const;
	int getHeight() const;
	bool intersect(const Points&) const;
	bool intersect(int x, int y, int width, int height) const;

protected:
	char chars_[9];
	int x_, y_;
	int width_, height_;
};
#endif POINTS_H
