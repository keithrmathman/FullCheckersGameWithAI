#include "CheckerPiece.h"



CheckerPiece::CheckerPiece(CheckerPieceColor Ccolor, CheckerPieceType Ctype)
{
	this->Ccolor = Ccolor;
	this->Ctype = Ctype;
}


CheckerPiece::~CheckerPiece()
{

}

void CheckerPiece::setAsKing() 
{
	this->Ctype = KING;
}

bool CheckerPiece::isKing()
{
	return (this->Ctype == KING);
}