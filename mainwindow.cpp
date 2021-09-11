#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QFileSystemModel *model = new QFileSystemModel; // Создадим модель обзора файловой системы

    model->setFilter(QDir::NoDotAndDotDot | QDir::QDir::AllEntries); // установим фильтры на эту модель
    model->setRootPath(""); // установим начальный путь, он же самый верхний

    ui->treeView_SystemFiles->setModel(model); // установим в представление модель обзора файловой системы

}

MainWindow::~MainWindow()
{
    delete ui;
}

