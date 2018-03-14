#include "mainGUI.h"

mainGUI::mainGUI(QWidget *parent) :QMainWindow{ parent }
{
	uim.setupUi(this);
	this->type = "";
	this->filename = "";
	this->connectSigSlot();
}

mainGUI::~mainGUI()
{
}

void mainGUI::connectSigSlot()
{
	QObject::connect(uim.csvButton, &QPushButton::clicked, this, &mainGUI::setTypeCSV);
	QObject::connect(uim.htmlButton, &QPushButton::clicked, this, &mainGUI::setTypeHTML);

}

void mainGUI::setTypeCSV()
{
	this->type = "csv";
	this->setFilename();
}

void mainGUI::setTypeHTML()
{
	this->type = "html";
	this->setFilename();
}

void mainGUI::setFilename()
{
	this->filename = uim.nameLineEdit->text().toStdString();
}