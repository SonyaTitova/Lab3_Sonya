#include "BarChart.h"

BarChart::BarChart()
{

}

BarChart::~BarChart(){

}

QChart* BarChart::createChart(){ // реализация чисто виртуальной функции класса шаблон для создания диаграммы

    if (groupToQChart.size() == 0) return qChart; // если вдруг дирректория не выбрана, то ничего не делать

    QStringList categories; // создаем категории для названий столбиков
    QStackedBarSeries *series = new QStackedBarSeries(); // содержит числовые значения для столбца
    QBarSet *set = new QBarSet("Bar set"); // содержит значения для серии в столбце, но серия в нашем случае одна

    for(int i = 0; i < groupToQChart.size(); i++){ // пробежка по данным из правой таблицы

        QString procent = groupToQChart[i][2]; // берём из данных строку, которая выражает процент
        QRegExp reg("\\d+\\.\\d+"); // регулярное выражение для того чтобы вырезать само число из строки
        reg.indexIn(procent); // функция которая находит и складирует нужное число в reg

        procent = reg.cap(0); // присваиваем строке процента это самое число
        // превращаем строку в дробное число, которое является процентом
        *set << static_cast<qreal>(procent.toDouble()); // и кладем его в серию
        categories << categories << groupToQChart[i][0]; // в категории добавляем имя файла
    }
    // добавляем 100, чтобы отображались на гистограмме макс. 100 процентов
    *set << static_cast<qreal>(100);

    series->append(set); // добавляем серию в столбик

    qChart->addSeries(series);  // добавляем столбцы в диаграмму

    QBarCategoryAxis *axis = new QBarCategoryAxis(); // это оси
    axis->append(categories); // добавляем категории
    qChart->createDefaultAxes(); // добавляем оси по-умолчанию
    qChart->setAxisX(axis, series); // устанавливаем соответствующему столбцу категорию

    return qChart;
}

