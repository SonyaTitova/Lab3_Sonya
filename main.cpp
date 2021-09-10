#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

#include "Strat_GroupFiles.h"
#include "Types_GroupFiles.h"
#include "Folders_GroupFiles.h"

int main(int argc, char *argv[])
{

    Strat_GroupFiles *typeGroup = new Types_GroupFiles("ваш путь");
    Strat_GroupFiles *folderGroup = new Folders_GroupFiles("ваш путь");

    typeGroup->groupFiles();
    folderGroup->groupFiles();

    delete typeGroup;
    delete folderGroup;
    return 5;
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    */
}
