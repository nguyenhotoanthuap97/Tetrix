

#ifndef L_BRICK_H
#define L_BRICK_H

#include "Brick.h"

class L_Brick : public Brick {
public:
	L_Brick();
	~L_Brick();
	L_Brick(Coord);
	virtual void draw();
	virtual void rotate();
};

#endif