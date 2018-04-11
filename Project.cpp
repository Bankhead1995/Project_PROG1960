//Project Of PROG1960
//Last Edit: 2018/04/11
//Author: Weixin Kong

#include "Pieces.h"
#include "Horse.h"
#include "rook.h"
#include "Bishop.h"
#include "Pawn1.h"
#include "Pawn2.h"
#include "king.h"
#include "queen.h"
#include<iostream>
#include<vector>
using namespace std;


void board(Pieces*Player[2][16]);
int searchingPos(int player, int ix, int iy, Pieces*Player[2][16]);
int *path(int x,int y,int mX, int mY, int counter);
bool findBarrier(int x,int y,int mX,int mY, Pieces* Player[][16]);
void takePieceDown(int tx, int ty, int playNum, Pieces* Player[][16]);

int main()
{
	//////////initializing the pointer to the object *Player[player number][pieces number]//////////
	Pieces *Player[2][16];

	//////////initializing the objects for Player 0//////////
	Player[0][0] = new Horse;
	Player[0][1] = new Horse;
	Player[0][2] = new Bishop;
	Player[0][3] = new Bishop;
	Player[0][4] = new rook;
	Player[0][5] = new rook;
	Player[0][6] = new Pawn1;
	Player[0][7] = new Pawn1;
	Player[0][8] = new Pawn1;
	Player[0][9] = new Pawn1;
	Player[0][10] = new Pawn1;
	Player[0][11] = new Pawn1;
	Player[0][12] = new Pawn1;
	Player[0][13] = new Pawn1;
	Player[0][14] = new queen;
	Player[0][15] = new king;

	//////////initializing the startposition for all pieces//////////
	Player[0][0]->setPos(1, 7);
	Player[0][1]->setPos(6, 7);
	Player[0][2]->setPos(2, 7);
	Player[0][3]->setPos(5, 7);
	Player[0][4]->setPos(0, 7);
	Player[0][5]->setPos(7, 7);
	Player[0][6]->setPos(0, 6);
	Player[0][7]->setPos(1, 6);
	Player[0][8]->setPos(2, 6);
	Player[0][9]->setPos(3, 6);
	Player[0][10]->setPos(4, 6);
	Player[0][11]->setPos(5, 6);
	Player[0][12]->setPos(6, 6);
	Player[0][13]->setPos(7, 6);
	Player[0][14]->setPos(3, 7);
	Player[0][15]->setPos(4, 7);

	/////////display the board with the pieces in the start position//////////
	board(Player);

	system("pause");

	int ipX, ipY;
	int mtX, mtY;
	bool barrierFlag = 0;
	bool loop1 = true;
	bool loop2 = true;

	//////////define is the piece exist or not(if ture->move the poition to player want to) (else->error code "8888")//////////

	while (loop1 == true)
	{
		//////////input info//////////
		cout << endl;
		for (int i = 0; i < 2; i++)
		{
			while (loop2 == true)
			{
				cout << "Please tell me which piece you want to move(Player " << i + 1 << ")" << endl;
				cout << "X :";
				cin >> ipX;
				cout << "Y :";
				cin >> ipY;

				//////////searching which piece//////////
				int returncode = searchingPos(i, ipX, ipY, Player);

				if (returncode != 8888)
				{
					cout << endl << "Move to X :";
					cin >> mtX;
					cout << endl << "Move to Y :";
					cin >> mtY;

					barrierFlag = findBarrier(ipX, ipY, mtX, mtY, Player);

					if (barrierFlag == true)
					{

						takePieceDown(mtX, mtY, i, Player);
						Player[i][returncode]->move(mtX, mtY);
						loop2 = false;
					}
					else if(Player[i][returncode]->returnID()==5)
					{
						takePieceDown(mtX, mtY, i, Player);
						Player[i][returncode]->move(mtX, mtY);
						loop2 = false;
					}
					else if (barrierFlag == false)
					{
						cout <<"There is a pieces on your way, you can not move to there, Please enter again" << endl;
					}
				}
				else
				{
					cout << "Where is the Pieces?";
					cout << "Please enter again.";
					system("pause");
				}
			}
			system("cls");
			board(Player);//////////reprint the board with moved piece
			cout << "0 for quit the game";
			cin >> loop1;
		}
	}

    return 0;
}

