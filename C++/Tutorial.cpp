#include "Tutorial.h"
#include <Windows.h>
#include <shellapi.h>
#include <assert.h>
#include <string>
#include <fstream>
#include "Utils.h"

using namespace std;

int Tutorial::objCount = 0;
int Tutorial::objCountTotal = 0;

Tutorial::Tutorial() :title(""), presenter(""), duration(Duration()), likes(0), source("") {}

Tutorial::Tutorial(const std::string& title, const std::string& presenter, const Duration& duration, const int& likes, const std::string& source)
{
	this->title = title;
	this->presenter = presenter;
	this->duration = duration;
	this->likes = likes;
	this->source = source;
	//this->objCount++;
	//this->objCountTotal++;
}

//Tutorial::~Tutorial()
//{
//static int c1 = this->getObjCount();
//static int*p1 = &c1;
//*p1--;

//}

void Tutorial::setTitle(std::string title)
{
	this->title = title;
}

void Tutorial::setPresenter(std::string presenter)
{
	this->presenter = presenter;
}

void Tutorial::setLikes(int likes)
{
	this->likes = likes;
}

void Tutorial::setSource(std::string source)
{
	this->source = source;
}

void Tutorial::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getSource().c_str(), NULL, SW_SHOWMAXIMIZED);
}

std::string Tutorial::toString()
{
	Duration d = *this->getDuration();
	std::string str = getTitle() + " presented by " + getPresenter() + " length " + std::to_string(d.getMinutes()) + ":" + std::to_string(d.getSeconds()) + " no.of likes " + std::to_string(getLikes()) + " " + getSource();
	return str;
}

istream & operator >> (istream & is, Tutorial & t)
{
string line;
getline(is, line);

vector<string> tokens = tokenize(line, ',');
if (tokens.size() != 5) // make sure all the starship data was valid
return is;

t.title = tokens[0];
t.presenter = tokens[1];

// get duration
vector<string> durationTokens = tokenize(tokens[2], ':');
if (durationTokens.size() != 2)
return is;
t.duration = Duration{ stoi(durationTokens[0]), stoi(durationTokens[1]) };
t.likes = stoi(tokens[3]);
t.source = tokens[4];

return is;

}

ostream & operator<<(ostream & os, const Tutorial & t)
{
os << t.title << "," << t.presenter << "," << t.duration.getMinutes() << ":" << t.duration.getSeconds() << "," << t.getLikes() << "," << t.source << "\n";
return os;
}

//-----------------
void testSet()
{
Tutorial t{ "best","is",Duration{ 11,22 },10,"afsf" };
t.setLikes(1);
assert(t.getLikes() == 1);
t.setSource("abc");
assert(t.getSource() == "abc");
t.setPresenter("yo");
assert(t.getPresenter() == "yo");
t.setTitle("title");
assert(t.getTitle() == "title");
t.toString();
}

void testGetDuration()
{
Tutorial t{ "best","is",Duration{ 11,22 },10,"afsf" };
Duration *d1 = t.getDuration();
Duration d2{ 11,22 };
assert((*d1).getMinutes() == d2.getMinutes());


Duration d{ 11,22 };
assert(d.getMinutes() == 11);
assert(d.getSeconds() == 22);
}

void testCount()
{
int c1 = Tutorial::getObjCount();
int c2 = Tutorial::getObjCountTotal();
//assert(Tutorial::getObjCount() == 0);
//assert(Tutorial::getObjCountTotal() == 0);

}

void testsTutorial()
{
testSet();
testGetDuration();
testCount();
}
