
#include "Game.h"

Game::Game() {
	int id = 0;
	Coord initialPos(26, -1);

	this->_score = 0;

	for (int i = 0; i < 14; i++)
		for (int j = 0; j < 8; j++) {
			this->_ground[i][j].pos.setX(6 + j * 5);
			this->_ground[i][j].pos.setY(47 - i * 3);
			this->_ground[i][j].isFilled = false;
		}
	
	id = rand() % 7; // 7

	switch (id) {
	case 0: this->_current = new L_Brick(initialPos);
		break;
	case 1:	this->_current = new LReverse_Brick(initialPos);
		break;
	case 2: this->_current = new Z_Brick(initialPos);
		break;
	case 3: this->_current = new ZReverse_Brick(initialPos);
		break;
	case 4: initialPos.setY(initialPos.getY() - 3);
		this->_current = new I_Brick(initialPos);
		break;
	case 5: initialPos.setY(initialPos.getY());
		this->_current = new HalfCross_Brick(initialPos);
		break;
	case 6: initialPos.setY(initialPos.getY() + 3);
		this->_current = new Square_Brick(initialPos);
		break;
	}

	id = rand() % 7; //7

	switch (id) {
	case 0: this->_after = new L_Brick(initialPos);
		break;
	case 1:	this->_after = new LReverse_Brick(initialPos);
		break;
	case 2: this->_after = new Z_Brick(initialPos);
		break;
	case 3: this->_after = new ZReverse_Brick(initialPos);
		break;
	case 4: initialPos.setY(initialPos.getY() - 3);
		this->_after = new I_Brick(initialPos);
		break;
	case 5: initialPos.setY(initialPos.getY());
		this->_after = new HalfCross_Brick(initialPos);
		break;
	case 6: initialPos.setY(initialPos.getY() + 3);
		this->_after = new Square_Brick(initialPos);
		break;
	}
}

Game::~Game() {
	delete this->_current;
	delete this->_after;
	this->_score = 0;
}

void Game::reset_ground() {
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 8; j++) {
			this->_ground[i][j].isFilled = false;
		}
	}
}

