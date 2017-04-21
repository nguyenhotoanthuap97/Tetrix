

#ifndef I_BRICK_H
#define I_BRICK_H

#include "Brick.h"

class I_Brick : public Brick {
public:
	I_Brick();
	~I_Brick();
	I_Brick(Coord);
	virtual void draw();
	virtual void rotate();
};

#endif