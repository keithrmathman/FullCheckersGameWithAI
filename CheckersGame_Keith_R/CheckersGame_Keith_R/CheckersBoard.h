#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "string.h"
#include "CheckerPiece.h"
#include "../CheckersGame_Keith_R/linked_list.cpp"

class Node
{
public:
	friend class BoardPieceCoordinates;
	Node* next;
	BoardPieceCoordinates* data;
};

using namespace std;

class LinkedList
{
public:
	int length;
	Node* head;

	LinkedList();
	~LinkedList();
	void add(BoardPieceCoordinates* data);
	void print();
};

LinkedList::LinkedList() {
	this->length = 0;
	this->head = NULL;
}

LinkedList::~LinkedList() {
	std::cout << "LIST DELETED";
}

void LinkedList::add(BoardPieceCoordinates* data) {
	Node* node = new Node();
	node->data = data;
	node->next = this->head;
	this->head = node;
	this->length++;
}

void LinkedList::print() {
	Node* head = this->head;
	int i = 1;
	while (head) {
		std::cout << i << ": " << head->data << std::endl;
		head = head->next;
		i++;
	}
}



class CheckersBoard
{

public:
	CheckersBoard();
	~CheckersBoard();
	

	

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
	void setBoardCheckerPieceMoved(int Xcoor, int Ycoor);
	void CheckersBoard::clearCheckerPositions();
	void PrintAllCheckerPositions(); //print all checker pieces 
	void CheckersBoard::PlacePiecesOnBoard();//lists coordinates of squares that are playable to array 
	void printAllPlayableSquares(); //prints list of squares the checker pieces are allowed to land
	void DisplayAllPossibleMovesOnBoard(int PlayerNo, CheckerPiece cp);

private:
	 int numberOfPlayer1CheckerPieceCoordinatesMapped = 0, numberOfPlayer2CheckerPieceCoordinatesMapped = 0;
	 int numberOfPlayableSquaresOnCheckerBoard = 32;//number of playable squares on checker board
	 LinkedList checkForPossibleSquares(int xcoor, int ycoor);
	 
	 struct BoardPieceCoordinates
	{
		int Xcoor;
		int Ycoor;
	};

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

