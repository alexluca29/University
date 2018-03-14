#include "TutorialGUI.h"
#include <QDebug.h>
#include <string>
#include "Utils.h"
#include "tableview.h"

TutorialGUI::TutorialGUI(Controller& _ctr, QWidget *parent):QWidget{parent}, ctrl{_ctr}
{
	this->initGUI();
	this->tutorials = this->ctrl.getTutorials();
	this->populateTutorialsList();
	this->pl = *(this->ctrl.getPlayL());
}

TutorialGUI::~TutorialGUI()
{
}

void TutorialGUI::initGUI()
{
	QFont f{ "Verdana", 15 };

	//general layout
	QHBoxLayout* layout = new QHBoxLayout{ this };

	//left side
	QWidget* leftSide = new QWidget{};
	QVBoxLayout* admin = new QVBoxLayout{ leftSide };

	//QWidget* filterWidget = new QWidget{};
	this->filter = new QLineEdit{};


	QLabel* all = new QLabel{ "All tutorials: " };
	this->allTutorials = all;
	this->allTutorials->setFont(f);
	admin->addWidget(this->allTutorials);
	
	this->tutorialsList = new QListWidget{};
	this->tutorialsList->setSelectionMode(QAbstractItemView::SingleSelection);
	admin->addWidget(this->tutorialsList);
	
	//tutorial information
	QWidget* tutorialDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ tutorialDataWidget };
	this->titleEdit = new QLineEdit{};
	this->presenterEdit = new QLineEdit{};
	this->durationEdit = new QLineEdit{};
	this->likesEdit = new QLineEdit{};
	this->sourceEdit = new QLineEdit{};
	QLabel* titleLabel = new QLabel{ "&Title:" };
	titleLabel->setBuddy(this->titleEdit);
	QLabel* presenterLabel = new QLabel{ "&Presenter: " };
	presenterLabel->setBuddy(this->presenterEdit);
	QLabel* durationLabel = new QLabel{ "&Duration:" };
	durationLabel->setBuddy(this->durationEdit);
	QLabel* likesLabel = new QLabel{ "&Likes: " };
	likesLabel->setBuddy(this->likesEdit);
	QLabel* sourceLabel = new QLabel{ "&Souce: " };
	sourceLabel->setBuddy(this->sourceEdit);

	titleLabel->setFont(f);
	presenterLabel->setFont(f);
	durationLabel->setFont(f);
	likesLabel->setFont(f);
	sourceLabel->setFont(f);
	this->titleEdit->setFont(f);
	this->presenterEdit->setFont(f);
	this->durationEdit->setFont(f);
	this->likesEdit->setFont(f);
	this->sourceEdit->setFont(f);

	formLayout->addRow(titleLabel, this->titleEdit);
	formLayout->addRow(presenterLabel, this->presenterEdit);
	formLayout->addRow(durationLabel, this->durationEdit);
	formLayout->addRow(likesLabel, this->likesEdit);
	formLayout->addRow(sourceLabel, this->sourceEdit);

	admin->addWidget(tutorialDataWidget);

	QWidget* buttonsWidget = new QWidget{};
	QHBoxLayout* hLayout = new QHBoxLayout{ buttonsWidget };
	this->addTutorialButton = new QPushButton("Add Tutorial");
	this->addTutorialButton->setFont(f);
	this->deleteTutorialButton = new QPushButton("Delete Tutorial");
	this->deleteTutorialButton->setFont(f);
	this->updateTutorialButton = new QPushButton("Update Tutorial");
	this->updateTutorialButton->setFont(f);
	this->sortButton = new QPushButton("Sort by likes");
	this->sortButton->setFont(f);
	hLayout->addWidget(this->addTutorialButton);
	hLayout->addWidget(this->deleteTutorialButton);
	hLayout->addWidget(this->updateTutorialButton);

	QWidget* sortWidget = new QWidget{};
	QHBoxLayout* hl = new QHBoxLayout{ sortWidget };
	hl->addWidget(this->sortButton);
	this->undoButton = new QPushButton("Undo");
	this->undoButton->setFont(f);
	hl->addWidget(this->undoButton);

	admin->addWidget(buttonsWidget);
	admin->addWidget(sortWidget);
	admin->addWidget(this->filter);

	//middle
	QWidget* middle = new QWidget{};
	QHBoxLayout* ml = new QHBoxLayout{ middle };
	this->addToPLButton = new QPushButton(">");
	this->addToPLButton->setFont(f);
	ml->addWidget(this->addToPLButton);

	//right side
	QWidget* rightSide = new QWidget{};
	QVBoxLayout* user = new QVBoxLayout{ rightSide };

	QLabel* plm = new QLabel{ "Playlist:" };
	this->playL = plm;
	this->playL->setFont(f);
	user->addWidget(this->playL);

	this->playList = new QListWidget{};
	this->playList->setSelectionMode(QAbstractItemView::SingleSelection);
	user->addWidget(this->playList);

	QWidget* buttonsPLWidget = new QWidget{};
	QHBoxLayout* hPLLayout = new QHBoxLayout{ buttonsPLWidget };

	this->playButton = new QPushButton("Play");
	this->playButton->setFont(f);
	this->nextButton = new QPushButton("Next");
	this->nextButton->setFont(f);
	this->rateButton = new QPushButton("Rate");
	this->rateButton->setFont(f);
	this->deletePLButton = new QPushButton("Delete");
	this->deletePLButton->setFont(f);

	hPLLayout->addWidget(this->playButton);
	hPLLayout->addWidget(this->nextButton);
	hPLLayout->addWidget(this->deletePLButton);
	hPLLayout->addWidget(this->rateButton);

	QWidget* buttonsPLWidget2 = new QWidget{};
	QHBoxLayout* hPLLayout2 = new QHBoxLayout{buttonsPLWidget2};
	this->saveButton = new QPushButton("Save");
	this->saveButton->setFont(f);
	this->openButton = new QPushButton("Open");
	this->openButton->setFont(f);
	this->viewButton = new QPushButton("View list");
	this->viewButton->setFont(f);
	hPLLayout2->addWidget(this->saveButton);
	hPLLayout2->addWidget(this->openButton);
	hPLLayout2->addWidget(this->viewButton);


	user->addWidget(buttonsPLWidget);
	user->addWidget(buttonsPLWidget2);

	//join
	layout->addWidget(leftSide);
	layout->addWidget(middle);
	layout->addWidget(rightSide);

	this->connectSignalsAndSlots();
}

