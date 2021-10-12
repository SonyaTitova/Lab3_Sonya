#include "SampleChart.h"

SampleChart::SampleChart()
{
    qChart = new QChart;
}

SampleChart::~SampleChart()
{
    delete qChart;
}

void SampleChart::clearQChart(){ // очистка данных из QChart, для обновления
    qChart->removeAllSeries();
}


QChart* SampleChart::getChart(){ // функция которая вызывает все функции шаблона
    this->clearQChart();
    this->createChart();
    return qChart;
}

QChart* SampleChart::UpdateChart(QVector<QStringList> group) { // реализация чисто виртуальной функции
    groupToQChart = group;                                      // обновления от класса наблюдатель
    return getChart();
}
