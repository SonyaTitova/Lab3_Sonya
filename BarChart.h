#ifndef BARCHART_H
#define BARCHART_H

#include <QChartView>
#include <QStackedBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QStringList>
#include <QString>
#include <QRegExp>


#include "SampleChart.h"

using namespace QtCharts;

class BarChart : public SampleChart{ //класс столбчатой диаграммы

    public:

        BarChart();
        virtual ~BarChart();

        // реализация чисто виртуальной функции класса шаблон для создания диаграммы
        QChart* createChart() override;
};

#endif // BARCHART_H
