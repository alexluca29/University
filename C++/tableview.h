#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QWidget>
#include "Playlist.h"
#include "ui_tableview.h"

class Tableview : public QWidget
{
	Q_OBJECT

public:
	Tableview(PlayList p,QWidget *parent = 0);
	~Tableview();

private:
	PlayList playlist;
	Ui::Form tableui;
};

#endif // TABLEVIEW_H
