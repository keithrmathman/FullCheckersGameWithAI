#pragma once
#include <iostream>
#include <cstdlib>

class Node
{
public:

	Node* next;
	int Xcoor;
	int Ycoor;

};

class LinkedList
{


public:
	int length;
	Node* head;

	LinkedList();
	~LinkedList();
	void add(int Xcoor, int Ycoor);
	void print(int j);
};