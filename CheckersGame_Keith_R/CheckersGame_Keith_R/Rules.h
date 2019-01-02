#pragma once
#include "CheckerPiece.h"
class Rules
{
public:
	Rules();
	~Rules();
	const int BlackCheckerEndYcoor = 8;
	const int RedCheckerEndYcoor = 0;

	bool is_Valid_move(CheckerPiece* cp, int XCoor, int Ycoor, int Prev_X_Coor,int Prev_Ycoor);

	void KingMe(CheckerPiece* cp);///King me

	void jump(); 

	bool _at_opponents_end_of_board(int XCoor, int Ycoor, CheckerPiece* cp);

	
};

