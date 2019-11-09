#pragma once
#include "body.h"
using namespace std;
struct food
{
	COORD coord;
	bool z=0;
};
using namespace std;
void paintmap(int x_size, int y_size);
void addfood(int x_size, int y_size, struct food *foods);