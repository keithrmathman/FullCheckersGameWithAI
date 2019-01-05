#include "CheckerPiece.h"



CheckerPiece::CheckerPiece(CheckerPieceColor Ccolor, CheckerPieceType Ctype)
{
	this->Ccolor = Ccolor;
	this->Ctype = Ctype;
}


CheckerPiece::~CheckerPiece()
{
	std::cout << "Checker Piece deleted" << std::endl;
}

void CheckerPiece::setAsKing() 
{
	this->Ctype = KING;
}

bool CheckerPiece::isKing()
{
	return (this->Ctype == KING);
}

void CheckerPiece::setCoord(int Xcoor, int Ycoor)
{
	this->XCoor = Xcoor;
	this->Ycoor = Ycoor;

}

int CheckerPiece::getXcoor()
{
	return this->XCoor;
}

int CheckerPiece::getYcoor()
{
	return this->Ycoor;
}