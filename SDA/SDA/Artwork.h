#pragma once
#include <string>
class Artwork 
{
private:
	std::string name;
	std::string type;
	double price;
public:
	//default constructor
	Artwork()
	{
		name = "";
		type = "";
		price = 0;
	}
	//constructor for the class Artwork
	Artwork(std::string n,std::string t,double p) : name{n},type{t},price{p}{}
	//destructor ; every field is static so there is no need for deallocation
	~Artwork(){}
	//return the name of the artwork
	std::string getName() {return name;}
	//return the type of the artwork
	std::string getType() { return type; }
	//return the price of the artwork
	double getPrice() { return price; }
	//returns a string having the data of an artwork
	std::string toString()
	{
		return "Name:" + getName() + " " + "Type:" + getType() + " " + "Price:" + std::to_string(getPrice());
	}

	bool operator==(Artwork& p)
	{
		if (this->getName() == p.getName())
			return true;
		else
			return false;
	}

	bool operator!=(Artwork& p)
	{
		if (this->getName() == p.getName())
			return false;
		else
			return true;
	}

};

void testsArtwork();