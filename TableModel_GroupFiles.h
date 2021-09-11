#ifndef TABLEMODEL_GROUPFILES_H
#define TABLEMODEL_GROUPFILES_H

#include <QAbstractTableModel>

class TableModel_GroupFiles : public QAbstractTableModel
{
    public:

        TableModel_GroupFiles(QObject *parent = nullptr);

        int rowCount(const QModelIndex &parent = QModelIndex()) const override; // отвечает за количество строк
        int columnCount(const QModelIndex &parent = QModelIndex()) const override; // отвечает за количество столбцов
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override; // отвечает за данные в таблице
};

#endif // TABLEMODEL_GROUPFILES_H
