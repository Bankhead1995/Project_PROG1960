//Project: Chess
//Date:2018/04/08
//Author:Weixin Kong

#include"Horse.h"
#include<iostream>
#include<math.h>
using namespace std;


Horse::Horse()
{
	ID = 5;
}
Horse::~Horse()
{

}

int Horse::returnID()
{
	return ID;
}


//////////Rule of the Knight//////////
void Horse::move(int PosA,int PosB)
{
	if (PosA >= 0 && PosA < 8 && PosB >= 0 && PosB < 8)
	{
		unsigned int a, b = 0;
		
		a = abs(PosA - returnPosX());
		b = abs(PosB - returnPosY());

		if ((a==1) && (b==2))
		{
			setPos(PosA, PosB);
			cout << "Moving success!" << endl;
		}
		else if ((a==2) && (b==1))
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
}