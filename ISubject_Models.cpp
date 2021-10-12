#include "ISubject_Models.h"

ISubject_Models::ISubject_Models()
{

}

ISubject_Models::~ISubject_Models()
{

}

void ISubject_Models::Attach(IObserver_Charts *observer_chart){ // добавить в список нового наблюдателя
    listOfCharts.append(observer_chart);
}

void ISubject_Models::Detach(IObserver_Charts *observer_chart){ // удалить наблюдателя из списка
    listOfCharts.removeOne(observer_chart);
}
