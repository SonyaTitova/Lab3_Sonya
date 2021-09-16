#ifndef TABLEMODEL_GROUPFILES_H
#define TABLEMODEL_GROUPFILES_H

#include <QAbstractTableModel>
#include "Strat_GroupFiles.h"
#include "helper_Strat.h"
#include "Folders_GroupFiles.h"
#include "Types_GroupFiles.h"

class TableModel_GroupFiles : public QAbstractTableModel
{
    public:

        TableModel_GroupFiles(QObject *parent = nullptr);
        int rowCount(const QModelIndex &parent = QModelIndex()) const override; // отвечает за количество строк
        int columnCount(const QModelIndex &parent = QModelIndex()) const override; // отвечает за количество столбцов
        QVariant headerData(int section, Qt::Orientation orientation, int role) const; // Формирует заголовки
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override; // отвечает за данные в таблице


        void setPath(QString path); // вызывается в других местах программы, чтобы сменить путь

    private:

        QVector<QStringList> listForTable; // удобный формат для того чтобы выводить в таблицу
};

#endif // TABLEMODEL_GROUPFILES_H
