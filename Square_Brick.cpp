

#include "Square_Brick.h"

Square_Brick::Square_Brick()
{
}

Square_Brick::~Square_Brick()
{
}

Square_Brick::Square_Brick(Coord topleft)
{
	Coord Ctemp(topleft.getX(), topleft.getY());
	vector<Coord> temp;
	temp.push_back(Ctemp);
	Ctemp.setX(Ctemp.getX() + 5);
	temp.push_back(Ctemp);
	Ctemp.setY(Ctemp.getY() + 3);
	temp.push_back(Ctemp);
	Ctemp.setX(Ctemp.getX() - 5);
	temp.push_back(Ctemp);
	this->set_part(temp);
}

void Square_Brick::rotate()
{
}

void Square_Brick::draw() {
	setTextColor();
	textColor(129);
	Brick::draw();
}