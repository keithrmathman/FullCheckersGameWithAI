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
void CheckersBoard::PlacePiecesOnBoard()
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
	
void CheckersBoard::setBoardCheckerPieceMoved(int Xcoor, int Ycoor)
{
	BoardCheckerPieceMovedorRemoved.Xcoor = Xcoor;
	BoardCheckerPieceMovedorRemoved.Ycoor = Ycoor;
}

void CheckersBoard::PrintAllCheckerPositions()
{
	std::cout << "\n\n\nPlayer 1 Piece Coordinates: " << std::endl;
	std::vector<BoardPieceCoordinates>::iterator it; 

	for (it = Player1CheckerPieces.begin(); it != Player1CheckerPieces.end(); ++it)
	{
		std::cout << it->Xcoor <<"," << it->Ycoor << std::endl;
	}

	std::cout << "\n\n\nPlayer 2 Piece Coordinates: " << std::endl;
	for (it = Player2CheckerPieces.begin(); it != Player2CheckerPieces.end(); ++it)
	{
		std::cout << it->Xcoor << "," << it->Ycoor << std::endl;
	}
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


void CheckersBoard::setCheckerPositionsOnBoard(int Xcoor, int Ycoor, int PlayerNo)
	{
		BoardPieceCoordinates bpc;
		
		if (PlayerNo == 1)
		{
			bpc.Xcoor = Xcoor;
			bpc.Ycoor = Ycoor;

			Player1CheckerPieces.push_back(bpc);
			numberOfPlayer1CheckerPieceCoordinqtesMapped++;
		}

		else if (PlayerNo == 2)
		{
			bpc.Xcoor = Xcoor;
			bpc.Ycoor = Ycoor;

			Player2CheckerPieces.push_back(bpc);
			numberOfPlayer2CheckerPieceCoordinqtesMapped++;
		}
	}


