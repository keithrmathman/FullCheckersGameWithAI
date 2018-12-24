#pragma once
class CheckerPiece
{
public:
	CheckerPiece();
	~CheckerPiece();

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
};

