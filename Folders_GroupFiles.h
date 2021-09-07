#ifndef FOLDERS_GROUPFILES_H
#define FOLDERS_GROUPFILES_H

#include <QString>
#include "Strat_GroupFiles.h"

class Folders_GroupFiles : public StratGroupFiles
{
    public:

        Folders_GroupFiles(QString path);
        ~Folders_GroupFiles();
};

#endif // FOLDERS_GROUPFILES_H