void TutorialGUI::populateTutorialsList()
{
	// clear the list, if there are elements in it
	if (this->tutorialsList->count() > 0)
		this->tutorialsList->clear();

	for (auto t : this->tutorials)
	{
		Duration d = *t.getDuration();
		QString itemInList = QString::fromStdString(t.getTitle() + " presented by " + t.getPresenter() + std::to_string(d.getMinutes()) + ":" + std::to_string(d.getSeconds()) + " no.of likes " + std::to_string(t.getLikes()) );
		QFont f{ "Verdana", 15 };
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		item->setFont(f);
		this->tutorialsList->addItem(item);
	}

	// set the selection on the first item in the list
	if (this->tutorials.size() > 0)
		this->tutorialsList->setCurrentRow(0);
}

void TutorialGUI::connectSignalsAndSlots()
{
	//QObject::connect(this->filter,SIGNAL(textChanger(),this,SLOT(filterTutorialsSignal())));
	QObject::connect(this->filter, &QLineEdit::textChanged, this, &TutorialGUI::filterT);
	QObject::connect(this->addTutorialButton, &QAbstractButton::clicked, this, &TutorialGUI::addNewTutorial);
	//QObject::connect(this->addTutorialButton, SIGNAL(clicked()), this, SLOT(addNewTutorial()));
	QObject::connect(this->deleteTutorialButton, &QAbstractButton::clicked, this, &TutorialGUI::deleteTutorial);
	QObject::connect(this->updateTutorialButton, &QAbstractButton::clicked, this, &TutorialGUI::updateTutorial);
	QObject::connect(this->sortButton, &QAbstractButton::clicked, this, &TutorialGUI::sortButtonHandler);
	QObject::connect(this->addToPLButton, &QAbstractButton::clicked, this, &TutorialGUI::moveTutorialToPlaylist);

	QObject::connect(this->playButton, &QAbstractButton::clicked, this, &TutorialGUI::playTutorial);
	QObject::connect(this->nextButton, &QAbstractButton::clicked, this, &TutorialGUI::nextTutorial);
	QObject::connect(this->rateButton, &QAbstractButton::clicked, this, &TutorialGUI::rateTutorial);
	QObject::connect(this->deletePLButton, &QAbstractButton::clicked, this, &TutorialGUI::deletePL);
	QObject::connect(this->saveButton, &QAbstractButton::clicked, this, &TutorialGUI::save);
	QObject::connect(this->openButton, &QAbstractButton::clicked, this, &TutorialGUI::open);
	QObject::connect(this->undoButton, &QAbstractButton::clicked, this, &TutorialGUI::undoButtonHandler);
	QObject::connect(this->viewButton, &QAbstractButton::clicked, this, &TutorialGUI::viewButtonHandler);

}

void TutorialGUI::filterT()
{
	std::string str = this->filter->text().toStdString();

	if (str == "")
	{
		this->tutorials = this->ctrl.getTutorials();
		this->populateTutorialsList();
		return;
	}
	std::vector<Tutorial> v = this->tutorials;
	std::vector<Tutorial> aux;
	for (int i = 0; i < this->tutorials.size()-1; i++)
	{
			if (strstr(v[i].toString().c_str(), str.c_str()))
				aux.push_back(v[i]);
	}

	this->tutorials = aux;
	this->populateTutorialsList();

}