bool Game::isHit_Ground(Brick *_block) {
	for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 14; j++) {
			for (int k = 0; k < 8; k++) {
				if (_block->get_part()[i].getX() == this->_ground[j][k].pos.getX() && _block->get_part()[i].getY() == this->_ground[j][k].pos.getY()) {
					if (this->_ground[j][k].isFilled == true) {
						for (int a = 0; a < 4; a++) {
							for (int b = 0; b < 14; b++) {
								for (int c = 0; c < 8; c++) {
									if (_block->get_part()[a].getX() == this->_ground[b][c].pos.getX() && _block->get_part()[a].getY() - 3 == this->_ground[b][c].pos.getY()) {
										this->_ground[b][c].isFilled = true;
									}
								}
							}
						}
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool Game::isHit(Brick *_block) {
	if (isHit_Ground(_block)) {
		return true;
	}
	for (int i = 0; i < 4; i++) {
		if (_block->get_part()[i].getY() > 47)
		{
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 14; j++) {
					for (int k = 0; k < 8; k++) {
						if (_block->get_part()[i].getX() == this->_ground[j][k].pos.getX() && _block->get_part()[i].getY() - 3 == this->_ground[j][k].pos.getY()) {
							this->_ground[j][k].isFilled = true;
						}
					}
				}
			}
			return true;
		}
	}
	return false;
}

bool Game::isHitSideWay(Brick *_block) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 14; j++) {
			for (int k = 0; k < 8; k++) {
				if (_block->get_part()[i].getX() == this->_ground[j][k].pos.getX() && _block->get_part()[i].getY() == this->_ground[j][k].pos.getY()) {
					if (this->_ground[j][k].isFilled == true) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

void Game::hittedDraw() {
	setTextColor();
	textColor(7);

	vector<int> isScored;

	if (this->_current->get_part()[0].getX() < this->_current->get_part()[1].getX() && this->_current->get_part()[0].getY() < this->_current->get_part()[1].getY()) {
		for (int i = 0; i < 4; i++) {
			if (i != 1) {
				if (this->_ground[12 - ((this->_current->get_part()[i].getY() - 11) / 3)][(this->_current->get_part()[i].getX() - 6) / 5].isFilled == true) {
					if ((this->isFull(12 - ((this->_current->get_part()[i].getY() - 11) / 3)) && isScored.size() == 0) || (this->isFull(12 - ((this->_current->get_part()[i].getY() - 11) / 3)) && isScored.size() > 0 && isScored[isScored.size() - 1] != 12 - ((this->_current->get_part()[i].getY() - 11) / 3)))
						isScored.push_back(12 - ((this->_current->get_part()[i].getY() - 11) / 3));

					if (((12 - ((this->_current->get_part()[i].getY() - 11) / 3)) % 2 == 0 && ((this->_current->get_part()[i].getX() - 6) / 5) % 2 == 0) || ((12 - ((this->_current->get_part()[i].getY() - 11) / 3)) % 2 != 0 && ((this->_current->get_part()[i].getX() - 6) / 5) % 2 != 0)) {
						if (this->_current->get_part()[i].getY() >= 11) {
							gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY());
							cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;

							gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY() + 1);
							cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;

							gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY() + 2);
							cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;
						}
					}
					else if (((12 - ((this->_current->get_part()[i].getY() - 11) / 3)) % 2 != 0 && ((this->_current->get_part()[i].getX() - 6) / 5) % 2 == 0) || ((12 - ((this->_current->get_part()[i].getY() - 11) / 3)) % 2 == 0 && ((this->_current->get_part()[i].getX() - 6) / 5) % 2 != 0)) {
						if (this->_current->get_part()[i].getY() >= 11) {
							gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY());
							cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;

							gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY() + 1);
							cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;

							gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY() + 2);
							cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;
						}
					}
				}
			}
		}
		int i = 1;
		if (this->_ground[12 - ((this->_current->get_part()[i].getY() - 11) / 3)][(this->_current->get_part()[i].getX() - 6) / 5].isFilled == true) {
			if ((this->isFull(12 - ((this->_current->get_part()[i].getY() - 11) / 3)) && isScored.size() == 0) || (this->isFull(12 - ((this->_current->get_part()[i].getY() - 11) / 3)) && isScored.size() > 0 && isScored[isScored.size() - 1] != 12 - ((this->_current->get_part()[i].getY() - 11) / 3)))
				isScored.push_back(12 - ((this->_current->get_part()[i].getY() - 11) / 3));

			if (((12 - ((this->_current->get_part()[i].getY() - 11) / 3)) % 2 == 0 && ((this->_current->get_part()[i].getX() - 6) / 5) % 2 == 0) || ((12 - ((this->_current->get_part()[i].getY() - 11) / 3)) % 2 != 0 && ((this->_current->get_part()[i].getX() - 6) / 5) % 2 != 0)) {
				if (this->_current->get_part()[i].getY() >= 11) {
					gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY());
					cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;

					gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY() + 1);
					cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;

					gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY() + 2);
					cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;
				}
			}
			else if (((12 - ((this->_current->get_part()[i].getY() - 11) / 3)) % 2 != 0 && ((this->_current->get_part()[i].getX() - 6) / 5) % 2 == 0) || ((12 - ((this->_current->get_part()[i].getY() - 11) / 3)) % 2 == 0 && ((this->_current->get_part()[i].getX() - 6) / 5) % 2 != 0)) {
				if (this->_current->get_part()[i].getY() >= 11) {
					gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY());
					cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;

					gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY() + 1);
					cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;

					gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY() + 2);
					cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;
				}
			}
		}
	}

	else if (this->_current->get_part()[0].getY() <= this->_current->get_part()[1].getY()) {

		for (int i = 0; i < 4; i++) {
			if (this->_ground[12 - ((this->_current->get_part()[i].getY() - 11) / 3)][(this->_current->get_part()[i].getX() - 6) / 5].isFilled == true) {
				if ((this->isFull(12 - ((this->_current->get_part()[i].getY() - 11) / 3)) && isScored.size() == 0) || (this->isFull(12 - ((this->_current->get_part()[i].getY() - 11) / 3)) && isScored.size() > 0 && isScored[isScored.size() - 1] != 12 - ((this->_current->get_part()[i].getY() - 11) / 3)))
					isScored.push_back(12 - ((this->_current->get_part()[i].getY() - 11) / 3));

				if (((12 - ((this->_current->get_part()[i].getY() - 11) / 3)) % 2 == 0 && ((this->_current->get_part()[i].getX() - 6) / 5) % 2 == 0) || ((12 - ((this->_current->get_part()[i].getY() - 11) / 3)) % 2 != 0 && ((this->_current->get_part()[i].getX() - 6) / 5) % 2 != 0)) {
					if (this->_current->get_part()[i].getY() >= 11) {
						gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY());
						cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;

						gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY() + 1);
						cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;

						gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY() + 2);
						cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;
					}
				}
				else if (((12 - ((this->_current->get_part()[i].getY() - 11) / 3)) % 2 != 0 && ((this->_current->get_part()[i].getX() - 6) / 5) % 2 == 0) || ((12 - ((this->_current->get_part()[i].getY() - 11) / 3)) % 2 == 0 && ((this->_current->get_part()[i].getX() - 6) / 5) % 2 != 0)) {
					if (this->_current->get_part()[i].getY() >= 11) {
						gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY());
						cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;

						gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY() + 1);
						cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;

						gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY() + 2);
						cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;
					}
				}
			}
		}
	}
	else {
		for (int i = 3; i >= 0; i--) {
			if (this->_ground[12 - ((this->_current->get_part()[i].getY() - 11) / 3)][(this->_current->get_part()[i].getX() - 6) / 5].isFilled == true) {
				if ((this->isFull(12 - ((this->_current->get_part()[i].getY() - 11) / 3)) && isScored.size() == 0) || (this->isFull(12 - ((this->_current->get_part()[i].getY() - 11) / 3)) && isScored.size() > 0 && isScored[isScored.size() - 1] != 12 - ((this->_current->get_part()[i].getY() - 11) / 3)))
					isScored.push_back(12 - ((this->_current->get_part()[i].getY() - 11) / 3));

				if (((12 - ((this->_current->get_part()[i].getY() - 11) / 3)) % 2 == 0 && ((this->_current->get_part()[i].getX() - 6) / 5) % 2 == 0) || ((12 - ((this->_current->get_part()[i].getY() - 11) / 3)) % 2 != 0 && ((this->_current->get_part()[i].getX() - 6) / 5) % 2 != 0)) {
					if (this->_current->get_part()[i].getY() >= 11) {
						gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY());
						cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;

						gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY() + 1);
						cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;

						gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY() + 2);
						cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;
					}
				}
				else if (((12 - ((this->_current->get_part()[i].getY() - 11) / 3)) % 2 != 0 && ((this->_current->get_part()[i].getX() - 6) / 5) % 2 == 0) || ((12 - ((this->_current->get_part()[i].getY() - 11) / 3)) % 2 == 0 && ((this->_current->get_part()[i].getX() - 6) / 5) % 2 != 0)) {
					if (this->_current->get_part()[i].getY() >= 11) {
						gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY());
						cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;

						gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY() + 1);
						cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;

						gotoXY(this->_current->get_part()[i].getX(), this->_current->get_part()[i].getY() + 2);
						cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;
					}
				}
			}
		}
	}
	if (isScored.size() != 0)
		this->scoreCal(isScored);
}

