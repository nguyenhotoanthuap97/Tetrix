

//Coord class

#ifndef COORD_H
#define COORD_H

#include "Windows.h"
#include "time.h"
#include <conio.h>

//Macro set text's colors
#define setTextColor() HANDLE Color; Color = GetStdHandle(STD_OUTPUT_HANDLE);
#define textColor(...) SetConsoleTextAttribute(Color, __VA_ARGS__);

class Coord {
private:
	int _x;
	int _y;
public:
	Coord();
	~Coord();
	Coord(int, int);
	int getX();
	int getY();
	void setX(int X);
	void setY(int Y);
	void xIncrease();
	void yIncrease();
	void xDecrease();
	void yDecrease();
};

#endif

//gotoXY function
void gotoXY(int x, int y);