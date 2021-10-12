#include "helper_Strat.h"

helper_Strat::helper_Strat(Strat_GroupFiles *strat)
{
    someStrat = strat;  // устанавливаем стратегию при инициализации
}

helper_Strat::~helper_Strat(){

}

QVector<QStringList> helper_Strat::getComfyMapping(){ // выдает данные в удобном формате и высчитывает процент размера от общего

    someStrat->groupFiles(); // запускаем группировку
    int weight = someStrat->getWeight(); // получаем размер
    QHash<QString, int> initialData = someStrat->getGroup(); // получаем группу
    QVector<QStringList> outputData; // иницилизируем выходные данные

    QHash<QString, int>::iterator i = initialData.begin();
    while (i != initialData.end()) {
        QStringList row; // инициализируем строку
        row << i.key() << QString::number(i.value()); // добавляем в строку имя содержимого и его размер
        float procent = static_cast<float>(i.value())/(weight/100); // высчитываем процент размера содержимого

        if(procent < 0.01) row << "< 0.01%"; // если процент равен нулю то пишем "< 0.01%"
        else row << QString::number(procent,'a',2) + "%"; // а иначе формируем запись процента с двумя знаками после запятой
        outputData.append(row); // добавляем строку в выходные данные
        i++;
    }
    return outputData;
}
