//
//Project Name: Tetrix
//Author: Nguyen Ho Toan Thu
//Starting day: February 11th, 2017
//Main.cpp
//

#include "Game.h"
#include <fstream>


void readFileText(char *FilePath, char **&_title) {
	
	ifstream f;
	char temp;
	f.open(FilePath);
	
	if (f.is_open()) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 80; j++) {
				f >> _title[i][j];
			}
		}

		f.close();
	}
	else cout << "Fail to open file!" << endl;
}

void printFile(char **_title) {
	for (int i = 0; i < 80; i++) {
		for (int j = 0; j < 10; j++) {
			gotoXY(0 + i, 11 + j);
			cout << _title[j][i];
		}
		Sleep(30);
	}
}

void drawBackGround() {
	setTextColor();
	textColor(7);
	for (int i = 11; i < 50; i++) {
		gotoXY(5, i);
		cout << (char)186;
		gotoXY(46, i);
		cout << (char)186;
	}
	gotoXY(5, 50);
	for (int i = 5; i < 47; i++) {
		cout << (char)223;
	}
	
	
	gotoXY(49, 14);
	textColor(207);
	cout << "00000 0000 00000 0000  0 0   0";
	gotoXY(49, 15);
	cout << "  0   0      0   0   0 0  0 0 ";
	gotoXY(49, 16);
	cout << "  0   0000   0   00000 0   0  ";
	gotoXY(49, 17);
	cout << "  0   0      0   0   0 0  0 0 ";
	gotoXY(49, 18);
	cout << "  0   0000   0   0   0 0 0   0";

	textColor(7);
	gotoXY(50, 27);
	cout << "Next: ";

	gotoXY(50, 43);
	cout << "Score: 0";
}


int main() {
	
	//Insert and draw the Title
	char **_title = new char*[10];

	for (int i = 0; i < 10; i++) {
		_title[i] = new char[80];
	}

	gotoXY(0, 11);
	setTextColor();
	textColor(10);
	readFileText("Title.txt", _title);

	printFile(_title);
	
	textColor(15);
	gotoXY(50, 22);
	cout << "Author: Nguyen Ho Toan Thu";

	//Menu two choices

	textColor(15);
	gotoXY(38, 29);
	cout << "Play";

	gotoXY(38, 33);
	cout << "Exit";
	
	textColor(12);
	gotoXY(37, 29);
	cout << "<Play>";

	int pos = 0;
	while (1) {
		if (kbhit()) {
			int id = getch();
			if (id == 224) {
				id = getch();
				if (id == 72 && pos == 1) {
					pos = 0;
					textColor(12);
					gotoXY(37, 29);
					cout << "<Play>";
					textColor(15);
					gotoXY(37, 33);
					cout << " Exit ";
				}
				else if (id == 80 && pos == 0) {
					pos = 1;
					textColor(12);
					gotoXY(37, 33);
					cout << "<Exit>";
					textColor(15);
					gotoXY(37, 29);
					cout << " Play ";
				}
			}
			else if (id == 13) {
				if (pos == 0) {
					//The game's loop
					srand(time(NULL));
					system("cls");
					drawBackGround();

					Game _game;

					gotoXY(19, 30);
					char _ready[16]("---Get Ready---");

					for (int i = 0; i < 16; i++) {
						Sleep(30);
						cout << _ready[i];
					}
					Sleep(1000);
					gotoXY(19, 30);
					for (int i = 0; i < 16; i++) {
						Sleep(30);
						cout << " ";
					}

					if (kbhit()) {
						int temp = getch();
						if (temp == 224)
							temp == getch();
					}

					while (_game.play()) {
						Game _game;
						system("cls");
						drawBackGround();
						if (kbhit()) {
							int temp = getch();
							if (temp == 224)
								temp == getch();
						}
					}
					
					break;
				}
				else {
					gotoXY(0, 40);
					break;
				}
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		delete[] _title[i];
	}
	delete[] _title;

	return 0;
}