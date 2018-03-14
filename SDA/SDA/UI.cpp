#include "UI.h"

using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "Available commands:" << endl;
	cout << "1.Add an artwork" << endl;
	cout << "2.Remove an artwork" << endl;
	cout << "3.Get the number of artworks in the musseum" << endl;
	cout << "4.Look for an artwork in the musseum" << endl;
	cout << "5.List all the artworks" << endl;
	cout << "0.Exit" << endl;
}

void UI::addUI()
{
	cout << "Give a name: " << endl;
	cin.ignore();
	std::string name;
	getline(cin,name);
	cout << "Give a type: " << endl;
	cin.ignore();
	std::string type;
	getline(cin, type);
	cout << "Give a price: " << endl;
	cin.ignore();
	std::string price;
	getline(cin, price);
	double p=0;
	try
	{
		p = stod(price);
	}
	catch(exception e)
	{
		cout << "Give a number for the price";
		return;
	}

	Artwork a{ name,type,p };
	try
	{
			s.add(a);
	}
	catch (exception &e)
	{
		cout << e.what();
		return;
	}
}

void UI::removeUI()
{
	cout << "Give a name: " << endl;
	cin.ignore();
	std::string name;
	getline(cin, name);

	Artwork a{ name,"",0 };
	try
	{
		s.remove(a);
	}
	catch(exception &e)
	{
		cout << e.what();
		return;
	}
}


void UI::display()
{
	SetIterator it{ s };
	while (it.valid())
	{
		cout << it.getCurrent().toString() << endl;
		it.next();
	}
}

void UI::findUI()
{
	cout << "Give a name: " << endl;
	std::string name;
	cin >> name;
	Artwork a{ name,"",0 };

	if (s.find(a) == true)
		cout << "The artwork exits" << endl;
	else
		cout << "The artwork does not exist" << endl;
}


void UI::run()
{
	while (true)
	{
		printMenu();
		int command;
		cout << "Your command: ";
		cin >> command;
		if (command == 0)
			break;
		switch (command)
		{
		case 1:
		{
			addUI();
			break;
		}
		case 2:
		{
			removeUI();
			break;

		}
		case 3:
		{
			cout << s.getSize() << endl;
			break;
		}
		case 4:
		{
			findUI();
			break;
		}
		case 5:
		{
			display();
			break;
		}
		}
	}
}
