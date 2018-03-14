// SDA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Set.h"
#include "UI.h"
#include "DLLANode.h"

int main()
{

	//testsNode();
	//testsArtwork();
	//testsSet();
	//testsIterator();

	Set s{};

	Artwork a0{ "Sunlight","painting",5000 };
	Artwork a1{ "Human","sculpture",10000 };
	Artwork a2{ "London","drawing",3000 };
	
	s.add(a0);
	s.add(a1);
	s.add(a2);
	
	UI ui{ s };

	ui.run();

	system("pause");
    return 0;
}

