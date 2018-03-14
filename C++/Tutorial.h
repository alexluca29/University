#pragma once
#include <iostream>


class Duration
{
private:
	int minutes;
	int seconds;
public:
	Duration() : minutes(0), seconds(0) {}
	Duration(int min, int sec) : minutes(min), seconds(sec) {}

	int getMinutes() const { return minutes; }
	int getSeconds() const { return seconds; }
	void setMinutes(int min) { minutes = min; }
	void setSeconds(int sec) { seconds = sec; }
};

class Tutorial
{
private:
	std::string title;
	std::string presenter;
	Duration duration;
	int likes;
	std::string source;
	static int objCount;
	static int objCountTotal;
public:
	Tutorial();
	Tutorial(const std::string& title, const std::string& presenter, const Duration& duration, const int& likes, const std::string& source);
	//~Tutorial();

	static void incC() { objCount++; }
	static void incCT() { objCountTotal++; }
	static void decC() { objCount--; }
	std::string getTitle() const { return title; }
	std::string getPresenter() const { return presenter; }
	Duration* getDuration() { return &duration; }
	int getLikes() const { return likes; }
	std::string getSource() const { return source; }

	void setTitle(std::string title);
	void setPresenter(std::string presenter);
	void setLikes(int likes);
	void setSource(std::string source);
	std::string toString();

	void play();

	static int getObjCount() { return objCount; };
	static int getObjCountTotal() { return objCountTotal; };

	friend std::istream& operator >> (std::istream& is, Tutorial& t);
	friend std::ostream& operator<<(std::ostream& os, const Tutorial& t);
};


void testsTutorial();