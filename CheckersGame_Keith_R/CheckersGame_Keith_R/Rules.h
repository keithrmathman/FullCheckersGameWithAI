#pragma once
#include "CheckerPiece.h"
#include "CheckersBoard.h"
class Rules
{
public:
	Rules();
	~Rules();
	const int BlackCheckerEndYcoor = 8;
	const int RedCheckerEndYcoor = 0;

	bool is_Valid_move(CheckerPiece* cp, int XCoor, int Ycoor, int Prev_X_Coor,int Prev_Ycoor);

	void KingMe(CheckerPiece* cp);///King me

	//this function takes in all of player1 and player2 checker pieces and returns the total number of possible jump moves for whicher player's turn it is.
	int Check_for_possible_jumps(CheckersBoard::BoardPieceCoordinates* possible_jump_coordinates, CheckerPiece** p1_cp, CheckerPiece** p2_cp, int number_of_player1_checkerpieces, int number_of_player2_checkerpieces, int Players_Turn);

	bool _at_opponents_end_of_board(int XCoor, int Ycoor, CheckerPiece* cp);

	void ConfigureCheckerPiecesOnGameBoard();

	enum  PlayerDirection
	{
		UP,
		DOWN
	};

	PlayerDirection Player1_Direction = UP;
	PlayerDirection Player2_direction = DOWN;
	/*PlayerDirection GetPlayerDirection()
	{
		return;
	}*/
};

