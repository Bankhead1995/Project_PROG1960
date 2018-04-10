//Project: Chess
//Date:2018/04/08
//Author:Adam Oliver

#ifndef ROOK_H_
#define ROOK_H_
#include "Pieces.h"

class rook:public Pieces
{
public:
	rook();
	~rook();
	void move(int PosX, int PosY);
	int returnID();

private:
	int nPosX[14];
	int nPosY[14];

	int ID;//ADD BY Weixin
};



#endif // !ROOK_H_
#pragma once
