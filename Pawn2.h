//Project: Chess
//Date:2018/04/11
//Author:Weixin Kong

#ifndef PAWN2_H_
#define PAWN2_H_
#include"Pieces.h"
//////////since the pawn can not move backward, so it is really hard to define the pawn of different player are moving  backward or not//////////
//////////Pawn1 is the pawn of player 2//////////

class Pawn2 :public Pieces
{
public:
	Pawn2();
	~Pawn2();
	void move(int nPosA, int nPosB);
	int returnID();
	void deletePiece();
private:
	bool firstMoveFlag;
	int ID;
};
#endif // !PAWN2_H_
#pragma once
