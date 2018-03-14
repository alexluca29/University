#pragma once
#include "Set.h"

class UI
{
private:
	Set s;
public:
	UI(Set setr) : s{setr}{}


	void printMenu();
	void run();

	void addUI();
	void removeUI();
	void display();
	void findUI();
};