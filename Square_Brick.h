

#ifndef SQUARE_BRICK_H
#define SQUARE_BRICK_H

#include "Brick.h"

class Square_Brick : public Brick {
public:
	Square_Brick();
	~Square_Brick();
	Square_Brick(Coord);
	virtual void rotate();
	virtual void draw();
};

#endif