

#ifndef GAME_H
#define GAME_H

#include "L_Brick.h"
#include "LReverse_Brick.h"
#include "I_Brick.h"
#include "Z_Brick.h"
#include "ZReverse_Brick.h"
#include "HalfCross_Brick.h"
#include "Square_Brick.h"

//struct background brick
struct Space {
	Coord pos;
	bool isFilled;
};

class Game {
private:
	Brick *_current;
	Brick *_after;
	Space _ground[14][8];
	int _score;
public:
	Game();
	~Game();
	void reset_ground();
	bool isHit_Ground(Brick *_block);
	bool isHit(Brick *_block);
	bool isHitSideWay(Brick *_block);
	void hittedDraw();
	void scoreDraw(int, vector<int>);
	int fallAllWayDown();
	bool play();
	void scoreCal(vector<int> isScored);
	void eraseAfterScored(vector<int>);
	void reDrawBlock(int, int);
	bool isFull(int);
	bool isOver();
};

#endif