//Project: Chess
//Date: 2018/04/10
//Author: Adam Oliver

#ifndef KING_H_
#define KING_H_
#include "Pieces.h"

class king:public Pieces
{
public:
	king();
	~king();

	void move(int nPosA, int nPosB);
	int returnID();
	void deletePiece(); //////////ADD BY Weixin 
private:
	int ID;
};

#endif // !king_H_
#pragma once
