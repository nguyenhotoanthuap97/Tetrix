

#ifndef LREVERSE_BRICK_H
#define LREVERSE_BRICK_H

#include "Brick.h"

class LReverse_Brick : public Brick {
public:
	LReverse_Brick();
	~LReverse_Brick();
	LReverse_Brick(Coord);
	virtual void draw();
	virtual void rotate();
};

#endif