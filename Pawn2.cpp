//Project: Chess
//Date:2018/04/11
//Author:Weixin Kong

#include"Pieces.h"
#include"Pawn2.h"
#include<math.h>
#include<iostream>
using namespace std;
Pawn2::Pawn2()
{
	firstMoveFlag = 1;//define is this pawn is first move or not(ture=first move/false=not first)
	ID = 6;
}

Pawn2::~Pawn2()
{
}

//////////Rule of the Pawn for player 2//////////

void Pawn2::move(int nPosA, int nPosB)
{
	int x, y;
	x = 0;
	y = 0;

	if (nPosA >= 0 && nPosA < 8 && nPosB >= 0 && nPosB < 8)
	{

		x = returnPosX();
		y = nPosB - returnPosY();

		if (firstMoveFlag == 1)
		{
			if ((x == nPosA) && ((y == 2) || (y == 1)))
			{
				setPos(nPosA, nPosB);
				cout << "Moving success!" << endl;
			}
			else
			{
				cout << "Invalid Position!" << endl;
			}
		}
		else
		{
			if ((x == nPosA) && (y == 1))
			{
				setPos(nPosA, nPosB);
				cout << "Moving success!" << endl;
			}
			else
			{
				cout << "Invalid Position!" << endl;
			}
		}
	}
	else
	{
		cout << "Invalid Position!" << endl;
	}
}

int Pawn2::returnID()
{
	return ID;
}

void Pawn2::deletePiece()
{
	ID = 0;
	setPos(NULL, NULL);
}