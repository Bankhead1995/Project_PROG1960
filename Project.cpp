// Project.cpp : Defines the entry point for the console application.
//

#include "Pieces.h"
#include "Horse.h"
#include "rook.h"
#include "Bishop.h"
#include<iostream>
#include<vector>
using namespace std;
void board(int x, int y);

int main()
{
	Pieces *p1;

	p1 = new Bishop;

	p1->setPos(1, 1);

	board(p1->returnPosX(),p1->returnPosY());
	system("pause");

	system("cls");

	p1->move(5,4);
	board(p1->returnPosX(), p1->returnPosY());
    return 0;
}

void board(int x, int y)
{
	int boardView[8][8] = { 0,0,0,0,0,0,0,0,
						    0,0,0,0,0,0,0,0,
						    0,0,0,0,0,0,0,0,
						    0,0,0,0,0,0,0,0,
						    0,0,0,0,0,0,0,0,
						    0,0,0,0,0,0,0,0,
						    0,0,0,0,0,0,0,0,
						    0,0,0,0,0,0,0,0 };
	boardView[x][y] = { 1 };
	
	for (int i = 0; i < 8; i++)
	{
		for (int z = 0; z < 8; z++)
		{
			
			cout << boardView[z][i];
		}
		cout << endl;
	}
}
