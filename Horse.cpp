//Project: Chess
//Date:2018/04/08
//Author:Weixin Kong

#include"Horse.h"
#include<iostream>
using namespace std;


Horse::Horse()
{
	for (int  i = 0; i < 8; i++)
	{
		nPosX[i] = 0;
		nPosY[i] = 0;
	}
}
Horse::~Horse()
{

}


//////////Rule of the Knight//////////
void Horse::move(int PosA,int PosB)
{
	if (PosA >= 0 && PosA < 8 && PosB >= 0 && PosB < 8)
	{
		if (PosA == returnPosX() + 2 && PosB == returnPosY() + 1)
		{
			setPos(PosA, PosB);
			cout << "Moving success!" << endl;
		}
		else if (PosA == returnPosX() - 2 && PosB == returnPosY() + 1)
		{
			setPos(PosA, PosB);
			cout << "Moving success!" << endl;
		}
		else if (PosA == returnPosX() + 2 && PosB == returnPosY() - 1)
		{
			setPos(PosA, PosB);
			cout << "Moving success!" << endl;
		}
		else if (PosA == returnPosX() - 2 && PosB == returnPosY() - 1)
		{
			setPos(PosA, PosB);
			cout << "Moving success!" << endl;
		}
		else if (PosA == returnPosX() + 1 && PosB == returnPosY() + 2)
		{
			setPos(PosA, PosB);
			cout << "Moving success!" << endl;
		}
		else if (PosA == returnPosX() - 1 && PosB == returnPosY() + 2)
		{
			setPos(PosA, PosB);
			cout << "Moving success!" << endl;
		}
		else if (PosA == returnPosX() + 1 && PosB == returnPosY() - 2)
		{
			setPos(PosA, PosB);
			cout << "Moving success!" << endl;
		}
		else if (PosA == returnPosX() - 1 && PosB == returnPosY() - 2)
		{
			setPos(PosA, PosB);
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

	/*
	nPosX[0] = returnPosX() + 2;
	nPosY[0] = returnPosY() + 1;

	nPosX[1] = returnPosX() - 2;
	nPosY[1] = returnPosY() + 1;

	nPosX[2] = returnPosX() + 2;
	nPosY[2] = returnPosY() - 1;

	nPosX[3] = returnPosX() - 2;
	nPosY[3] = returnPosY() - 1;

	nPosX[4] = returnPosX() + 1;
	nPosY[4] = returnPosY() + 2;

	nPosX[5] = returnPosX() - 1;
	nPosY[5] = returnPosY() + 2;

	nPosX[6] = returnPosX() + 1;
	nPosY[6] = returnPosY() - 2;

	nPosX[7] = returnPosX() - 1;
	nPosY[7] = returnPosY() - 2;

	bool flag = 0;

	for (int i = 0; i < 8; i++)
	{
		if (nPosX[i]>0 && nPosX[i]<8 && nPosY[i]>0 && nPosY[i]<8)
		{
			if (nPosX[i] == PosA && nPosY[i] == PosB)
			{
				setPos(PosA, PosB);
				cout << "Moving success!" << endl;
				flag = 1;
				break;
			}
		}
	}
	if (flag == 0)
	{
		cout << "Invalid Pos!" << endl;
	}*/

}