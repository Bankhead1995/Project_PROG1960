//Project: Chess
//Date:2018/04/11
//Author:Weixin Kong

#ifndef PIECES_H_
#define PIECES_H_

class Pieces
{
public:
	Pieces();
	~Pieces();

	void setPos(int x, int y);
	int returnPosX();
	int returnPosY();

	virtual void move(int nPosA, int nPosB);
	virtual int returnID();
	virtual void deletePiece();

private:
	int player;
	int posX;
	int posY;

};


#endif // !PIECES_H_
#pragma once
