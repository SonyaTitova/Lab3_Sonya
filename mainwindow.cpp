#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BarChart.h"


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

    diagrams = new QChartView();

    ds = new BarChart();
    ds->set();

    QChart *ch = ds->getChart();

    diagrams->setChart(ch);

    ui->splitter->addWidget(diagrams);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete fileSystem;
    delete tableModel;
    delete diagrams;
    delete ds;
}


// Создали слот для обработки события двойного клика по дирректории
void MainWindow::on_treeView_SystemFiles_doubleClicked(const QModelIndex &index)
{
    QFileInfo fileInfo = fileSystem->fileInfo(index); // получаем полный путь
    QString s = fileInfo.absoluteFilePath(); // превращаем путь строку
    s.replace(R"(\)","/"); // заменяем все \ на / для того чтобы классы стратегий погли этот путь прочитать
    tableModel->setPath(s); // посылаем путь в экземпляр класса TableModel_GroupFiles
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    tableModel->setGroupingStrat(index);
}
