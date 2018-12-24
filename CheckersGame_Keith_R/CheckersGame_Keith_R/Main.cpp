
#include <iostream>
#include<vector>
#include<algorithm>
#include "CheckersBoard.h"

using namespace std;

int main()
{


	CheckersBoard CB;

	CB.DisplayColorsOnBoard();

	//CB.InitalizelayoutOfcheckerPiecesOnBoard();

	CB.PrintBoardToScreen();


	CB.setCheckerPositionsOnBoard(1, 3, 1);
	CB.setCheckerPositionsOnBoard(1, 5, 1);
	CB.setCheckerPositionsOnBoard(1, 7,1);
	CB.setCheckerPositionsOnBoard(3,7,1);

	CB.setCheckerPositionsOnBoard(2, 1, 2);
	CB.setCheckerPositionsOnBoard(5,2,2);
	CB.setCheckerPositionsOnBoard(5,6,2);
	CB.setCheckerPositionsOnBoard(7, 7,2);
	

	CB.setBoardCheckerPieceMoved(5, 4);

	CB.PrintAllCheckerPositions();

	CB.PlacePiecesOnBoard();

	CB.clearCheckerPositions();


	//CB.setCheckerPositionsOnBoard(1, 2, 1);
	CB.setCheckerPositionsOnBoard(2, 5, 1);
	CB.setCheckerPositionsOnBoard(7, 1, 1);
	CB.setCheckerPositionsOnBoard(7, 7, 1);

	CB.setCheckerPositionsOnBoard(2, 1, 2);
	CB.setCheckerPositionsOnBoard(4, 5, 2);
	CB.setCheckerPositionsOnBoard(6, 6, 2);
	CB.setCheckerPositionsOnBoard(6, 7, 2);

	CB.PlacePiecesOnBoard();

	CB.printAllPlayableSquares();
	return 0;
}