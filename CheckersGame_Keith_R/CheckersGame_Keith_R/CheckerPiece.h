#pragma once
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

	CheckerPiece(CheckerPieceColor Ccolor, CheckerPieceType Ctype);
	~CheckerPiece();

	

	void setAsKing();
	bool isKing();

private:
	
	CheckerPieceColor Ccolor;
	CheckerPieceType Ctype;
};




