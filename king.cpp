//Project: Chess
//Date: 2018/04/10
//Author: Adam Oliver

#include"king.h"
#include"Pieces.h"
#include<iostream>
#include<math.h>

using namespace std;

king::king()
{
	ID = 1;
}

king::~king()
{
}

void king::move(int nPosA, int nPosB)
{
	unsigned int a, b;
	if (nPosA >= 0 && nPosA < 8 && nPosB >= 0 && nPosB < 8)
	{
		a = abs(nPosA - returnPosX());
		b = abs(nPosB - returnPosY());
		if (a == b == 1)
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
		cout << "Invalid Position!" << endl;
	}
}

int king::returnID()
{
	return ID;
}

void king::deletePiece() //////////ADD BY Weixin 
{
	ID = 0;
	setPos(NULL, NULL);
}