void Game::scoreDraw(int color, vector<int> score) {
	setTextColor();
	textColor(color);
	for (int i = 0; i < score.size(); i++) {
		for (int j = 0; j < 3; j++) {
			gotoXY(this->_ground[score[i]][0].pos.getX(), this->_ground[score[i]][0].pos.getY() + j);
			for (int k = 0; k < 40; k++)
				cout << (char)176;
		}
	}
}

int Game::fallAllWayDown() {
	setTextColor();
	int f = 0, l = 0, id = 0;
	Coord initialPos(26, -1);
	vector<Coord> predictedPos(this->_after->get_part());
	Brick _temp(*this->_after);

	for (int i = 0; i < 4; i++) {
		predictedPos[i].setX(predictedPos[i].getX() + 35);
		predictedPos[i].setY(predictedPos[i].getY() + 27);
	}

	_temp.set_part(predictedPos);

	f = clock();
	while (1) {
		l = clock();
		Brick _block(*this->_current);

		if (l - f >= 50) {
			f = clock();

			_block.fallOne();

			if (isHit(&_block)) {

				if (isOver()) {

					textColor(12);
					gotoXY(6, 26);
					cout << "                                        ";
					gotoXY(6, 27);
					textColor(12);
					cout << "               GAME OVER                ";
					gotoXY(6, 28);
					textColor(14);
					cout << "            Your Score:                 ";
					gotoXY(30, 28);
					cout << this->_score;
					gotoXY(6, 29);
					textColor(10);
					cout << "        Press Enter to play again       ";
					gotoXY(6, 30);
					cout << "          Press Esc to Exit...          ";
					gotoXY(6, 31);
					cout << "                                        ";
					gotoXY(40, 29);
					
					while (1) {
						if (kbhit()) {
							int temp = getch();
							if (temp == 13) {
								return 1;
							}
							else if (temp == 27) {
								return 0;
							}
						}
					}

				}

				this->hittedDraw();

				this->_current = this->_after;

				id = rand() % 7; //7

				_temp.erase();

				switch (id) {
				case 0: this->_after = new L_Brick(initialPos);
					break;
				case 1:	this->_after = new LReverse_Brick(initialPos);
					break;
				case 2: this->_after = new Z_Brick(initialPos);
					break;
				case 3: this->_after = new ZReverse_Brick(initialPos);
					break;
				case 4: initialPos.setY(initialPos.getY() - 3);
					this->_after = new I_Brick(initialPos);
					break;
				case 5: initialPos.setY(initialPos.getY());
					this->_after = new HalfCross_Brick(initialPos);
					break;
				case 6: initialPos.setY(initialPos.getY() + 3);
					this->_after = new Square_Brick(initialPos);
					break;
				}

				setTextColor();
				textColor(7);

				//Predicted Brick

				for (int i = 0; i < 4; i++) {
					predictedPos[i].setX(this->_after->get_part()[i].getX() + 35);
					predictedPos[i].setY(this->_after->get_part()[i].getY() + 27);
				}

				_temp.set_part(predictedPos);

				_temp.draw();

				return -1;

			}
			else {
				this->_current->erase();
				this->_current->set_part(_block.get_part());
				this->_current->draw();
			}
		}
	}
	return false;
}

