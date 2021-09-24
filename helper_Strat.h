#ifndef HELPER_STRAT_H
#define HELPER_STRAT_H

#include <Strat_GroupFiles.h>
#include <QVector>
#include <QString>
#include <QStringList>

class helper_Strat // класс помогающий адаптировать начальные данные Strat_GroupFiles к модели
{
    public:

        helper_Strat(Strat_GroupFiles *strat);
        ~helper_Strat();

        QVector<QStringList> getComfyMapping(); // выдает данные в удобном формате и высчитывает процент размера от общего

    private:

        Strat_GroupFiles *someStrat; // указатель на стратегию

};

#endif // HELPER_STRAT_H