void board(Pieces*Player[2][16])
{	
	//////////initializing the board ('0' representing blank)//////////
	char boardView[8][8] = { '0','0','0','0','0','0','0','0',
							 '0','0','0','0','0','0','0','0',
							 '0','0','0','0','0','0','0','0',
							 '0','0','0','0','0','0','0','0',
							 '0','0','0','0','0','0','0','0',
							 '0','0','0','0','0','0','0','0',
							 '0','0','0','0','0','0','0','0',
							 '0','0','0','0','0','0','0','0' };

	//////////Puting the pieces into the board//////////
	//////////'K' = King  = 1
	//////////'Q' = Queen = 2
	//////////'B' = Bishop= 3
	//////////'R' = Rook  = 4
	//////////'H' = Knight= 5
	//////////'P' = Pawn  = 6
	for (int i = 0; i < 16; i++)
	{
		int x = Player[0][i]->returnPosX();
		int y = Player[0][i]->returnPosY();
		switch (Player[0][i]->returnID())
		{
		case 0:
			boardView[x][y] = { '0' };
			break;
		case 1:
			boardView[x][y] = { 'K' };
			break;
		case 2:
			boardView[x][y] = { 'Q' };
			break;
		case 3:
			boardView[x][y] = { 'B' };
			break;
		case 4:
			boardView[x][y] = { 'R' };
			break;
		case 5:
			boardView[x][y] = { 'H' };
			break;
		case 6:
			boardView[x][y] = { 'P' };
			break;
		default:
			break;
		}
	}
	
	//////Print the Board//////
	for (int i = 0; i < 8; i++)
	{
		for (int z = 0; z < 8; z++)
		{
			cout << boardView[z][i];
		}
		cout << endl;
	}
}

////////////give the position to find the pieces number//////////////
int searchingPos(int playNum, int ipX, int ipY, Pieces*Player[2][16])
{
	for (int z = 0; z < 16; z++)
	{
		int opX = Player[playNum][z]->returnPosX();
		int opY = Player[playNum][z]->returnPosY();

		if ((ipX == opX) && (ipY == opY))
		{
			return z;
		}
	}
	return 8888;
}

///////////Find the position in the path///////////
int *path(int x, int y, int mX, int mY, int counter)
{
	int a, b;
	a = mX - x;
	b = mY - y;

	int * op = new int[2];

	if (a < 0 && b < 0)
	{
		op[0] = x - counter;
		op[1] = y - counter;
	}
	else if (a > 0 && b > 0)
	{
		op[0] = x + counter;
		op[1] = y + counter;
	}
	else if(a < 0 && b >0)
	{
		op[0] = x - counter;
		op[1] = y + counter;
	}
	else if (a > 0 && b < 0)
	{
		op[0] = x + counter;
		op[1] = y - counter;
	}
	else if (a == 0 && b > 0)
	{
		op[0] = x;
		op[1] = y + counter;
	}
	else if (a == 0 && b < 0)
	{
		op[0] = x;
		op[1] = y - counter;
	}
	else if (a < 0 && b == 0)
	{
		op[0] = x - counter;
		op[1] = y;
	}
	else if (a > 0 && b == 0)
	{
		op[0] = x + counter;
		op[1] = y;
	}
	else
	{
		system("cls");
		cout << endl << "error!!!!!";
	}
	return op;
}

/////////////////find is there any piece on it's way////////////////
bool findBarrier(int x, int y, int mX, int mY, Pieces* Player[][16])
{
	int diffX = mX - x;
	int diffY = mY - y;
	int *retPos;
	for (int i = 1; i < abs(diffX) || i < abs(diffY); i++)
	{
		retPos = path(x, y, mX, mY, i);
		const int retX = retPos[0];
		const int retY = retPos[1];

		for (int z = 0; z < 1; z++)
		{
			for (int q = 0; q < 16; q++)
			{
				if (((Player[z][q]->returnPosX()) == retX) && (Player[z][q]->returnPosY() == retY))
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

//////////As the name//////////
void takePieceDown(int tX, int tY, int playNum ,Pieces* Player[][16])
{
	for (int z = 0; z < 16; z++)
	{
		int opX = Player[playNum][z]->returnPosX();
		int opY = Player[playNum][z]->returnPosY();

		if ((tX == opX) && (tY == opY))
		{
			Player[playNum][z]->deletePiece();
		}
	}
}
