// Snake.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include"body.h"
#include"Library.h"
using namespace std;
const int x_size = 79;
const int y_size = 40;

int main()
{
	body snake;
	int speed = 3;
	food foods[5];
	int score;
	COORD lp = { 15,y_size + 1 };
	while(true)
	{
	//LoadKeyboardLayout("00000409", KLF_ACTIVATE);
		for (int i = 0; i < 4; i++) {
			foods[i].z = 0;
		}
	snake.setfirstpartcoord(x_size, y_size);
	snake.size = 2;
	speed = 3;
	paintmap(x_size, y_size);
	snake.paintbody();
	score = 0;
	while (snake.gameover(x_size, y_size)) {
		if (score > 1000)speed = (score / 1000)*(3);
		addfood(x_size, y_size, foods);
		Sleep(1000 / speed);
		snake.setside();
		snake.newcoords();
		snake.eatfood(foods, score);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), lp);
		cout << score;
	}
	system("cls");
	cout <<endl<<endl<<endl<< "           Nu ti proigral" << endl << "      Your score: " << score << endl;
	_getch();
	system("cls");
}
	system("pause");
    return 0;

}

