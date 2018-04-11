//Project: Chess
//Date:2018/04/11
//Author:Weixin Kong

#include"Pieces.h"
#include"Pawn1.h"
#include<math.h>
#include<iostream>
using namespace std;
Pawn1::Pawn1()
{
	firstMoveFlag = 1;//define is this pawn is first move or not(ture=first move/false=not first)
	ID = 6;
}

Pawn1::~Pawn1()
{
}

//////////Rule of the Pawn for player 1//////////

void Pawn1::move(int nPosA, int nPosB)
{
	int x, y;
	x = 0;
	y = 0;

	if (nPosA >= 0 && nPosA < 8 && nPosB >= 0 && nPosB < 8)
	{
		x = returnPosX();
		y = returnPosY() - nPosB;

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

int Pawn1::returnID()
{
	return ID;
}

void Pawn1::deletePiece()
{
	ID = 0;
	setPos(NULL, NULL);
}