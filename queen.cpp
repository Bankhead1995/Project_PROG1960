//Project: Chess
//Date: 2018/04/10
//Author: Adam Oliver

#include"queen.h"
#include"Pieces.h"
#include<iostream>
#include<math.h>

using namespace std;

queen::queen()
{
	ID = 2;
}

queen::~queen()
{
}

void queen::move(int nPosA, int nPosB)
{
	unsigned int a, b;
	if (nPosA >= 0 && nPosA < 8 && nPosB >= 0 && nPosB < 8)
	{
		a = abs(nPosA - returnPosX());
		b = abs(nPosB - returnPosY());
		if (a == b || a == 0 || b == 0)
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

int queen::returnID()
{
	return ID;
}

void queen::deletePiece() //////////ADD BY Weixin 
{
	ID = 0;
	setPos(NULL, NULL);
}