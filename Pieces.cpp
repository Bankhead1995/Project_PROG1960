#include"Pieces.h"
#include"Horse.h"
#include <iostream>

using namespace std;


Pieces::Pieces()
{
	
}

Pieces::~Pieces()
{
}

void Pieces::setPos(int x, int y)
{
	if (x<0||x>7||y<0||y>7)
	{
		cout << "invalid Position!!!" << endl;
	}
	else
	{
		posX = x;
		posY = y;
	}
}


int Pieces::returnPosX()
{
	return posX;
}

int Pieces::returnPosY()
{
	return posY;
}


void Pieces::move(int PosA, int PosB)
{}

int Pieces::returnID()
{
	return 0;
}