bool Game::play() {
	setTextColor();
	int f, l, id = 0;
	Coord initialPos(26, -1);
	this->reset_ground();
	//Predicted Brick

	vector<Coord> predictedPos(this->_after->get_part());
	for (int i = 0; i < 4; i++) {
		predictedPos[i].setX(predictedPos[i].getX() + 35);
		predictedPos[i].setY(predictedPos[i].getY() + 27);
	}
	Brick _temp(*this->_after);
	
	_temp.set_part(predictedPos);

	_temp.draw();

	f = clock();

	while (1) {
		Brick _block(*this->_current);
		l = clock();
		if (l - f >= 800 - this->_score) {
			f = clock();
			_block.fallOne();

			if (isHit(&_block)) {

				if (isOver()) {

					textColor(12);
					gotoXY(6, 26);
					cout << "                                        ";
					gotoXY(6, 27);
					textColor(12);
					cout << "               GAME OVER                ";
					gotoXY(6, 28);
					textColor(14);
					cout << "            Your Score:                 ";
					gotoXY(30, 28);
					cout << this->_score;
					gotoXY(6, 29);
					textColor(10);
					cout << "        Press Enter to play again       ";
					gotoXY(6, 30);
					cout << "          Press Esc to Exit...          ";
					gotoXY(6, 31);
					cout << "                                        ";
					gotoXY(40, 29);

					while (1) {
						if (kbhit()) {
							int temp = getch();
							if (temp == 13) {
								return true;
							}
							else if (temp == 27) {
								return false;
							}
						}
					}
				}

				this->hittedDraw();

				this->_current = this->_after;

				id = rand() % 7;//7

				_temp.erase();

				switch (id) {
				case 0: this->_after = new L_Brick(initialPos);
					break;
				case 1:	this->_after = new LReverse_Brick(initialPos);
					break;
				case 2: this->_after = new Z_Brick(initialPos);
					break;
				case 3: this->_after = new ZReverse_Brick(initialPos);
					break;
				case 4: initialPos.setY(initialPos.getY() - 3);
					this->_after = new I_Brick(initialPos);
					break;
				case 5: initialPos.setY(initialPos.getY());
					this->_after = new HalfCross_Brick(initialPos);
					break;
				case 6: initialPos.setY(initialPos.getY() + 3);
					this->_after = new Square_Brick(initialPos);
					break;
				}

				textColor(7);

				//Predicted Brick
				for (int i = 0; i < 4; i++) {
					predictedPos[i].setX(this->_after->get_part()[i].getX() + 35);
					predictedPos[i].setY(this->_after->get_part()[i].getY() + 27);
				}
				_temp.set_part(predictedPos);

				_temp.draw();

			}
			else {
				this->_current->erase();
				this->_current->set_part(_block.get_part());
				this->_current->draw();
			}
			continue;
		}
		if (kbhit()) {
			int buffer = getch();
			if (buffer == 224) {
				buffer = getch();
				if (buffer == 72) {//Up - Rotate
					Brick _block(*this->_current);
					this->_current->rotate();

					if (isHit(this->_current)) {
						this->_current->set_part(_block.get_part());
					}
					else {
						_block.erase();
						this->_current->draw();
					}
					continue;
				}

				else if (buffer == 77) {//Right - move Right
					Brick _block(*this->_current);
					_block.moveRight();
					if (!this->_current->isHitRightSideWall() && !isHitSideWay(&_block)) {
						this->_current->erase();
						this->_current->moveRight();
						this->_current->draw();
					}
					continue;

				}

				else if (buffer == 75) {//Left - move Left
					Brick _block(*this->_current);
					_block.moveLeft();
					if (!this->_current->isHitLeftSideWall() && !isHitSideWay(&_block)) {
						this->_current->erase();
						this->_current->moveLeft();
						this->_current->draw();
					}
					continue;

				}
				else if (buffer == 80) {//Down - move Down
					int _tmp = this->fallAllWayDown();
					if (_tmp == 1) return true;
					else if (_tmp == 0) return false;
					else {
						if (kbhit()) {
							int buffer = getch();
							if (buffer == 224) {
								buffer = getch();
							}
							continue;
						}
					}

					for (int i = 0; i < 4; i++) {
						predictedPos[i].setX(this->_after->get_part()[i].getX() + 35);
						predictedPos[i].setY(this->_after->get_part()[i].getY() + 27);
					}
					_temp.set_part(predictedPos);

				}
			}
		}
	}
	return false;
}

