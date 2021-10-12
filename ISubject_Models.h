#ifndef ISUBJECT_MODELS_H
#define ISUBJECT_MODELS_H

#include <QList>
#include "IObserver_Charts.h"


class ISubject_Models { // класс шаблона "наблюдатель", за которым наблюдают

    public:

        ISubject_Models();
        ~ISubject_Models();

        void Attach(IObserver_Charts *observer_chart); // добавить в список нового наблюдателя
        void Detach(IObserver_Charts *observer_chart); // удалить наблюдателя из списка
        virtual void Notify() = 0; // уведомление всех наблюдателей

    protected:

        QList<IObserver_Charts *> listOfCharts; // список наблюдателей
};

#endif // ISUBJECT_MODELS_H
