#include "CheckersBoard.h"



CheckersBoard::CheckersBoard()
{
	int i = 0, j = 0, k = 0;
	while(i < 8)
	{
		while(j < 8)
		{
			BoardColorLayout[i][j] = BoardSquareColor::LIGHT;
			BoardColorLayout[i][++j] = BoardSquareColor::DARK;
			++j;
		}
		i++;

		while(k < 8)
		{
			BoardColorLayout[i][k] = BoardSquareColor::DARK;
			BoardColorLayout[i][++k] = BoardSquareColor::LIGHT;
			++k;
		}
		i++;

		j = 0, k = 0;
	}

	 putAllPlayableSquareCoordinatesToArray();
	//InitalizelayoutOfcheckerPiecesOnBoard();
	//this->Board = Board;
}



CheckersBoard::~CheckersBoard()
{
}

//Displays the layout of color squares(light,dark) on the checker board
void CheckersBoard::DisplayColorsOnBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << "|" << BoardColorLayout[i][j]  << "|";
			
		}
		std::cout << "\n";
	}
}

void CheckersBoard::printAllPlayableSquares()
{
	std::cout << "Coordinate List of Playable Squares\n\n" << std::endl;
	for (int i = 0; i < numberOfPlayableSquaresOnCheckerBoard; i++)
	{
		
		std::cout << PlayableSquaresOnBoardArray[i].Xcoor << "," << PlayableSquaresOnBoardArray[i].Ycoor << std::endl;
	}

}


//Initalize Standard checkers board layout
void CheckersBoard::InitalizelayoutOfcheckerPiecesOnBoard()
{

	std::string NewBoard[8][8] =
	{ {"|  ","|P1","|  ","|P1","|  ","|P1","|  ","|P1" },
	{"|P1","|  ","|P1","|  ","|P1","|  ","|P1","|  " },
	{ "|  ","|P1","|  ","|P1","|  ","|P1","|  ","|P1" },
	{"|  ","|  ","|  ","|  ","|  ","|  ","|  ","|  " },
	{ "|  ","|  ","|  ","|  ","|  ","|  ","| " ,"|  " },
	{"|P2","|  ","|P2","|  ","|P2","|  ","|P2","|  " },
	{"|  ","|P2","|  ","|P2","|  ","|P2","|  ","|P2" },
	{"|P2","|  ","|P2","|  ","|P2","|  ","|P2","|  " },
	};

	//Board = NewBoard;
}


void CheckersBoard::PrintBoardToScreen()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << "|" << Board[i][j];

		}
		std::cout << "\n";
	}
}

void CheckersBoard::ResetBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << "|" << Board[i][j];

		}
		std::cout << "\n";
	}
}


//NOT OPTIMAL CODE---->> CHANGE LATER 
void CheckersBoard::PlacePiecesOnBoard( )
{
	int Player1marker = 0, Player2marker = 0, Player1VectorSize = Player1CheckerPieces.size(), Player2VectorSize = Player2CheckerPieces.size();

	std::cout << "number of checker pieces for player 1: " << Player1VectorSize << "\n\nnumber of checker pieces for player 2: " << Player2VectorSize << std::endl;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Player1marker < Player1VectorSize)
			{
				if (i == Player1CheckerPieces[Player1marker].Xcoor && j == Player1CheckerPieces[Player1marker].Ycoor )
				{
					Player1marker++;
					std::cout << "||P1";
					Board[i][j] = "||P1";
					continue;
				}
			}
		 if (Player2marker < Player2VectorSize)
			{
				if (i == Player2CheckerPieces[Player2marker].Xcoor && j == Player2CheckerPieces[Player2marker].Ycoor)
				{
					Player2marker++;
					std::cout << "||P2";
					Board[i][j] = "||P2";
					continue;
				}
			}
			
				std::cout << "||  ";
				Board[i][j] = "||  ";
			

			//checker piece that was moved from board is now gone so this becomes an empty space
			if (i == BoardCheckerPieceMovedorRemoved.Xcoor && j == BoardCheckerPieceMovedorRemoved.Ycoor)
			{
				std::cout << "||  ";
				Board[i][j] = "||  ";
			}


		}
		std::cout << "\n";
	}

	std::cout << "\n\n\n\n";
}

