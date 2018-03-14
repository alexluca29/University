#include "tableview.h"
#include "Model.h"

Tableview::Tableview(PlayList p,QWidget *parent)
	: QWidget(parent),playlist{p}
{
	tableui.setupUi(this);
	TableModel* m = new TableModel{ this->playlist };
	tableui.tableView->setModel(m);
}

Tableview::~Tableview()
{

}
