#pragma once
#ifndef NODE
#define NODE
#include "..\CheckersGame_Keith_R\LinkedList.h"







LinkedList::LinkedList() {
	this->length = 0;
	this->head = NULL;
}

LinkedList::~LinkedList() {
	std::cout << "LIST DELETED";
}

void LinkedList::add(int Xcoor, int Ycoor) {
	Node* node = new Node();
	node->Xcoor = Xcoor;
	node->Ycoor = Ycoor;
	node->next = this->head;
	this->head = node;
	this->length++;
}

void LinkedList::print(int j) {
	Node* head = this->head;
	//int i = 1;


	while (head) {
		std::cout << "Checker Piece " << j << ": " << head->Xcoor << ", " << head->Ycoor << std::endl;
		head = head->next;
		//i++;
	}

}


#endif