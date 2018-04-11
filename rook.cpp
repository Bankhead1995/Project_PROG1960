//Project: Chess
//Date:2018/04/08
//Author:Adam Oliver

#include "rook.h"
#include "Pieces.h"
#include<iostream>

using namespace std;
rook::rook()
{
	for (int i = 0; i < 15; ++i)
	{
		nPosX[i] = 0;
		nPosY[i] = 0;
	}

	ID = 4;//ADD BY Weixin
}

rook::~rook()
{
}

void rook::move(int PosX, int PosY)
{
	for (int i = 0; i < 7; i++)
	{
		nPosX[i] = returnPosX() + i;
		nPosY[i] = returnPosY() + i;
	}
	for (int i = 7; i < 15; i++)
	{
		nPosX[i] = returnPosX() - (i - 7);
		nPosY[i] = returnPosY() - (i - 7);
	}

	bool flag = 0;

	for (int i = 0; i < 15; ++i)
	{
		if (nPosX[i] == PosX && PosY == returnPosY())
		{
			setPos(PosX, PosY);
			flag = 1;
			break;
		}
		if (nPosY[i] == PosY && PosX == returnPosX())
		{
			setPos(PosX, PosY);
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		cout << "Invalid move." << endl;
	}
}

int rook::returnID()     //////////ADD BY Weixin 
{
	return ID;
}

void rook::deletePiece()       //////////ADD BY Weixin 
{
	ID = 0;
	setPos(NULL, NULL);
}