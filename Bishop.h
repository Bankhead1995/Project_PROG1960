//Project: Chess
//Date:2018/04/08
//Author:Weixin Kong

#ifndef BISHOP_H_
#define BISHOP_H_
#include "Pieces.h"

class Bishop:public Pieces
{
public:
	Bishop();
	~Bishop();
	void move(int nPosA, int nPosB);
	int returnID();
private:
	int ID;
};


#endif // !BISHOP_H_
#pragma once
