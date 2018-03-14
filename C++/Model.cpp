#include "Model.h"
#include <QFont>
#include <QBrush>
#include <string>

TableModel::TableModel(PlayList& p) : playlist{ p }
{

}

TableModel::~TableModel()
{

}

int TableModel::rowCount(const QModelIndex & index) const
{
	return this->playlist.getSizePL();
}

int TableModel::columnCount(const QModelIndex & index) const
{
	return 4;
}

QVariant TableModel::data(const QModelIndex & index, int role) const
{
	int row = index.row();
	int col = index.column();

	std::vector<Tutorial> tutorials = this->playlist.getAll();

	if (row < 0 || row >= tutorials.size())
		return QVariant{};

	Tutorial currentTutorial = tutorials[row];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (col)
		{
		case 0:
			return QString::fromStdString(currentTutorial.getTitle());
		case 1:
			return QString::fromStdString(currentTutorial.getPresenter());
		case 2:
			return QString::fromStdString(std::to_string(currentTutorial.getDuration()->getMinutes()) + ":" + std::to_string(currentTutorial.getDuration()->getSeconds()));
		case 3:
			return QString::fromStdString(std::to_string(currentTutorial.getLikes()));
		}
	}

	if (role == Qt::FontRole)
	{
		QFont f{ "Times", 15, 10 };
		return f;
	}

	if (row % 2 == 0)
	{
		if (role == Qt::BackgroundRole)
		{
			QBrush brush{ QColor{ Qt::green } };
			return brush;
		}
	}

	return QVariant();
}

bool TableModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
	if (!index.isValid() || role != Qt::EditRole)
		return false;

	// set the new data to the gene
	int tutorialIndex = index.row();

	std::vector<Tutorial> tutorials = this->playlist.getAll();
	Tutorial currentTutorial = tutorials[tutorialIndex];
	switch (index.column())
	{
	case 0:
		currentTutorial.setTitle(value.toString().toStdString());
		break;
	case 1:
		currentTutorial.setPresenter(value.toString().toStdString());
		break;
	//case 2:
		//currentTutorial.setLikes(value.toString().toStdString());
	}
	//this->playlist.updateGene(geneIndex, currentGene);

	// emit the dataChanged signal
	emit dataChanged(index, index);

	return true;
}

Qt::ItemFlags TableModel::flags(const QModelIndex & index) const
{
	return Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable;
}