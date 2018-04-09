#ifndef PIECES_H_
#define PIECES_H_

class Pieces
{
public:
	Pieces();
	~Pieces();

	void setPos(int x, int y);
	void moveTo(int x, int y);
	int returnPosX();
	int returnPosY();

	virtual void move(int nPosA, int nPosB);

private:
	int player;
	int posX;
	int posY;
	int xTemp;
	int yTemp;
};


#endif // !PIECES_H_
#pragma once
