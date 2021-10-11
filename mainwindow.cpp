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
    subjectModel = tableModel;

    ui->treeView_SystemFiles->setModel(fileSystem); // установим в представление модель обзора файловой системы
    ui->tableView_GroupFiles->setModel(tableModel); // установим в представление модель группировки файлов

    diagrams = new QChartView(); // создаем представление диаграммы, в которую поместим модель

    someChart = new BarChart(); // создаем модель столбцов

    observerChart = someChart; // присваеваем наблюдателю указатель на нашу модель

    subjectModel->Attach(observerChart); // добавляем наблюдателя к субъекту

    ui->splitter->addWidget(diagrams); // добавляем диаграмму в UI
}

MainWindow::~MainWindow()
{
    delete ui;
    delete fileSystem; // Указатель на модель обзора файловой системы
    delete tableModel; // Указатель на модель для правой таблицы
    delete diagrams;
    delete someChart;
    delete observerChart;
    delete subjectModel;

}


// Создали слот для обработки события двойного клика по дирректории
void MainWindow::on_treeView_SystemFiles_doubleClicked(const QModelIndex &index)
{
    QFileInfo fileInfo = fileSystem->fileInfo(index); // получаем полный путь
    QString s = fileInfo.absoluteFilePath(); // превращаем путь строку
    s.replace(R"(\)","/"); // заменяем все \ на / для того чтобы классы стратегий могли этот путь прочитать
    tableModel->setPath(s); // посылаем путь в экземпляр класса TableModel_GroupFiles

    subjectModel->Notify(); // при выборе директории уведомляем все модели диаграмм
    diagrams->setChart(someChart->getChart()); // установить обновленную модель в
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    tableModel->setGroupingStrat(index);

    subjectModel->Notify(); // при выборе директории уведомляем все модели диаграмм
    diagrams->setChart(someChart->getChart()); // установить обновленную модель в
}
