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

//Players_Turn= tells which player's turn it is to make a move
int Rules::Check_for_possible_jumps(CheckersBoard::BoardPieceCoordinates* possible_jump_coordinates, CheckerPiece** p1_cp, CheckerPiece** p2_cp, int number_of_player1_checkerpieces, int number_of_player2_checkerpieces, int Players_Turn)
{

	int temp1, temp2, temp3, temp4, numberOfCheckersthatcanjump = 0 ;
	if (Players_Turn == 1)
	{
		for (int i = 0; i < number_of_player1_checkerpieces; i++)
		{
			temp1 = p1_cp[i]->getXcoor(); temp2 = p1_cp[i]->getYcoor();

			for (int j = 0; j < number_of_player2_checkerpieces; j++)
			{
				if (temp1 + 2 < 8 && temp2 + 2 < 8 && !cb.isSquareOccupied(temp1, temp2))//if move will be in bounds and space of the desired move is not occupied
				{
					if ((temp1 + 1) == p2_cp[j]->getXcoor() && temp2 + 1 == p2_cp[j]->getYcoor())
					{
						possible_jump_coordinates[numberOfCheckersthatcanjump].Xcoor = (temp1 + 2);
						possible_jump_coordinates[numberOfCheckersthatcanjump].Ycoor = (temp2 + 2);
						numberOfCheckersthatcanjump++;
					}
					if (temp1 - 2 >= 0 && !cb.isSquareOccupied(temp1,temp2))//if move will be in bounds
					{
						if ((temp1 - 1) == p2_cp[j]->getXcoor() && temp2 + 1 == p2_cp[j]->getYcoor())
						{
							possible_jump_coordinates[numberOfCheckersthatcanjump].Xcoor = (temp1 - 2);
							possible_jump_coordinates[numberOfCheckersthatcanjump].Ycoor = (temp2 + 2);
							numberOfCheckersthatcanjump++;
						}
					}
				
					if (p1_cp[i]->isKing())
					{
						if (temp1 + 2 < 8 && temp2 - 2 >= 0 &&  !cb.isSquareOccupied(temp1, temp2))//if move will be in bounds--moving backwards right on board
						{
							if ((temp1 + 1) == p2_cp[j]->getXcoor() && temp2 + 1 == p2_cp[j]->getYcoor())
							{
								possible_jump_coordinates[numberOfCheckersthatcanjump].Xcoor = (temp1 + 2);
								possible_jump_coordinates[numberOfCheckersthatcanjump].Ycoor = (temp2 - 2);
								numberOfCheckersthatcanjump++;
							}
							if (temp1 - 2 >= 0 && !cb.isSquareOccupied(temp1, temp2))//if move will be in bounds--moving backwards left
							{
								if ((temp1 - 1) == p2_cp[j]->getXcoor() && temp2 + 1 == p2_cp[j]->getYcoor())
								{
									possible_jump_coordinates[numberOfCheckersthatcanjump].Xcoor = (temp1 - 2);
									possible_jump_coordinates[numberOfCheckersthatcanjump].Ycoor = (temp2 - 2);
									numberOfCheckersthatcanjump++;
								}
							}


					}
				
				
					
				}
			}
		}
				
			}
		}

	if (Players_Turn == 2)
	{
		for (int i = 0; i < number_of_player2_checkerpieces; i++)
		{
			temp1 = p2_cp[i]->getXcoor(); temp2 = p2_cp[i]->getYcoor();

			for (int j = 0; j < number_of_player1_checkerpieces; j++)
			{
				if (temp1 + 2 < 8 && temp2 - 2 >= 0  )//if move will be in bounds
				{
					cout << temp1 + 2 << ", " << temp2 - 2 << endl;
					if (!cb.isSquareOccupied(temp1 + 2, temp2 - 2))
					{
						cout << "NON OCCUPIED SQUARE\n";
						if ((temp1 + 1) == p1_cp[j]->getXcoor() && temp2 - 1 == p1_cp[j]->getYcoor())
						{
							cout << "possible jump\n\n";
							possible_jump_coordinates[numberOfCheckersthatcanjump].Xcoor = (temp1 + 2);
							possible_jump_coordinates[numberOfCheckersthatcanjump].Ycoor = (temp2 + 2);
							numberOfCheckersthatcanjump++;
						}

					}
					cout << temp1 - 2 << ", " << temp2 - 2 << endl;
					if (temp1 - 2 >= 0 && !cb.isSquareOccupied(temp1 - 2, temp2 -2))//if move will be in bounds
					{
						cout << "NON OCCUPIED SQUARE\n";
						if ((temp1 - 1) == p1_cp[j]->getXcoor() && temp2 - 1 == p1_cp[j]->getYcoor())
						{
							cout << "possible jump\n\n";
							possible_jump_coordinates[numberOfCheckersthatcanjump].Xcoor = (temp1 - 2);
							possible_jump_coordinates[numberOfCheckersthatcanjump].Ycoor = (temp2 + 2);
							numberOfCheckersthatcanjump++;
						}
					}

					if (p2_cp[i]->isKing())
					{
						cout << temp1 + 2 << ", " << temp2 + 2 << endl;
						if (temp1 + 2 < 8 && temp2 + 2 >= 0 )//if move will be in bounds--moving backwards right on board
						{
							if (!cb.isSquareOccupied(temp1 + 2, temp2 + 2))
							{
								cout << "NON OCCUPIED SQUARE\n";
								if ((temp1 + 1) == p1_cp[j]->getXcoor() && temp2 + 1 == p1_cp[j]->getYcoor())
								{
									cout << "possible jump\n\n";
									possible_jump_coordinates[numberOfCheckersthatcanjump].Xcoor = (temp1 + 2);
									possible_jump_coordinates[numberOfCheckersthatcanjump].Ycoor = (temp2 + 2);
									numberOfCheckersthatcanjump++;
								}
							}
							cout << temp1 - 2 << ", " << temp2 + 2 << endl;
							if (temp1 - 2 >= 0 && !cb.isSquareOccupied(temp1 - 2, temp2 + 2))//if move will be in bounds--moving backwards left
							{
								cout << "NON OCCUPIED SQUARE\n";
								if ((temp1 - 1) == p2_cp[j]->getXcoor() && temp2 + 1 == p2_cp[j]->getYcoor())
								{
									cout << "possible jump\n\n";
									possible_jump_coordinates[numberOfCheckersthatcanjump].Xcoor = (temp1 - 2);
									possible_jump_coordinates[numberOfCheckersthatcanjump].Ycoor = (temp2 + 2);
									numberOfCheckersthatcanjump++;
								}
							}


						}



					}
				}
			}

		}
	}
	return numberOfCheckersthatcanjump;
	}


	int Check_for_possible_jumps(CheckersBoard::BoardPieceCoordinates* possible_jump_coordinates, CheckerPiece* cp, CheckerPiece** cp_Arr, int number_of_player_checkerpieces)
	{
		int temp1, temp2, temp3, temp4, numberOfCheckersthatcanjump = 0;
		
			
				temp1 = cp->getXcoor(); temp2 = cp->getYcoor();

				for (int j = 0; j < number_of_player_checkerpieces; j++)
				{
					if (temp1 + 2 < 8 && temp2 + 2 < 8)//if move will be in bounds
					{
						if ((temp1 + 1) == cp_Arr[j]->getXcoor() && temp2 + 1 == cp_Arr[j]->getYcoor())
						{
							possible_jump_coordinates[numberOfCheckersthatcanjump].Xcoor = (temp1 + 2);
							possible_jump_coordinates[numberOfCheckersthatcanjump].Ycoor = (temp2 + 2);
							numberOfCheckersthatcanjump++;
						}
						if (temp1 - 2 >= 0)//if move will be in bounds
						{
							if ((temp1 - 1) == cp_Arr[j]->getXcoor() && temp2 + 1 == cp_Arr[j]->getYcoor())
							{
								possible_jump_coordinates[numberOfCheckersthatcanjump].Xcoor = (temp1 - 2);
								possible_jump_coordinates[numberOfCheckersthatcanjump].Ycoor = (temp2 + 2);
								numberOfCheckersthatcanjump++;
							}
						}

						if (cp->isKing())
						{
							if (temp1 + 2 < 8 && temp2 - 2 >= 0)//if move will be in bounds--moving backwards right on board
							{
								if ((temp1 + 1) == cp_Arr[j]->getXcoor() && temp2 + 1 == cp_Arr[j]->getYcoor())
								{
									possible_jump_coordinates[numberOfCheckersthatcanjump].Xcoor = (temp1 + 2);
									possible_jump_coordinates[numberOfCheckersthatcanjump].Ycoor = (temp2 - 2);
									numberOfCheckersthatcanjump++;
								}
								if (temp1 - 2 >= 0)//if move will be in bounds--moving backwards left
								{
									if ((temp1 - 1) == cp_Arr[j]->getXcoor() && temp2 + 1 == cp_Arr[j]->getYcoor())
									{
										possible_jump_coordinates[numberOfCheckersthatcanjump].Xcoor = (temp1 - 2);
										possible_jump_coordinates[numberOfCheckersthatcanjump].Ycoor = (temp2 - 2);
										numberOfCheckersthatcanjump++;
									}
								}


							}



						}
					}
				}

			
		

		
		return numberOfCheckersthatcanjump;
	}