#pragma once
#include"stdafx.h"
#include"Library.h"
using namespace std;
struct partofsnake
{
	COORD coord;
	COORD lcoord;
	bool z = 0;
};
class body
{

public:
	body();
	~body();
private:
	char moveside = 'w';
	partofsnake part[150];
	const char up = 'w', down = 's', left = 'a', right = 'd';
public:
	int size = 1;
	void setfirstpartcoord(int x_size, int y_size);
	void setside();
	void paintbody();
	void newcoords();
	bool checkdie();
	void eatfood(struct food *foods, int &score);
	bool gameover(int x_size, int y_size);
};

