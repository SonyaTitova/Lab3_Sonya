#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

#include "Strat_GroupFiles.h"
#include "Types_GroupFiles.h"
#include "Folders_GroupFiles.h"
#include <QMetaObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
