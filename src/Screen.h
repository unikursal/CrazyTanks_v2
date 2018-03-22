#pragma once

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

	void updateScreen() const;
	void show(Points);
	void clear();
	bool canMove(Points, Direction);

private:
	char** arrayChar;
};

