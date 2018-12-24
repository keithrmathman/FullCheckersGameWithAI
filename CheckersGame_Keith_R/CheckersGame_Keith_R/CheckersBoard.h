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
	void PrintAllCheckerPositions(); //print all checker pieces 
	void CheckersBoard::PlacePiecesOnBoard();//lists coordinates of squares that are playable to array 
	void printAllPlayableSquares(); //prints list of squares the checker pieces are allowed to land

private:
	 int numberOfPlayer1CheckerPieceCoordinqtesMapped = 0, numberOfPlayer2CheckerPieceCoordinqtesMapped = 0;
	 int numberOfPlayableSquaresOnCheckerBoard = 32;//number of playable squares on checker board

	 struct BoardPieceCoordinates
	{
		int Xcoor;
		int Ycoor;
	};

	 BoardPieceCoordinates PlayableSquaresOnBoardArray[32];
	std::vector<BoardPieceCoordinates> Player1CheckerPieces;
	std::vector<BoardPieceCoordinates> Player2CheckerPieces;

	BoardPieceCoordinates BoardCheckerPieceMovedorRemoved;

	void putAllPlayableSquareCoordinatesToArray();

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

