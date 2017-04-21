
#include "Brick.h"

Brick::Brick()
{
}

Brick::~Brick()
{
	this->_part.clear();
}

vector<Coord> Brick::get_part()
{
	return this->_part;
}

void Brick::set_part(vector<Coord> p)
{
	this->_part = p;
}

void Brick::draw()
{
	if (this->_part[0].getY() >= 11) {
		gotoXY(this->_part[0].getX(), this->_part[0].getY());
		cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;
		gotoXY(this->_part[0].getX(), this->_part[0].getY() + 1);
		cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;
		gotoXY(this->_part[0].getX(), this->_part[0].getY() + 2);
		cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;
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

void Brick::erase() {
	setTextColor();
	textColor(0);
	for (int i = 0; i < 4; i++) {
		if (this->_part[i].getY() >= 11) {
			gotoXY(this->_part[i].getX(), this->_part[i].getY());
			cout << "     ";
			gotoXY(this->_part[i].getX(), this->_part[i].getY() + 1);
			cout << "     ";
			gotoXY(this->_part[i].getX(), this->_part[i].getY() + 2);
			cout << "     ";
		}
	}
}

void Brick::rotate() {
}

void Brick::moveLeft() {
	for (int i = 0; i < 4; i++) {
		this->_part[i].setX(this->_part[i].getX() - 5);
	}
}

void Brick::moveRight() {
	for (int i = 0; i < 4; i++) {
		this->_part[i].setX(this->_part[i].getX() + 5);
	}
}

bool Brick::isHitLeftSideWall() {
	for (int i = 0; i < 4; i++) {
		if (this->_part[i].getX() == 6) {
			return true;
		}
	}
	return false;
}

bool Brick::isHitRightSideWall() {
	for (int i = 0; i < 4; i++) {
		if (this->_part[i].getX() == 41) {
			return true;
		}
	}
	return false;
}

void Brick::fallOne() {
	for (int i = 0; i < 4; i++) {
		this->_part[i].setY(this->_part[i].getY() + 3);
	}
}