void TutorialGUI::addNewTutorial()
{
	std::string title = this->titleEdit->text().toStdString();
	std::string presenter = this->presenterEdit->text().toStdString();
	std::string duration = this->durationEdit->text().toStdString();
	// get minutes and seconds
	
	std::vector<std::string> durationTokens = tokenize(duration, ':');
	if (durationTokens.size() != 2)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "The duration must have minutes and seconds, separated by \":\"!");
		return;
	}

	std::string likesSTD = this->likesEdit->text().toStdString();
	int likes = stoi(likesSTD);
	std::string source = this->sourceEdit->text().toStdString();

	try
	{
		this->ctrl.addTutorialCtrl(title, presenter, stoi(durationTokens[0]), stoi(durationTokens[1]), likes,source);
		// refresh the list
		this->tutorials = this->ctrl.getTutorials();
		this->populateTutorialsList();
	}
	catch (TutorialExceptions& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getErrorsAsString()));
	}
	catch (DuplicateTutorialException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
	
}

void TutorialGUI::deleteTutorial()
{
	std::string  title = this->titleEdit->text().toStdString();
	std::string presenter = this->presenterEdit->text().toStdString();

	try
	{
		this -> ctrl.deleteTutorialCtrl(title, presenter);
		this->tutorials = this->ctrl.getTutorials();
		this->populateTutorialsList();
	}
	catch (LackTutorialException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void TutorialGUI::updateTutorial()
{
	std::string title = this->titleEdit->text().toStdString();
	std::string presenter = this->presenterEdit->text().toStdString();
	std::string duration = this->durationEdit->text().toStdString();
	// get minutes and seconds

	std::vector<std::string> durationTokens = tokenize(duration, ':');
	if (durationTokens.size() != 2)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "The duration must have minutes and seconds, separated by \":\"!");
		return;
	}

	std::string likesSTD = this->likesEdit->text().toStdString();
	int likes = stoi(likesSTD);
	std::string source = this->sourceEdit->text().toStdString();
	try
	{
		this->ctrl.updateTutorialCtrl(title, presenter, stoi(durationTokens[0]), stoi(durationTokens[1]), likes, source);
		// refresh the list
		this->tutorials = this->ctrl.getTutorials();
		this->populateTutorialsList();
	}
	catch (TutorialExceptions& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getErrorsAsString()));
	}
	catch (LackTutorialException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void TutorialGUI::sortButtonHandler()
{
	this->tutorials = this->ctrl.sortByLikesCtrl();
	this->populateTutorialsList();
}

//===================================playlist much

int TutorialGUI::getRepoListSelectedIndex()
{
	if (this->tutorialsList->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = this->tutorialsList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->titleEdit->clear();
		this->presenterEdit->clear();
		this->durationEdit->clear();
		this->likesEdit->clear();
		this->sourceEdit->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void TutorialGUI::populatePlaylist()
{
	
		// clear the list, if there are elements in it
		if (this->playList->count() > 0)
			this->playList->clear();

		for (auto t : this->ctrl.getPL())
		{
			Duration d = *t.getDuration();
			QString itemInList = QString::fromStdString(t.getTitle() + " presented by " + t.getPresenter() + std::to_string(d.getMinutes()) + ":" + std::to_string(d.getSeconds()) + " no.of likes " + std::to_string(t.getLikes()));
			QFont f{ "Verdana", 15 };
			QListWidgetItem* item = new QListWidgetItem{ itemInList };
			item->setFont(f);
			this->playList->addItem(item);
		}

	
}

void TutorialGUI::moveTutorialToPlaylist()
{
	int idx = this->getRepoListSelectedIndex();
	if (idx == -1 || idx >= this->tutorials.size())
		return;

	const Tutorial& t = this->tutorials[idx];
	this->ctrl.addToPlayListCtrl(t);
	this->populatePlaylist();
	this->pl.add(t);
	this->populateView();
}

int TutorialGUI::getPlaylistSelectedIndex()
{
	if (this->playList->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = this->playList->selectionModel()->selectedIndexes();

	int idx = index.at(0).row();
	return idx;
}

void TutorialGUI::playTutorial()
{
	this->ctrl.getPlayL()->play();
}

void TutorialGUI::nextTutorial()
{
	this->ctrl.getPlayL()->next();
}

void TutorialGUI::rateTutorial()
{
	//this->ctrl.rate();
}

void TutorialGUI::deletePL()
{
	this->ctrl.deleteFromPlayListCtrl(this->getPlaylistSelectedIndex());
	this->populatePlaylist();
}

void TutorialGUI::save()
{
	this->ctrl.getFilePL()->setFile("HTML.html");
	this->ctrl.saveToFile();
}

void TutorialGUI::open()
{
	this->ctrl.openFile();
}

void TutorialGUI::undoButtonHandler()
{
	try
	{
		this->ctrl.undo();
	}
	catch (int i)
	{
		QMessageBox msg;
		msg.critical(0,"Error","Undo list empty");
	}
	this->tutorials = this->ctrl.getTutorials();
	this->populateTutorialsList();
}

void TutorialGUI::viewButtonHandler()
{
	tvp->show();
}

void TutorialGUI::populateView()
{
	Tableview*p  = new Tableview{ pl };
	tvp = p;
}