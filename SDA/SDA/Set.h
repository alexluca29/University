#pragma once
#include <iostream>
#include "DLLANode.h"
#define dim 50

class SetIterator;
class Set
{
private:
	friend class SetIterator;
	DLLANode nodes[dim];
	int cap;
	int head;
	int tail;
	int firstEmpty;
public:
	//constructor for a set
	Set()
	{
		this->cap = dim;
		this->head = -1;
		this->tail = 0;
		this->firstEmpty = 0;
	//	for (int i = 0; i < dim; i++)
		//{
			//nodes[i] = DLLANode{ Artwork{} };
		//}
	}
	~Set() {};
	//returns the doubly linked list
private:
	DLLANode* getList();

	//adds an artwork to an empty set
	//Input:a - artwork
	//Output:- ; the set is modified
	void addIfEmpty(Artwork a);
	//adds an artwork to a non-empty set
public:
	void add(Artwork a);
	//search for the first empty position in the dlla
	//the value of firstEmpty is modified
private:
	void searchFirstEmpty();
	//removes an element from the set
public:
	void remove(Artwork a);
	//checks if in element is in the set
	//Input:a - artwork
	//Output:true-if exists /false - otherwise
	bool find(Artwork a);
	//returns the number of elem in the set
	int getSize();
	//returns an iterator for the set
	SetIterator getIterator();
private:
	int getHead() { return head; }
	int getTail() { return tail; }
	
};


class SetIterator
{
private:
	friend class Set;
	DLLANode dlla[dim];
	int currentN;

public:
	SetIterator(Set s)
	{
		for (int i = 0; i < dim; i++)
			dlla[i] = s.getList()[i];
		currentN = s.getHead();
	}
	//returns the current element from the iterator
	Artwork getCurrent() { return dlla[currentN].getInfo(); }
	//checks if the iterator is at a valid position
	bool valid();
	//moves to the next element
	void next();
	int getCurrentIndex() { return currentN; }
};


void testAdd();
void testRemove();
void testFind();
void testsSet();

void testsIterator();