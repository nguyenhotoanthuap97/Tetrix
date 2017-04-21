

#ifndef Z_BRICK_H
#define Z_BRICK_H

#include "Brick.h"

class Z_Brick : public Brick {
public:
	Z_Brick();
	~Z_Brick();
	Z_Brick(Coord);
	virtual void rotate();
	virtual void draw();
};

#endif