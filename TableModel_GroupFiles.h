#ifndef TABLEMODEL_GROUPFILES_H
#define TABLEMODEL_GROUPFILES_H

#include <QAbstractTableModel>
#include "Strat_GroupFiles.h"
#include "helper_Strat.h"
#include "Folders_GroupFiles.h"
#include "Types_GroupFiles.h"
#include "ISubject_Models.h"

// модель таблицы является объектом за которым наблюдают диаграммы
class TableModel_GroupFiles : public ISubject_Models, public QAbstractTableModel
{

    enum GroupingStrategy{ // перечисление стратегий
        Folders_Group,
        Types_Group
    };

    public:

        TableModel_GroupFiles(QObject *parent = nullptr);
        ~TableModel_GroupFiles();

        int rowCount(const QModelIndex &parent = QModelIndex()) const override; // отвечает за количество строк
        int columnCount(const QModelIndex &parent = QModelIndex()) const override; // отвечает за количество столбцов
        QVariant headerData(int section, Qt::Orientation orientation, int role) const; // Формирует заголовки
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override; // отвечает за данные в таблице


        void setPath(QString path); // вызывается в других местах программы, чтобы сменить путь
        void setGroupingStrat(int strat); // вызывается в других местах программы, чтобы сменить стратегию группировки

        virtual void Notify() override; // реализация метода уведомления для наблюдателей

    private:

        QVector<QStringList> listForTable; // удобный формат для того чтобы выводить в таблицу
        Strat_GroupFiles *someStrat; // указатель на актуальную стратегию
};

#endif // TABLEMODEL_GROUPFILES_H
