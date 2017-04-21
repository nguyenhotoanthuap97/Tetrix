
#include "I_Brick.h"

I_Brick::I_Brick()
{
}

I_Brick::~I_Brick()
{
}

I_Brick::I_Brick(Coord top)
{
	Coord Ctemp(top.getX(), top.getY());
	vector<Coord> temp;
	temp.push_back(Ctemp);
	Ctemp.setY(Ctemp.getY() + 3);
	temp.push_back(Ctemp);
	Ctemp.setY(Ctemp.getY() + 3);
	temp.push_back(Ctemp);
	Ctemp.setY(Ctemp.getY() + 3);
	temp.push_back(Ctemp);
	this->set_part(temp);
}

void I_Brick::rotate()
{
	if (this->_part[0].getY() < this->_part[1].getY() && this->_part[0].getX() <= 36 && this->_part[0].getX() >= 16) {
		this->_part[0].setX(this->_part[0].getX() + 5);
		this->_part[0].setY(this->_part[0].getY() + 3);
		this->_part[1].setX(this->_part[1].getX());
		this->_part[1].setY(this->_part[1].getY());
		this->_part[2].setX(this->_part[2].getX() - 5);
		this->_part[2].setY(this->_part[2].getY() - 3);
		this->_part[3].setX(this->_part[3].getX() - 10);
		this->_part[3].setY(this->_part[3].getY() - 6);
	}
	else if (this->_part[0].getX() > this->_part[1].getX()) {
		this->_part[0].setX(this->_part[0].getX() - 5);
		this->_part[0].setY(this->_part[0].getY() - 3);
		this->_part[1].setX(this->_part[1].getX());
		this->_part[1].setY(this->_part[1].getY());
		this->_part[2].setX(this->_part[2].getX() + 5);
		this->_part[2].setY(this->_part[2].getY() + 3);
		this->_part[3].setX(this->_part[3].getX() + 10);
		this->_part[3].setY(this->_part[3].getY() + 6);
	}
}

void I_Brick::draw() {
	setTextColor();
	textColor(139);
	Brick::draw();
}