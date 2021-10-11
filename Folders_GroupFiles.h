#ifndef FOLDERS_GROUPFILES_H
#define FOLDERS_GROUPFILES_H

#include <iostream>

#include <QString>
#include <QDir>
#include <QHash>
#include <QDebug>

#include "Strat_GroupFiles.h"

class Folders_GroupFiles : public Strat_GroupFiles{

    public:

        Folders_GroupFiles(QString path);
        ~Folders_GroupFiles();

        virtual void groupFiles();
};

#endif // FOLDERS_GROUPFILES_H
