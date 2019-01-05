#pragma once
#include <iostream> 

class CheckerPiece
{
public:
	enum CheckerPieceType
	{
		KING,
		SINGLE
	};
	enum CheckerPieceColor
	{
		RED,
		BLACK
	};

	CheckerPiece();
	CheckerPiece(CheckerPieceColor Ccolor, CheckerPieceType Ctype);
	~CheckerPiece();

	//set new checker coordinates
	void setCoord(int Xcoor, int Ycoor);
	int getXcoor();
	int getYcoor();
	void setAsKing();
	bool isKing();

private:
	
	int XCoor; 
	int Ycoor;
	CheckerPieceColor Ccolor;
	CheckerPieceType Ctype;
};




