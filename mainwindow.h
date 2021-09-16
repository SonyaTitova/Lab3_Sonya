#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QAbstractTableModel>
#include "TableModel_GroupFiles.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();


    private slots:
        // слот реагирующий на выбор дирректории
        void on_treeView_SystemFiles_doubleClicked(const QModelIndex &index);

    private:
        Ui::MainWindow *ui;

        QFileSystemModel *fileSystem; // Указатель на модель обзора файловой системы
        TableModel_GroupFiles *tableModel; // Указатель на модель для правой таблицы


};
#endif // MAINWINDOW_H