void CheckersBoard::clearCheckerPositions()
{
	Player1CheckerPieces.clear();
	Player2CheckerPieces.clear();
}
void CheckersBoard::MoveCheckerPiece(CheckerPiece* cp, int newX, int newY)
{
	cp->setCoord(newX, newY);
}

void CheckersBoard::setBoardCheckerPieceMoved(int CheckerPieceNumber, int Xcoor, int Ycoor)
{
	CheckerPieceNumber_ThatisbeingMovedorRemoved = CheckerPieceNumber;
	BoardCheckerPieceMovedorRemoved.Xcoor = Xcoor;
	BoardCheckerPieceMovedorRemoved.Ycoor = Ycoor;
}

void CheckersBoard::PrintAllCheckerPositions(CheckerPiece** Player1_cp, CheckerPiece** Player2_cp,int P1_CheckerPieces_size, int Player2_CheckerPieces_size)
{
	std::cout << "\n\n\nPlayer 1 Piece Coordinates: " << std::endl;

	for (int t = 0; t < P1_CheckerPieces_size; t++)
	{
		std::cout << Player1_cp[t]->getXcoor() << ", " << Player1_cp[t]->getYcoor() << std::endl;
	}
	/*std::vector<BoardPieceCoordinates>::iterator it; 

	for (it = Player1CheckerPieces.begin(); it != Player1CheckerPieces.end(); ++it)
	{
		std::cout << it->Xcoor <<"," << it->Ycoor << std::endl;
	}*/

	std::cout << "\n\n\nPlayer 2 Piece Coordinates: " << std::endl;
	for (int t = 0; t < P1_CheckerPieces_size; t++)
	{
		std::cout << Player2_cp[t]->getXcoor() << ", " << Player2_cp[t]->getYcoor() << std::endl;
	}
	/*for (it = Player2CheckerPieces.begin(); it != Player2CheckerPieces.end(); ++it)
	{
		std::cout << it->Xcoor << "," << it->Ycoor << std::endl;
	}*/
}


void CheckersBoard:: putAllPlayableSquareCoordinatesToArray()
{
	int x = 0; 
	int y = 0;
	int Arrindex = 0;

	for (int i = 0; i < 8;)
	{
		for (int j = 1; j < 8; j+=2)
		{
			PlayableSquaresOnBoardArray[Arrindex].Xcoor = i;
			PlayableSquaresOnBoardArray[Arrindex].Ycoor = j;
			Arrindex++;
		}
		i++;

		for (int j = 0; j < 8; j+=2)
		{
			PlayableSquaresOnBoardArray[Arrindex].Xcoor = i;
			PlayableSquaresOnBoardArray[Arrindex].Ycoor = j;
			Arrindex++;
		}
		i++;
	}
}

//playerno_totalnumberOfcheckerpieces -- total number of checkers on checker board for each checker player
void CheckersBoard::DisplayAllPossibleMovesOnBoard(int PlayerNo, CheckerPiece** cp, int playerno_totalnumberOfcheckerpieces)
{
	LinkedList LinkedlistArr[12];


	for (int t = 0; t < playerno_totalnumberOfcheckerpieces; t++)
	{
		if (PlayerNo == 1)
		{
			if (cp[t]->isKing())
			{

				LinkedlistArr[t] = checkForPossibleMoves(cp[t]->getXcoor(), cp[t]->getYcoor(), true, PlayerNo);


			}

			else//if checker piece is not a king
				//for (int t = 0; t < playerno_totalnumberOfcheckerpieces; t++)
				{
					LinkedlistArr[t] = checkForPossibleMoves(cp[t]->getXcoor(), cp[t]->getYcoor(), false, PlayerNo);

				}
		}
	}

	if (PlayerNo == 2)
	{
		if (cp[t]->isKing())
		{
			for (int t = 0; t < playerno_totalnumberOfcheckerpieces; t++)
			{
				LinkedlistArr[t] = checkForPossibleMoves(cp[t]->getXcoor(), cp[t]->getYcoor(), true, PlayerNo);

			}
		}

		else
			for (int t = 0; t < playerno_totalnumberOfcheckerpieces; t++)
			{
				LinkedlistArr[t] = checkForPossibleMoves(cp[t]->getXcoor(), cp[t]->getYcoor(), false, PlayerNo);

			}
	}

	cout << " All Possible Moves For Each checker piece:\n\n " << endl;
	for (int i = 0; i < 12 && LinkedlistArr[i].head != NULL; i++)
	{
		LinkedlistArr[i].print(i);
	}

}


