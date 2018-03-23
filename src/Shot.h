#ifndef SHOT_H
#define SHOT_H

#include "Points.h"
#include "Util.h"

class Shot :
	public Points
{
public:
	Shot(int id, int x, int y, Direction);
	~Shot();

	void move();
	int getIdTank() const;
	Direction getDirection() const;

private:
	int idTank_;
	Direction direction_;

};
#endif SHOT_H

