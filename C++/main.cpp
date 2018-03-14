#include "lab11.h"
#include <QtWidgets/QApplication>
#include "TutorialGUI.h"
#include "CSVPlaylist.h"
#include "HTMLPlaylist.h"
#include "mainGUI.h"
#include "watchlist.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//Lab11 w;
	//w.show();
	/*
	Tutorial t1{ "install","ion",Duration{ 5,20 },20,"https://www.youtube.com/watch?v=tvC1WCdV1XU&list=PLAE85DE8440AA6B83" };
	Tutorial t2{ "understanding","vasile",Duration{ 4,20 },30,"https://www.youtube.com/watch?v=SWZfFNyUsxc&index=2&list=PLAE85DE8440AA6B83" };
	Tutorial t3{ "print","george",Duration{ 3,10 },20,"https://www.youtube.com/watch?v=sPv0HQ8xOaU&index=3&list=PLAE85DE8440AA6B83" };
	Tutorial t4{ "variables","ion",Duration{ 10,2 },100,"https://www.youtube.com/watch?v=QwBSv4-_Lmk&list=PLAE85DE8440AA6B83&index=4" };
	Tutorial t5{ "calculator","steve",Duration{ 5,0 },1000,"https://www.youtube.com/watch?v=yjucJUsHSqg&list=PLAE85DE8440AA6B83&index=5" };
	Tutorial t6{ "variables","john",Duration{ 8,45 },500,"https://www.youtube.com/watch?v=3Iq_uFbc4L4&index=6&list=PLAE85DE8440AA6B83" };
	Tutorial t7{ "if","ion",Duration{ 2,11 },1,"https://www.youtube.com/watch?v=3Iq_uFbc4L4&index=6&list=PLAE85DE8440AA6B83" };
	Tutorial t8{ "functions","john",Duration{ 3,20 },40,"https://www.youtube.com/watch?v=bsWWHo4KDHE&index=9&list=PLAE85DE8440AA6B83" };
	Tutorial t9{ "classes","ion",Duration{ 11,35 },2140,"https://www.youtube.com/watch?v=ABRP_5RYhqU&list=PLAE85DE8440AA6B83&index=12" };
	Tutorial t10{ "constructors","john",Duration{ 6,22 },300,"https://www.youtube.com/watch?v=_b7odUc7lg0&index=14&list=PLAE85DE8440AA6B83" };

	std::vector<Tutorial> tutorialz;
	tutorialz.push_back(t1);
	tutorialz.push_back(t2);
	tutorialz.push_back(t3);
	tutorialz.push_back(t4);
	tutorialz.push_back(t5);
	tutorialz.push_back(t6);
	tutorialz.push_back(t7);
	tutorialz.push_back(t8);
	tutorialz.push_back(t9);
	tutorialz.push_back(t10);
	*/
	/*
	mainGUI m{};
	m.show();
	std::string ty="";
	//while (ty == "")
		//ty = m.type;
	std::string f = m.filename;
	*/
	//m.hide();
	Repository r{ "Tutorials.txt" };

	FilePlaylist* p = new HTMLPlaylist{};
	/*
	if (ty == "csv")
	{
		FilePlaylist* playlist = new CSVPlaylist{};
		CSVPlaylist* p = static_cast<CSVPlaylist*>(playlist);
	}
	else {
		FilePlaylist* playlist = new HTMLPlaylist{};
		HTMLPlaylist* p = static_cast<HTMLPlaylist*>(playlist);
	}*/
	Controller c{ r ,p,TutorialValidator{} };
	//c.getFilePL()->setFile(f);
	TutorialGUI t{c};
	t.show();
	return a.exec();
}
