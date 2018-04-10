#ifndef PAWN1_H_
#define PAWN1_H_
#include"Pieces.h"
//////////since the pawn can not move backward, so it is really hard to define the pawn of different player are moving  backward or not//////////
//////////Pawn1 is the pawn of player 1//////////

class Pawn1:public Pieces
{
public:
	Pawn1();
	~Pawn1();
	void move(int nPosA, int nPosB);
	int returnID();
private:
	bool firstMoveFlag;
	int ID;
};
#endif // !PAWN_H_
#pragma once
