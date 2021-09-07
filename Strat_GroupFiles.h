#ifndef STRAT_GROUPFILES_H
#define STRAT_GROUPFILES_H

#include <QString>

class StratGroupFiles
{
    public:

        StratGroupFiles(QString path);
        virtual ~StratGroupFiles();

        void setPath(QString path_);

    protected:

        QString path;
};

#endif // STRAT_GROUPFILES_H
