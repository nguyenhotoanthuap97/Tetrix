

//define all Coord class's function

#include "Coord.h"

Coord::Coord()
{
}


Coord::Coord(int xt, int yt)
{
	this->_x = xt;
	this->_y = yt;
}

Coord::~Coord()
{
	this->_x = 0;
	this->_y = 0;
}

int Coord::getX()
{
	return this->_x;
}

int Coord::getY()
{
	return this->_y;
}

void Coord::setX(int xt)
{
	this->_x = xt;
}

void Coord::setY(int yt)
{
	this->_y = yt;
}

void Coord::xIncrease()
{
	(this->_x)++;
}

void Coord::xDecrease()
{
	(this->_x)--;
}

void Coord::yIncrease()
{
	(this->_y)++;
}

void Coord::yDecrease()
{
	(this->_y)--;
}

//Goto x y
void gotoXY(int x, int y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };
	SetConsoleCursorPosition(hStdout, position);
}