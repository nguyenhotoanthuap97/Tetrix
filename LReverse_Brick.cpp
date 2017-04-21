
#include "LReverse_Brick.h"


LReverse_Brick::LReverse_Brick()
{
}

LReverse_Brick::~LReverse_Brick()
{
}

LReverse_Brick::LReverse_Brick(Coord topright)
{
	Coord Ctemp(topright.getX(), topright.getY());
	vector<Coord> temp;
	temp.push_back(Ctemp);
	Ctemp.setY(Ctemp.getY() + 3);
	temp.push_back(Ctemp);
	Ctemp.setY(Ctemp.getY() + 3);
	temp.push_back(Ctemp);
	Ctemp.setX(Ctemp.getX() - 5);
	temp.push_back(Ctemp);
	this->set_part(temp);
}

void LReverse_Brick::rotate()
{
	if (this->_part[0].getY() < this->_part[1].getY() && this->_part[0].getX() <= 36 && this->_part[3].getX() >= 6) {
		this->_part[0].setX(this->_part[0].getX() + 5);
		this->_part[0].setY(this->_part[0].getY() + 6);
		this->_part[1].setX(this->_part[1].getX());
		this->_part[1].setY(this->_part[1].getY() + 3);
		this->_part[2].setX(this->_part[2].getX() - 5);
		this->_part[2].setY(this->_part[2].getY());
		this->_part[3].setX(this->_part[3].getX());
		this->_part[3].setY(this->_part[3].getY() - 3);
	}
	else if (this->_part[0].getX() > this->_part[1].getX()) {
		this->_part[0].setX(this->_part[0].getX() - 10);
		this->_part[0].setY(this->_part[0].getY());
		this->_part[1].setX(this->_part[1].getX() - 5);
		this->_part[1].setY(this->_part[1].getY() - 3);
		this->_part[2].setX(this->_part[2].getX());
		this->_part[2].setY(this->_part[2].getY() - 6);
		this->_part[3].setX(this->_part[3].getX() + 5);
		this->_part[3].setY(this->_part[3].getY() - 3);
	}
	else if (this->_part[0].getY() > this->_part[1].getY() && this->_part[3].getX() <= 36 && this->_part[0].getX() >= 6) {
		this->_part[0].setX(this->_part[0].getX());
		this->_part[0].setY(this->_part[0].getY() - 3);
		this->_part[1].setX(this->_part[1].getX() + 5);
		this->_part[1].setY(this->_part[1].getY());
		this->_part[2].setX(this->_part[2].getX() + 10);
		this->_part[2].setY(this->_part[2].getY() + 3);
		this->_part[3].setX(this->_part[3].getX() + 5);
		this->_part[3].setY(this->_part[3].getY() + 6);
	}
	else if (this->_part[0].getX() < this->_part[1].getX()) {
		this->_part[0].setX(this->_part[0].getX() + 5);
		this->_part[0].setY(this->_part[0].getY() - 3);
		this->_part[1].setX(this->_part[1].getX());
		this->_part[1].setY(this->_part[1].getY());
		this->_part[2].setX(this->_part[2].getX() - 5);
		this->_part[2].setY(this->_part[2].getY() + 3);
		this->_part[3].setX(this->_part[3].getX() - 10);
		this->_part[3].setY(this->_part[3].getY());
	}
}


void LReverse_Brick::draw() {
	setTextColor();
	textColor(133);
	Brick::draw();
}