#ifndef BARCHART_H
#define BARCHART_H

#include <QChartView>
#include <QStackedBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QStringList>


using namespace QtCharts;

class BarChart
{
    public:

        BarChart();

        QChart *qchart;
        QChartView *qcharview;

        QChart* getChart(){
            return qchart;
        }

        void set(){
            QStringList categories;
            QStackedBarSeries *series = new QStackedBarSeries(qchart);
            QBarSet *set = new QBarSet("Bar set " + QString::number(11));
            qreal f1 = 13;
            qreal f2 = 100;
            *set << f1;
            *set << f2;

            series->append(set);

            categories << "df" << "fdgg";
            qchart->addSeries(series);

            QBarCategoryAxis *axis = new QBarCategoryAxis();
            axis->append(categories);
            qchart->createDefaultAxes();
            qchart->setAxisX(axis, series);

        }
};

#endif // BARCHART_H
