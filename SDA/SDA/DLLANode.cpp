#include "stdafx.h"
#include "DLLANode.h"

void testsNode()
{
	Artwork a{ "abc","sculpture",5000 };
	DLLANode n{ a };
	Artwork b{ "ccc","gg",543 };
	n.setInfo(b);
	assert(n.getInfo().getName() == "ccc");
	n.setNext(0);
	assert(n.getNext() == 0);
	n.setPrev(5);
	assert(n.getPrev() == 5);
}
