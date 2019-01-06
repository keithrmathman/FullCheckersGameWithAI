#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "string.h"
#include "CheckerPiece.h"
#include "..\CheckersGame_Keith_R\LinkedList.h"





using namespace std;



class CheckersBoard
{

public:
	CheckersBoard();
	~CheckersBoard();
	
	//friend class ::Node;
	//friend class ::LinkedList;
	
	struct BoardPieceCoordinates
	{

		int Xcoor;
		int Ycoor;
	};

	int t;
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
	void setBoardCheckerPieceMoved(int CheckerPieceNumber, int Xcoor, int Ycoor);
	void CheckersBoard::clearCheckerPositions();
	void PrintAllCheckerPositions(CheckerPiece** Player1_cp, CheckerPiece** Player2_cp,  int P1_CheckerPieces_size, int Player2_CheckerPieces_size); //print all checker pieces 
	void CheckersBoard::PlacePiecesOnBoard();//lists coordinates of squares that are playable to array 
	void printAllPlayableSquares(); //prints list of squares the checker pieces are allowed to land
	void DisplayAllPossibleMovesOnBoard(int PlayerNo, CheckerPiece** cp, int playerno_totalnumberOfcheckerpieces);
	void MoveCheckerPiece(CheckerPiece* cp, int newX, int newY); //move checker piece to new location
private:

	
	int CheckerPieceNumber_ThatisbeingMovedorRemoved;
	 int numberOfPlayer1CheckerPieceCoordinatesMapped = 0, numberOfPlayer2CheckerPieceCoordinatesMapped = 0;
	 int numberOfPlayableSquaresOnCheckerBoard = 32;//number of playable squares on checker board
	 LinkedList checkForPossibleMoves(int xcoor, int ycoor, bool isKing, int playerNo);
	 
	

	 BoardPieceCoordinates PlayableSquaresOnBoardArray[32];
	std::vector<BoardPieceCoordinates> Player1CheckerPieces;
	std::vector<BoardPieceCoordinates> Player2CheckerPieces;
	std::vector<BoardPieceCoordinates> PossibleMovingSquares;
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
