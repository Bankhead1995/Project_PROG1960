//Project Of PROG1960
//Last Edit: 2018/04/09
//Author: Adam Oliver
//		  Weixin Kong

#include "Pieces.h"
#include "Horse.h"
#include "rook.h"
#include "Bishop.h"
#include "Pawn1.h"
#include<iostream>
#include<vector>
using namespace std;


void board(Pieces*Player[2][16]);
int searchingPos(int player, int ix, int iy, Pieces*Player[2][16]);

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

	/////////display the board with the pieces in the start position//////////
	board(Player);

	//////////input info//////////
	system("pause");
	int num;
	cout << "enter player number: " ;
	cin >> num;

	int ipX, ipY;
	int mtX, mtY;
	cout << endl << "X :";
	cin >> ipX;
	cout << endl << "Y :";
	cin >> ipY;
	
	//////////searching which piece//////////
	int returncode = searchingPos(num, ipX, ipY, Player);

	//////////define is the piece exist or not(if ture->move the poition to player want to) (else->error code "8888")//////////
	if (returncode!=8888)
	{
		cout << endl << "Move to X :";
		cin >> mtX;
		cout << endl << "Move to Y :";
		cin >> mtY;
		Player[num][returncode]->move(mtX, mtY);
	}
	else
	{
		cout << "Where is the Pieces?";
	}

	//////////reprint the board with moved piece//////////
	board(Player);

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
	for (int i = 0; i < 14; i++)
	{
		int x = Player[0][i]->returnPosX();
		int y = Player[0][i]->returnPosY();
		switch (Player[0][i]->returnID())
		{
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
	
	//////////Print the Board/////////
	for (int i = 0; i < 8; i++)
	{
		for (int z = 0; z < 8; z++)
		{
			cout << boardView[z][i];
		}
		cout << endl;
	}
}

//////////give the position to find the pieces number////////////
int searchingPos(int playNum, int ipX, int ipY, Pieces*Player[2][16])
{
	for (int z = 0; z < 14; z++)
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