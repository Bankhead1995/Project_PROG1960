//Project: Chess
//Date:2018/04/08
//Author:Weixin Kong

#ifndef HORSE_H_
#define HORSE_H_
#include"Pieces.h"

class Horse:public Pieces
{
public:
	Horse();
	~Horse();
	void move(int nPosA, int nPosB);
private:

};


#endif // !HORSE_H_
#pragma once
