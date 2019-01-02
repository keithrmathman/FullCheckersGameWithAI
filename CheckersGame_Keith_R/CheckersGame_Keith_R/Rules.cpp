#include "Rules.h"



Rules::Rules()
{
}


Rules::~Rules()
{
}


void Rules::KingMe(CheckerPiece* cp)
{
	cp->setAsKing();
}