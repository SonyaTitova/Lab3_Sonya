#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    fileSystem = new QFileSystemModel; // Создадим модель обзора файловой системы
    fileSystem->setFilter(QDir::NoDotAndDotDot | QDir::QDir::AllEntries); // установим фильтры на эту модель
    fileSystem->setRootPath(""); // установим начальный путь, он же самый верхний

    tableModel = new TableModel_GroupFiles; // инициализоровали модель для правой таблицы

    ui->treeView_SystemFiles->setModel(fileSystem); // установим в представление модель обзора файловой системы
    ui->tableView_GroupFiles->setModel(tableModel); // установим в представление модель группировки файлов

}

MainWindow::~MainWindow()
{
    delete ui;
}


// Создали слот для обработки события двойного клика по дирректории
void MainWindow::on_treeView_SystemFiles_doubleClicked(const QModelIndex &index)
{
    QFileInfo fileInfo = fileSystem->fileInfo(index); // получаем полный путь
    QString s = fileInfo.absoluteFilePath(); // превращаем путь строку
    s.replace(R"(\)","/"); // заменяем все \ на / для того чтобы классы стратегий погли этот путь прочитать
    tableModel->setPath(s); // посылаем путь в экземпляр класса TableModel_GroupFiles
}



