
#ifndef BRICK_H
#define BRICK_H

#include "Coord.h"
#include <iostream>
using namespace std;
#include <vector>

class Brick {
protected:
	vector<Coord> _part;
public:
	Brick();
	~Brick();
	vector<Coord> get_part();
	void set_part(vector<Coord> p);
	virtual void rotate();
	virtual void draw();
	virtual void erase();
	void moveLeft();
	void moveRight();
	bool isHitRightSideWall();
	bool isHitLeftSideWall();
	void fallOne();
};

#endif