#ifndef TYPES_GROUPFILES_H
#define TYPES_GROUPFILES_H

#include <iostream>

#include <QString>
#include <QDir>
#include <QMap>
#include "Strat_GroupFiles.h"


class Types_GroupFiles : public Strat_GroupFiles
{
    public:

        Types_GroupFiles(QString path);
        ~Types_GroupFiles();

        virtual void groupFiles();
};

#endif // TYPES_GROUPFILES_H
