#include "TableModel_GroupFiles.h"

TableModel_GroupFiles::TableModel_GroupFiles(QObject *parent) : QAbstractTableModel(parent)
{
    someStrat = nullptr;
    setGroupingStrat(0);
}

TableModel_GroupFiles::~TableModel_GroupFiles(){
    if(someStrat != nullptr){
        delete someStrat;
    }
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

    someStrat->setPath(path);
    helper_Strat helper(someStrat);

    listForTable = helper.getComfyMapping();

    endResetModel();
}

// вызывается в других местах программы, чтобы сменить стратегию группировки
void TableModel_GroupFiles::setGroupingStrat(int strat){

    QString path; // будет содержать актуальный путь при смене стратегии группировки

    beginResetModel();

    if(someStrat != nullptr) {
        path = someStrat->getPath(); // сохраняем путь перед удалением старой стратегии
        delete someStrat;
    }

    switch (strat) { // переключатель стратегий
        case Folders_Group:
            someStrat = new Folders_GroupFiles(path);
            break;
        case Types_Group:
            someStrat = new Types_GroupFiles(path);
            break;
    }

    helper_Strat helper(someStrat); // посылаем стратегию в класс-помощник

    listForTable = helper.getComfyMapping(); // получаем удобную для вставки в таблицу структуру данных

    endResetModel();
}

void TableModel_GroupFiles::Notify(){
    for (QList<IObserver_Charts *>::iterator i = listOfCharts.begin(); i != listOfCharts.end(); i++){
        (*i)->UpdateChart(listForTable); // вызывает у всех наблюдателей метод обновления
    }
}
