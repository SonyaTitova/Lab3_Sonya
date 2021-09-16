#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

#include "Strat_GroupFiles.h"
#include "Types_GroupFiles.h"
#include "Folders_GroupFiles.h"
#include <QMetaObject>

int main(int argc, char *argv[])
{

    Strat_GroupFiles *typeGroup = new Types_GroupFiles("E:/Учеба 4 курс 1 семестр");
    Strat_GroupFiles *typeGroup2 = new Types_GroupFiles("E:/Учеба 4 курс 1 семестр");
    Strat_GroupFiles *folderGroup = new Folders_GroupFiles("ваш путь");

    //typeGroup->groupFiles();
    folderGroup->groupFiles();

    helper_Strat d(typeGroup);
    QVector<QStringList> comfy = d.getComfyMapping();

    helper_Strat d2(typeGroup2);
    QVector<QStringList> comfy2 = d2.getComfyMapping();

    delete typeGroup;
    delete folderGroup;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
