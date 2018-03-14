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
#include "ui_maingui.h"

class mainGUI : public QMainWindow
{
	Q_OBJECT
public:
	mainGUI(QWidget* parent = 0);
	~mainGUI();

	std::string filename;
	std::string type;

	Ui::MainGUI uim;
	void connectSigSlot();
	void setFilename();

public slots:
	void setTypeCSV();
	void setTypeHTML();

};