#include "stdafx.h"
#include "Library.h"

void paintmap(int x_size, int y_size)
{
	for (int k = 0; k < y_size; k++) {
		if ((k == 0) || (k == y_size - 1))
			for (int i = 0; i < x_size; i++) cout << "#";
		else
			for (int k = 0; k < x_size; k++)
				if ((k == 0) || (k == x_size - 1))
					cout << "j";
				else
					cout << " ";
		cout << endl;
	}
	cout << endl;
	cout << "Your score: ";
}

void addfood(int x_size, int y_size, struct food *foods)
{
	int count = sizeof(foods);
	for (int i = 0; i < count; i++)
	{
		while (foods[i].z == 0) {
			foods[i].coord.X = rand() % (x_size-2)+1;
			foods[i].coord.Y = rand() % (y_size-2)+1;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), foods[i].coord);
			cout << "*";
			foods[i].z = 1;
			
		}
	}
}
