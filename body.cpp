#include "stdafx.h"
#include "body.h"


body::body()
{

}


body::~body()
{
}

void body::setfirstpartcoord(int x_size, int y_size)
{
	for (int i = 0; i < 150; i++) {
		part[i].coord.X = x_size / 2;
		part[i].coord.Y = y_size / 2 + i;
	}
}

void body::setside() //определение куда идти
{
	if (_kbhit()) {
		char lol = _getch();
		if        ((!((moveside == left) && (lol == right)))
				&& (!((moveside == right) && (lol == left)))
				&& (!((moveside == up) && (lol == down)))
				&& (!((moveside == down) && (lol == up))))
			switch (lol)
			{
			case'w':moveside = up; break;
			case'a':moveside = left; break;
			case's':moveside = down; break;
			case 'd':moveside = right; break;
			default:
				break;
			}
		
		
	}
}

void body::paintbody()
{
	for (int i = 0; i < size; i++) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), part[i].coord);
		cout << "$";
	}
}

void body::newcoords()
{
	for (int i = 0; i < size; i++)
		part[i].lcoord = part[i].coord;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), part[size - 1].coord); cout << " ";
	switch (moveside) {
	case 'w': part[0].coord.Y--; for (int i = 0; i < size-1; i++) part[i + 1].coord = part[i].lcoord;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), part[0].coord); cout << "$";	break;
	case 'a': part[0].coord.X--; for (int i = 0; i < size-1; i++) part[i + 1].coord = part[i].lcoord;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), part[0].coord); cout << "$"; break;
	case 's': part[0].coord.Y++; for (int i = 0; i < size-1; i++) part[i + 1].coord = part[i].lcoord;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), part[0].coord); cout << "$"; break;
	case 'd': part[0].coord.X++; for (int i = 0; i < size-1; i++) part[i + 1].coord = part[i].lcoord;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), part[0].coord); cout << "$"; break;
	default:break;
	}
}

bool body::checkdie()
{
	bool z=true;
	int i = 1;
	for (i; i < size;i++) {
		if ((part[0].coord.X == part[i].coord.X)&&(part[0].coord.Y == part[i].coord.Y))
		{
			z = false;
		}
	}
	return z;
}

void body::eatfood(struct food *foods , int& score)
{
	for(int i=0;i<4;i++)
		if ((part[0].coord.X == foods[i].coord.X) && (part[0].coord.Y == foods[i].coord.Y)) {
			size++;
			foods[i].z = 0;
			score += 100;
	}
}

bool body::gameover(int x_size, int y_size)
{
	bool z=true;
	if (part[0].coord.X == 0) z = 0;
	if (part[0].coord.X == x_size-1) z = 0;
	if (part[0].coord.Y == 0) z = 0;
	if (part[0].coord.Y == y_size-1) z = 0;
	
	return (z&&checkdie());
}
