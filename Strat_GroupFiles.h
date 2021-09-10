#ifndef STRAT_GROUPFILES_H
#define STRAT_GROUPFILES_H

#include <QString>
#include <QDebug>
#include <QHash>

class Strat_GroupFiles
{
    public:

        Strat_GroupFiles(QString path_);
        virtual ~Strat_GroupFiles();

        void setPath(QString path_);

        virtual void groupFiles() = 0;

    protected:

        QString path; // путь к дирректории
        int weight; // размер выбранного пути
        QHash<QString, int> group; // группировка в удобный контейнер
};

#endif // STRAT_GROUPFILES_H
