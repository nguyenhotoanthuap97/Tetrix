

#include "Z_Brick.h"

Z_Brick::Z_Brick()
{
}

Z_Brick::~Z_Brick()
{
}

Z_Brick::Z_Brick(Coord topright)
{
	Coord Ctemp(topright.getX(), topright.getY());
	vector<Coord> temp;
	temp.push_back(Ctemp);
	Ctemp.setY(Ctemp.getY() + 3);
	temp.push_back(Ctemp);
	Ctemp.setX(Ctemp.getX() - 5);
	temp.push_back(Ctemp);
	Ctemp.setY(Ctemp.getY() + 3);
	temp.push_back(Ctemp);
	this->set_part(temp);
}

void Z_Brick::rotate()
{
	if (this->_part[0].getY() < this->_part[1].getY() && this->_part[0].getX() <= 36 && this->_part[3].getX() >= 6) {
		this->_part[0].setX(this->_part[0].getX() + 5);
		this->_part[0].setY(this->_part[0].getY() + 3);
		this->_part[1].setX(this->_part[1].getX());
		this->_part[1].setY(this->_part[1].getY());
		this->_part[2].setX(this->_part[2].getX() + 5);
		this->_part[2].setY(this->_part[2].getY() - 3);
		this->_part[3].setX(this->_part[3].getX());
		this->_part[3].setY(this->_part[3].getY() - 6);
	}
	else if (this->_part[0].getX() > this->_part[1].getX()) {
		this->_part[0].setX(this->_part[0].getX() - 5);
		this->_part[0].setY(this->_part[0].getY() - 3);
		this->_part[1].setX(this->_part[1].getX());
		this->_part[1].setY(this->_part[1].getY());
		this->_part[2].setX(this->_part[2].getX() - 5);
		this->_part[2].setY(this->_part[2].getY() + 3);
		this->_part[3].setX(this->_part[3].getX());
		this->_part[3].setY(this->_part[3].getY() + 6);
	}
}

void Z_Brick::draw() {
	setTextColor();
	textColor(130);
	Brick::draw();
}