void CheckersBoard::setCheckerPositionsOnBoard(int Xcoor, int Ycoor, int PlayerNo)
	{
		BoardPieceCoordinates bpc;
		
		if (PlayerNo == 1)
		{
			bpc.Xcoor = Xcoor;
			bpc.Ycoor = Ycoor;

			Player1CheckerPieces.push_back(bpc);
			numberOfPlayer1CheckerPieceCoordinatesMapped++;
		}

		else if (PlayerNo == 2)
		{
			bpc.Xcoor = Xcoor;
			bpc.Ycoor = Ycoor;

			Player2CheckerPieces.push_back(bpc);
			numberOfPlayer2CheckerPieceCoordinatesMapped++;
		}
	}


LinkedList CheckersBoard::checkForPossibleMoves(int xcoor, int ycoor, bool isKing, int playerNo)
{
	LinkedList Llist;
	//BoardPieceCoordinates bpc,bpc2,bpc3,bpc4;

	if (isKing)//if checker piece is a king, then the piece can move in 4 possible squares if in bounds

	{
		if (xcoor + 1 < 8 && ycoor + 1 < 8)
		{
			Llist.add(xcoor + 1, ycoor + 1);
			/*bpc.Xcoor = xcoor + 1;
			bpc.Ycoor = ycoor + 1;
			Llist.add(bpc);*/
		}
		
		if (xcoor - 1 >= 0 && ycoor + 1 < 8)
		{
			Llist.add(xcoor - 1, ycoor + 1);
			/*bpc2.Xcoor = xcoor - 1;
			bpc2.Ycoor = ycoor + 1;
			Llist.add(bpc2);*/
		}
		if (xcoor + 1 < 8 && ycoor - 1 >= 0)
		{
			Llist.add(xcoor + 1, ycoor - 1);
			/*bpc3.Xcoor = xcoor + 1;
			bpc3.Ycoor = ycoor - 1;
			Llist.add(bpc3);*/
		}

		if (xcoor - 1 >= 0 && ycoor - 1 >= 0)
		{
			Llist.add(xcoor - 1, ycoor - 1);
			/*bpc4.Xcoor = xcoor - 1;
			bpc4.Ycoor = ycoor - 1;
			Llist.add(bpc4);*/
		}

		return Llist;
	}

	if (playerNo == 1)
	{
		if (xcoor + 1 < 8 && ycoor + 1 < 8)
		{
			Llist.add(xcoor + 1, ycoor + 1);
			/*bpc.Xcoor = xcoor + 1;
			bpc.Ycoor = ycoor + 1;
			Llist.add(bpc);*/

		}

		if (xcoor - 1 >= 0 && ycoor + 1 < 8)
		{
			Llist.add(xcoor - 1, ycoor + 1);
			/*bpc2.Xcoor = xcoor - 1;
			bpc2.Ycoor = ycoor + 1;
			Llist.add(bpc2);*/
		}
	}

	if (playerNo == 2)
	{
		if (xcoor - 1 >= 0 && ycoor - 1 >= 0)
		{
			Llist.add(xcoor - 1, ycoor - 1);
			/*bpc4.Xcoor = xcoor - 1;
			bpc4.Ycoor = ycoor - 1;
			Llist.add(bpc4);*/
		}

		if (xcoor + 1 < 8 && ycoor - 1 >= 0)
		{
			Llist.add(xcoor + 1, ycoor - 1);
			/*bpc3.Xcoor = xcoor + 1;
			bpc3.Ycoor = ycoor - 1;
			Llist.add(bpc3);*/
		}
	}

	return Llist;
	
}