#pragma once
#include "Artwork.h"
#include <assert.h>

class DLLANode
{
private:
	Artwork info;
	int next;
	int prev;
public:
	//default constructor
	DLLANode()
	{
		info = Artwork{};
		next = -1;
		prev = -1;
	}
	//constructor or init
	//Input:Artowork i needed for information
	DLLANode(Artwork i) : info{i},next{-1},prev{-1}{}
	//destructor
	~DLLANode(){}
	//returns the information contained in a node = Artwork
	Artwork getInfo() { return info; }
	//returns the index of the element which follows the current one
	int getNext() { return next; }
	//returns the index of the element which follows the current one
	int getPrev() { return prev; }
	//sets the information contained in a node 
	void setInfo(Artwork a) { this->info = a; }
	//sets the index of the element which follows the current one
	void setNext(int x) { this->next = x; }
	//sets the index of the element which follows the current one
	void setPrev(int x) { this->prev = x; }
};

void testsNode();