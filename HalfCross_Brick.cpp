

#include "HalfCross_Brick.h"


HalfCross_Brick::HalfCross_Brick()
{
}

HalfCross_Brick::~HalfCross_Brick()
{
}

HalfCross_Brick::HalfCross_Brick(Coord topright)
{
	Coord Ctemp(topright.getX(), topright.getY());
	vector<Coord> temp;
	temp.push_back(Ctemp);
	Ctemp.setY(Ctemp.getY() + 3);
	Ctemp.setX(Ctemp.getX() - 5);
	temp.push_back(Ctemp);
	Ctemp.setX(Ctemp.getX() + 5);
	temp.push_back(Ctemp);
	Ctemp.setY(Ctemp.getY() + 3);
	temp.push_back(Ctemp);
	this->set_part(temp);
}

void HalfCross_Brick::rotate()
{
	if (this->_part[0].getY() < this->_part[2].getY() && this->_part[0].getX() <= 36 && this->_part[1].getX() >= 6) {
		this->_part[0].setX(this->_part[0].getX() + 5);
		this->_part[0].setY(this->_part[0].getY() + 3);
		this->_part[1].setX(this->_part[1].getX() + 5);
		this->_part[1].setY(this->_part[1].getY() - 3);
		this->_part[2].setX(this->_part[2].getX());
		this->_part[2].setY(this->_part[2].getY());
		this->_part[3].setX(this->_part[3].getX() - 5);
		this->_part[3].setY(this->_part[3].getY() - 3);
	}
	else if (this->_part[0].getX() > this->_part[2].getX()) {
		this->_part[0].setX(this->_part[0].getX() - 5);
		this->_part[0].setY(this->_part[0].getY() + 3);
		this->_part[1].setX(this->_part[1].getX() + 5);
		this->_part[1].setY(this->_part[1].getY() + 3);
		this->_part[2].setX(this->_part[2].getX());
		this->_part[2].setY(this->_part[2].getY());
		this->_part[3].setX(this->_part[3].getX() + 5);
		this->_part[3].setY(this->_part[3].getY() - 3);
	}
	else if (this->_part[0].getY() > this->_part[2].getY() && this->_part[0].getX() <= 36 && this->_part[0].getX() >= 11) {
		this->_part[0].setX(this->_part[0].getX() - 5);
		this->_part[0].setY(this->_part[0].getY() - 3);
		this->_part[1].setX(this->_part[1].getX() - 5);
		this->_part[1].setY(this->_part[1].getY() + 3);
		this->_part[2].setX(this->_part[2].getX());
		this->_part[2].setY(this->_part[2].getY());
		this->_part[3].setX(this->_part[3].getX() + 5);
		this->_part[3].setY(this->_part[3].getY() + 3);
	}
	else if (this->_part[0].getX() < this->_part[2].getX()) {
		this->_part[0].setX(this->_part[0].getX() + 5);
		this->_part[0].setY(this->_part[0].getY() - 3);
		this->_part[1].setX(this->_part[1].getX() - 5);
		this->_part[1].setY(this->_part[1].getY() - 3);
		this->_part[2].setX(this->_part[2].getX());
		this->_part[2].setY(this->_part[2].getY());
		this->_part[3].setX(this->_part[3].getX() - 5);
		this->_part[3].setY(this->_part[3].getY() + 3);
	}
}

void HalfCross_Brick::draw() {
	setTextColor();
	textColor(142);
	if (this->_part[0].getY() >= 11) {
		gotoXY(this->_part[0].getX(), this->_part[0].getY());
		cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;
		gotoXY(this->_part[0].getX(), this->_part[0].getY() + 1);
		cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;
		gotoXY(this->_part[0].getX(), this->_part[0].getY() + 2);
		cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;
	}

	if (this->_part[1].getY() >= 11) {
		gotoXY(this->_part[1].getX(), this->_part[1].getY());
		cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;
		gotoXY(this->_part[1].getX(), this->_part[1].getY() + 1);
		cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;
		gotoXY(this->_part[1].getX(), this->_part[1].getY() + 2);
		cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;
	}
	if (this->_part[2].getY() >= 11) {
		gotoXY(this->_part[2].getX(), this->_part[2].getY());
		cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;
		gotoXY(this->_part[2].getX(), this->_part[2].getY() + 1);
		cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;
		gotoXY(this->_part[2].getX(), this->_part[2].getY() + 2);
		cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;
	}
	if (this->_part[3].getY() >= 11) {
		gotoXY(this->_part[3].getX(), this->_part[3].getY());
		cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;
		gotoXY(this->_part[3].getX(), this->_part[3].getY() + 1);
		cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;
		gotoXY(this->_part[3].getX(), this->_part[3].getY() + 2);
		cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;
	}
}