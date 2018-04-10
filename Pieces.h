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

private:
	int player;
	int posX;
	int posY;

};


#endif // !PIECES_H_
#pragma once
