#pragma once
#include <qwidget.h>
#include "Tutorial.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox.h>
#include "Controller.h"
#include "RepositoryExceptions.h"
#include "ControllerExceptions.h"
#include "tableview.h"


class TutorialGUI : public QWidget
{
	Q_OBJECT
public:
	TutorialGUI(Controller& c, QWidget* parent = 0);
	~TutorialGUI();
private:
	Controller &ctrl;
	std::vector<Tutorial> tutorials;

	QLabel* allTutorials;

	QLineEdit* filter;

	QListWidget* tutorialsList;
	QLineEdit* titleEdit;
	QLineEdit* presenterEdit;
	QLineEdit* durationEdit;
	QLineEdit* likesEdit;
	QLineEdit* sourceEdit;
	QPushButton* addTutorialButton;
	QPushButton* deleteTutorialButton;
	QPushButton* updateTutorialButton;
	QPushButton* sortButton;
	QPushButton* undoButton;
	
	QPushButton* addToPLButton;

	QLabel* playL;
	QListWidget* playList;
	QPushButton* playButton;
	QPushButton* nextButton;
	QPushButton* rateButton;
	QPushButton* deletePLButton;
	QPushButton* saveButton;
	QPushButton* openButton;
	QPushButton* viewButton;

	void initGUI();
	void populateTutorialsList();
	void connectSignalsAndSlots();

	int getRepoListSelectedIndex();
	void moveTutorialToPlaylist();
	void populatePlaylist();
	int getPlaylistSelectedIndex();

	PlayList pl;
	Tableview v{ pl };
	Tableview* tvp = &v;

public slots:
	void filterT();

	void addNewTutorial();
	void deleteTutorial();
	void updateTutorial();
	void sortButtonHandler();
	void undoButtonHandler();

	void playTutorial();
	void nextTutorial();
	void rateTutorial();
	void deletePL();
	void save();
	void open();
	void viewButtonHandler();
	void populateView();
};