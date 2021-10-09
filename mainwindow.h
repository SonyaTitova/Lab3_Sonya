#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QAbstractTableModel>
#include <QtCharts/QChartView>
#include "TableModel_GroupFiles.h"
#include "BarChart.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using namespace QtCharts;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:

        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:

        // слот реагирующий на выбор дирректории
        void on_treeView_SystemFiles_doubleClicked(const QModelIndex &index);

        void on_comboBox_currentIndexChanged(int index);

    private:

            Ui::MainWindow *ui;

            QFileSystemModel *fileSystem; // Указатель на модель обзора файловой системы
            TableModel_GroupFiles *tableModel; // Указатель на модель для правой таблицы
            QChartView *diagrams;
            BarChart *ds;

};
#endif // MAINWINDOW_H
