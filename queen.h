//Project: Chess
//Date: 2018/04/10
//Author: Adam Oliver

#ifndef QUEEN_H_
#define QUEEN_H_
#include "Pieces.h"

class queen:public Pieces
{
public:
	queen();
	~queen();

	void move(int nPosA, int nPosB);
	int returnID();
	void deletePiece(); //////////ADD BY Weixin 
private:
	int ID;
};

#endif // !QUEEN_H_
#pragma once
