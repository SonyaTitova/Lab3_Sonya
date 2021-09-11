#include "TableModel_GroupFiles.h"

TableModel_GroupFiles::TableModel_GroupFiles(QObject *parent) : QAbstractTableModel(parent)
{

}

int TableModel_GroupFiles::rowCount(const QModelIndex &parent) const{ // отвечает за количество строк
    return 10;
}

int TableModel_GroupFiles::columnCount(const QModelIndex &parent) const { // отвечает за количество столбцов
    return 3;
}

QVariant TableModel_GroupFiles::data(const QModelIndex &index, int role) const { // отвечает за данные в таблице
    // ради проверки работы вот такой вот простенький алгоритм заполнения с сайта Qt

    if (role == Qt::DisplayRole)
       return QString("Row%1, Column%2")
                   .arg(index.row() + 1)
                   .arg(index.column() +1);

    return QVariant();
}
