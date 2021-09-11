#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QFileSystemModel *fileSystem = new QFileSystemModel; // Создадим модель обзора файловой системы
    fileSystem->setFilter(QDir::NoDotAndDotDot | QDir::QDir::AllEntries); // установим фильтры на эту модель
    fileSystem->setRootPath(""); // установим начальный путь, он же самый верхний

    QAbstractTableModel *tableModel = new TableModel_GroupFiles; // инициализоровали модель для правой таблицы

    ui->treeView_SystemFiles->setModel(fileSystem); // установим в представление модель обзора файловой системы
    ui->tableView_GroupFiles->setModel(tableModel); // установим в представление модель группировки файлов
}

MainWindow::~MainWindow()
{
    delete ui;
}

