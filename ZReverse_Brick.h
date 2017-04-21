

#ifndef ZREVERSE_BRICK_H
#define ZREVERSE_BRICK_H

#include "Brick.h"

class ZReverse_Brick : public Brick {
public:
	ZReverse_Brick();
	~ZReverse_Brick();
	ZReverse_Brick(Coord);
	virtual void rotate();
	virtual void draw();
};

#endif