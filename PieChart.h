#ifndef PIECHART_H
#define PIECHART_H

#include <QRegExp>
#include <QPieSeries>
#include <QPieSlice>
#include <QString>

#include "SampleChart.h"

using namespace QtCharts;

class PieChart : public SampleChart //класс круговой диаграммы, реализует шаблон SampleChart
{
    public:

        PieChart();
        virtual ~PieChart();

        // реализация чисто виртуальной функции класса шаблон для создания диаграммы
        QChart* createChart() override;
};

#endif // PIECHART_H
