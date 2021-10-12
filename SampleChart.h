#ifndef SAMPLECHART_H
#define SAMPLECHART_H

#include <QChart>
#include <QString>

#include "IObserver_Charts.h"

using namespace QtCharts;

class SampleChart : public IObserver_Charts{ // класс шаблон для реализации обработки
                                               // алгоритмов отрисовки диаграмм, является наблюдателем
    public:

        SampleChart();
        virtual ~SampleChart();

        QChart* getChart(); // функция которая вызывает все функции шаблона

        // реализация чисто виртуальной функции обновления от класса наблюдатель
        virtual QChart* UpdateChart(QVector<QStringList> group) override;

        void clearQChart(); // очистка данных из QChart, для обновления

        virtual QChart* createChart() = 0; // формирования QChart, то есть модели диаграммы

    protected:

        QVector<QStringList> groupToQChart; // хранит в себе данные для диаграмм
        QChart *qChart;
};

#endif // SAMPLECHART_H
