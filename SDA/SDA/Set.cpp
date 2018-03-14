#include "Set.h"
#include <assert.h>

using namespace std;

DLLANode* Set::getList()
{
	return nodes;
}

void Set::addIfEmpty(Artwork a)
{
	int newElem = firstEmpty;
	DLLANode n{ a };
	nodes[newElem] = n;
	firstEmpty++;
	this->head = newElem;
	this->tail = newElem;
}

void Set::add(Artwork a)
{
	if (find(a) == true)
		throw exception{ "Element already in the set" };
	if (getSize() == 0)
	{
		addIfEmpty(a);
		return;
	}
	DLLANode n{ a };
	/*int auxTail = tail;

	nodes[tail].setNext(firstEmpty);
	tail = firstEmpty;
	int newElem = firstEmpty;
	nodes[newElem] = n;
	searchFirstEmpty();
	nodes[newElem].setPrev(auxTail);
	nodes[newElem].setNext(-1);
	*/
	int auxHead = head;
	nodes[head].setPrev(firstEmpty);
	head = firstEmpty;
	int newElem = firstEmpty;
	nodes[newElem] = n;
	searchFirstEmpty();
	nodes[newElem].setNext(auxHead);
	nodes[newElem].setPrev(-1);
}

void Set::searchFirstEmpty()
{
	for (int i = 1; i < dim; i++)
	{
		if(nodes[i].getInfo().getName()=="" && nodes[i].getInfo().getType()=="")
		{
			this->firstEmpty = i;
			break;
		}
	}
}

void Set::remove(Artwork a)
{
	if (find(a) == false)
		throw exception{ "Element not in the set" };
	SetIterator it = getIterator();
	while(it.getCurrent() != a)
	{
		it.next();
	}
	int pos = it.getCurrentIndex();

	int previousPos = nodes[pos].getPrev();
	int nextPos = nodes[pos].getNext();

	if (pos == head && pos == tail)
	{
		head = -1;
		tail = -1;
	}
	else if (pos == head)
	{
		nodes[nextPos].setPrev(-1);
		head = nextPos;
	}
	else if (pos == tail)
	{
		nodes[previousPos].setNext(-1);
		tail = previousPos;
	}

	else {
		nodes[previousPos].setNext(nextPos);
		nodes[nextPos].setPrev(previousPos);
	}
	searchFirstEmpty();
}

bool Set::find(Artwork a)
{
	SetIterator it = getIterator();
	while (it.valid())
	{
		if(it.getCurrent() == a)
			return true;
		it.next();
	}
	return false;
}

int Set::getSize()
{
	int c=0;
	SetIterator it = getIterator();
	while (it.valid())
	{
		c++;
		it.next();
	}
	return c;
}


SetIterator Set::getIterator()
{
	SetIterator s{ *this };
	return s;
}

//---------------Iterator----------


bool SetIterator::valid()
{
	if (currentN == -1)
		return false;
	return true;
}

void SetIterator::next()
{
	int pos = currentN;
	currentN = dlla[pos].getNext();
}



//----------tests-------
/*
void testAdd()
{
	Set s{};
	Artwork a0{ "Sunlight","painting",5000 };
	Artwork a1{ "Human","sculpture",10000 };
	Artwork a2{ "London","painting",3000 };

	s.addIfEmpty(a0);
	assert(s.getSize() == 1);
	assert(s.getHead() == 0);
	s.add(a1);
	s.add(a2);
	assert(s.getList()[s.getTail()].getInfo() == a2);
	assert(s.getSize() == 3);
	try {
		s.add(a2);
	}
	catch (exception &e)
	{
	}
}


void testRemove()
{
	Set s{};
	Artwork a0{ "Sunlight","painting",5000 };
	Artwork a1{ "Human","sculpture",10000 };
	Artwork a2{ "London","painting",3000 };
	Artwork a3{ "London1","paintingr",3000 };

	s.addIfEmpty(a0);
	s.add(a1);
	s.add(a3);
	s.add(a2);

	s.remove(a3);
	assert(s.getSize() == 3);
	assert(s.find(a3) == false);
	s.remove(a2);
	assert(s.getSize() == 2);
	assert(s.getList()[s.getTail()].getInfo() == a1);
	s.remove(a0);
	assert(s.getSize() == 1);
	assert(s.getList()[s.getHead()].getInfo() == a1);
	s.remove(a1);
	assert(s.getSize() == 0);
	try
	{
		s.remove(a1);
	}
	catch(exception &e)
	{ }
}


void testFind()
{

	Set s{};
	Artwork a0{ "Sunlight","painting",5000 };
	Artwork a1{ "Human","sculpture",10000 };
	Artwork a2{ "London","painting",3000 };
	s.add(a0);
	s.add(a1);
	
	s.find(a2);
	assert(s.find(a2) == false);
	assert(s.find(a1) == true);
}

void testsSet()
{
	testAdd();
	testRemove();
	testFind();
}


void testsIterator()
{
	Set s{};
	Artwork a0{ "Sunlight","painting",5000 };
	Artwork a1{ "Human","sculpture",10000 };
	Artwork a2{ "London","painting",3000 };
	s.addIfEmpty(a0);
	s.add(a1);
	s.add(a2);

	SetIterator it{ s };
	assert(it.getCurrentIndex() == 0);
	assert(it.getCurrent() == a0);
	it.next();
	assert(it.getCurrentIndex() == 1);
	assert(it.getCurrent() == a1);
	it.next();
	assert(it.getCurrent() == a2);
	assert(it.valid() == true);
	it.next();
	assert(it.valid() == false);
}
*/