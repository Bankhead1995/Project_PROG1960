//Project: Chess
//Date:2018/04/08
//Author:Weixin Kong

#ifndef HORSE_H_
#define HORSE_H_
#include"Pieces.h"
#include<string>

class Horse:public Pieces
{
public:
	Horse();
	~Horse();
	void move(int nPosA, int nPosB);
	int returnID();
private:
	int ID ;
};


#endif // !HORSE_H_
#pragma once
