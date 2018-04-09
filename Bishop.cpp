//Project: Chess
//Date:2018/04/08
//Author:Weixin Kong

#include"Bishop.h"
#include"Pieces.h"
#include<iostream>

using namespace std;

Bishop::Bishop()
{
}

Bishop::~Bishop()
{
}

void Bishop::move(int nPosA, int nPosB)
{
	unsigned int a, b;
	if (nPosA >= 0 && nPosA < 8 && nPosB >= 0 && nPosB < 8)
	{
		a = nPosA - returnPosX();
		b = nPosB - returnPosY();

		if (a == b)
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