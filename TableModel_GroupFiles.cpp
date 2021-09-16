#include "TableModel_GroupFiles.h"

TableModel_GroupFiles::TableModel_GroupFiles(QObject *parent) : QAbstractTableModel(parent)
{

}

int TableModel_GroupFiles::rowCount(const QModelIndex &parent) const{ // отвечает за количество строк
    int i = listForTable.length();
    return i;
}

int TableModel_GroupFiles::columnCount(const QModelIndex &parent) const { // отвечает за количество столбцов
    int i = 0;
    if(listForTable.empty()){}
    else i = listForTable.at(0).length();
    return i;
}

// формирует заголовки
QVariant TableModel_GroupFiles::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return tr("Имя");

            case 1:
                return tr("Размер");

            case 2:
                return tr("Процент");

            default:
                return QVariant();
        }
    }
    return QVariant();
}


QVariant TableModel_GroupFiles::data(const QModelIndex &index, int role) const { // отвечает за данные в таблице

    if (role == Qt::DisplayRole)

       return QString(listForTable[index.row()][index.column()]);

    return QVariant();
}


// вызывается в других местах программы, чтобы сменить путь
void TableModel_GroupFiles::setPath(QString path){

    beginResetModel();

    Strat_GroupFiles *someStrat = new Types_GroupFiles(path);
    helper_Strat helper(someStrat);

    listForTable = helper.getComfyMapping();

    delete someStrat;

    endResetModel();
}

