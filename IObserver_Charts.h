#ifndef IOBSERVER_CHARTS_H
#define IOBSERVER_CHARTS_H

#include <QVector>
#include <QStringList>
#include <QChart>

using namespace QtCharts;

class IObserver_Charts{ // класс шаблона "наблюдатель", интерфейс для наблюдателей

    public:

        IObserver_Charts();
        virtual ~IObserver_Charts();

        // функция реакции на уведомление от ISubject_Models
        virtual QChart* UpdateChart(QVector<QStringList> group) = 0;
};

#endif // IOBSERVER_CHARTS_H
