
#include <iostream>
#include<vector>
#include<algorithm>
#include "CheckersBoard.h"
#include "CheckerPiece.h"
#include "Rules.h"

using namespace std;

int main()
{


	CheckersBoard CB;

	CB.DisplayColorsOnBoard();

	//CB.InitalizelayoutOfcheckerPiecesOnBoard();

	CB.PrintBoardToScreen();


	//CB.setCheckerPositionsOnBoard(1, 3, 1);
	//CB.setCheckerPositionsOnBoard(1, 5, 1);
	//CB.setCheckerPositionsOnBoard(1, 7,1);
	//CB.setCheckerPositionsOnBoard(3,7,1);

	//CB.setCheckerPositionsOnBoard(2, 1, 2);
	//CB.setCheckerPositionsOnBoard(5,2,2);
	//CB.setCheckerPositionsOnBoard(5,6,2);
	//CB.setCheckerPositionsOnBoard(7, 7,2);
	//

	//CB.setBoardCheckerPieceMoved(5, 4);

	//

	//CB.PlacePiecesOnBoard();

	//CB.clearCheckerPositions();


	////CB.setCheckerPositionsOnBoard(1, 2, 1);
	//CB.setCheckerPositionsOnBoard(2, 5, 1);
	//CB.setCheckerPositionsOnBoard(7, 1, 1);
	//CB.setCheckerPositionsOnBoard(7, 7, 1);

	//CB.setCheckerPositionsOnBoard(2, 1, 2);
	//CB.setCheckerPositionsOnBoard(4, 5, 2);
	//CB.setCheckerPositionsOnBoard(6, 6, 2);
	//CB.setCheckerPositionsOnBoard(6, 7, 2);

	CB.PlacePiecesOnBoard();

	CB.printAllPlayableSquares();

	CheckerPiece* cp_1[12];// = static_cast<CheckerPiece*>(alloca(12 * sizeof(CheckerPiece)));
	int x = 0; int y = 0, starting_x = 0;;
	for (int i = 0; i < 12;)
	{
		for (int j = 0; j < 7; j+=2)
		{
			
			cp_1[i] = new CheckerPiece(CheckerPiece::RED, CheckerPiece::SINGLE);
			cp_1[i]->setCoord(x, y);
			i++;
			x += 2;
		}
		starting_x = !starting_x;
		x = starting_x;
		y++;
	}

	CheckerPiece* cp_2[12];// = static_cast<CheckerPiece*>(alloca(12 * sizeof(CheckerPiece)));
	 x = 1, y = 7, starting_x = 1;;
	for (int i = 0; i < 12;)
	{
		for (int j = 0; j < 7; j += 2)
		{

			cp_2[i] = new CheckerPiece(CheckerPiece::RED, CheckerPiece::SINGLE);
			cp_2[i]->setCoord(x, y);
			i++;
			x += 2;
		}
		starting_x = !starting_x;
		x = starting_x;
		y--;
	}

	CB.PrintAllCheckerPositions(cp_1, cp_2, 12, 12);

	cp_1[0]->setAsKing();
	cp_1[11]->setAsKing();
	cp_1[1]->setAsKing();
	cp_1[5]->setAsKing();
	cp_1[7]->setAsKing();
	cp_1[8]->setAsKing();
	cp_1[2]->setAsKing();
	cp_1[3]->setAsKing();
	cp_1[4]->setAsKing();
	cp_1[6]->setAsKing();
	cp_1[9]->setAsKing();
	cp_1[10]->setAsKing();
	//for (int i = 0; i < 12; i++)
	{
		CB.DisplayAllPossibleMovesOnBoard(1, cp_2, 12);
	}

	cp_1[0]->setCoord(0, 4);
	cp_1[1]->setCoord( 2,4);
	cp_1[2]->setCoord(4, 4);
	cp_1[3]->setCoord(6,4);

	CB.updateBoardSquares(cp_1, cp_2);
	//cout << "\n\n is the square occupied? " << CB.isSquareOccupied(0,0) << std::endl;
	Rules rules;
	rules.cb = CB;
	CheckersBoard::BoardPieceCoordinates cb_coor[12];
	rules.Check_for_possible_jumps(cb_coor, cp_1, cp_2, 12, 12, 2);
	//rules.Check_for_possible_jumps(cb_coor, cp_1, cp_2, 12, 12, 1);
	return 0;
}