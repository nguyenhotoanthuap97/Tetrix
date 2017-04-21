

#ifndef HALFCROSS_BRICK_H
#define HALFCROSS_BRICK_H

#include "Brick.h"

class HalfCross_Brick : public Brick {
public:
	HalfCross_Brick();
	~HalfCross_Brick();
	HalfCross_Brick(Coord);
	virtual void rotate();
	virtual void draw();
};

#endif