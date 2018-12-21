#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "string.h"


class CheckersBoard
{
public:
	CheckersBoard();
	~CheckersBoard();
	

	enum CheckerPieceColor
	{
		RED,
		BLACK
	};

	enum BoardSquareColor
	{
		LIGHT,
		DARK
	};

	

	void CheckersBoard::DisplayColorsOnBoard();
	void ResetBoard();
	void InitalizelayoutOfcheckerPiecesOnBoard();
	void CheckersBoard::PrintBoardToScreen();
	void setCheckerPositionsOnBoard(int Xcoor, int Ycoor, int PlayerNo);
	void setBoardCheckerPieceMoved(int Xcoor, int Ycoor);
	void CheckersBoard::clearCheckerPositions();
	void PrintAllCheckerPositions();
	void CheckersBoard::PlacePiecesOnBoard();

private:
	 int numberOfPlayer1CheckerPieceCoordinqtesMapped = 0, numberOfPlayer2CheckerPieceCoordinqtesMapped = 0;
	
	 struct BoardPieceCoordinates
	{
		int Xcoor;
		int Ycoor;
	};

	
	std::vector<BoardPieceCoordinates> Player1CheckerPieces;
	std::vector<BoardPieceCoordinates> Player2CheckerPieces;

	BoardPieceCoordinates BoardCheckerPieceMovedorRemoved;

	

	int BoardColorLayout[8][8];
	
	std::string Board[8][8] = 
	{ { "|  ","|P1","|  ","|P1","|  ","|P1","|  ","|P1" },
	{ "|P1","|  ","|P1","|  ","|P1","|  ","|P1","|  " },
	{ "|  ","|P1","|  ","|P1","|  ","|P1","|  ","|P1" },
	{ "|  ","|  ","|  ","|  ","|  ","|  ","|  ","|  " },
	{ "|  ","|  ","|  ","|  ","|  ","|  ","|  " ,"|  " },
	{ "|P2","|  ","|P2","|  ","|P2","|  ","|P2","|  " },
	{ "|  ","|P2","|  ","|P2","|  ","|P2","|  ","|P2" },
	{ "|P2","|  ","|P2","|  ","|P2","|  ","|P2","|  " },
	};;// [8][8];
	
};

