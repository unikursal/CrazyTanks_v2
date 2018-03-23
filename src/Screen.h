#ifndef SCREEN_H
#define SCREEN_H

#include<iostream>
#include<vector>

#include<Windows.h>

#include "Util.h"
#include "Points.h"

class Screen
{
public:
	Screen();
	~Screen();

	void updateScreen(int usrLife, int numbTanks, int second) const;
	void show(const Points&);
	void clear();
	bool canMove(const Points&, Direction) const;

private:
	char** arrayChar_;
};

#endif SCREEN_H

