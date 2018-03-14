#pragma once
#include <qabstractitemmodel.h>
#include "Playlist.h"

class TableModel : public QAbstractTableModel
{
private:
	PlayList &playlist;
public:
	TableModel(PlayList& p);
	~TableModel();
	
	// number of rows
	int rowCount(const QModelIndex &parent = QModelIndex{}) const override;

	// number of columns
	int columnCount(const QModelIndex &parent = QModelIndex{}) const override;

	// Value at a given position
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;


	// will be called when a cell is edited
	bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) override;

	// used to set certain properties of a cell (to be able to edit)
	Qt::ItemFlags flags(const QModelIndex & index) const override;
};