void Game::eraseAfterScored(vector<int> scored) {
	for (int i = 0; i < scored.size(); i++) {
		for (int j = scored[i]; j < 12; j++) {
			for (int k = 0; k < 8; k++) {
				this->_ground[j][k].isFilled = this->_ground[j + 1][k].isFilled;
				this->reDrawBlock(j, k);
			}
		}
	}
}

void Game::reDrawBlock(int i, int j) {

	if (this->_ground[i][j].isFilled == true) {
		if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0)) {
			gotoXY(this->_ground[i][j].pos.getX(), this->_ground[i][j].pos.getY());
			cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;

			gotoXY(this->_ground[i][j].pos.getX(), this->_ground[i][j].pos.getY() + 1);
			cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;
			
			gotoXY(this->_ground[i][j].pos.getX(), this->_ground[i][j].pos.getY() + 2);
			cout << (char)219 << (char)219 << (char)219 << (char)219 << (char)219;
		}
		else if ((i % 2 != 0 && j % 2 == 0) || (i % 2 == 0 && j % 2 != 0)) {
			gotoXY(this->_ground[i][j].pos.getX(), this->_ground[i][j].pos.getY());
			cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;
				
			gotoXY(this->_ground[i][j].pos.getX(), this->_ground[i][j].pos.getY() + 1);
			cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;
			
			gotoXY(this->_ground[i][j].pos.getX(), this->_ground[i][j].pos.getY() + 2);
			cout << (char)177 << (char)177 << (char)177 << (char)177 << (char)177;
		}
	}
	else {
		gotoXY(this->_ground[i][j].pos.getX(), this->_ground[i][j].pos.getY());
		cout << "     ";

		gotoXY(this->_ground[i][j].pos.getX(), this->_ground[i][j].pos.getY() + 1);
		cout << "     ";

		gotoXY(this->_ground[i][j].pos.getX(), this->_ground[i][j].pos.getY() + 2);
		cout << "     ";
	}
}

void Game::scoreCal(vector<int> isScored) {
	
	for (int i = 0; i < 3; i++) {
		this->scoreDraw(9, isScored);
		Sleep(200);
		this->scoreDraw(12, isScored);
		Sleep(200);
	}

	if (isScored.size() == 2) {
		this->_score += 4;
	}
	else if (isScored.size() == 3) {
		this->_score += 7;
	}
	else if (isScored.size() == 4) {
		this->_score += 12;
	}
	else this->_score += 1;

	setTextColor();
	textColor(7);

	gotoXY(57, 43);
	cout << this->_score;

	this->eraseAfterScored(isScored);
}

bool Game::isFull(int pos) {
	int count = 0;
	for (int i = 0; i < 8; i++) {
		if (this->_ground[pos][i].isFilled == true) {
			count++;
		}
	}
	if (count == 8) return true;
	return false;
}

bool Game::isOver() {
	for (int i = 0; i < 8; i++) {
		if (this->_ground[13][i].isFilled == true) {
			return true;
		}
	}
	return false;
}