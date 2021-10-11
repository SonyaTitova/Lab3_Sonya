#include "PieChart.h"

PieChart::PieChart()
{

}

PieChart::~PieChart()
{

}

QChart* PieChart::createChart(){

    if (groupToQChart.size() == 0) return qChart; // если вдруг дирректория не выбрана, то ничего не делать

    QPieSeries *series = new QPieSeries();

    for(int i = 0; i < groupToQChart.size(); i++){ // пробежка по данным из правой таблицы

        QString procent = groupToQChart[i][2]; // берём из данных строку, которая выражает процент
        QRegExp reg("\\d+\\.\\d+"); // регулярное выражение для того чтобы вырезать само число из строки
        reg.indexIn(procent); // функция которая находит и складирует нужное число в reg

        procent = reg.cap(0); // присваиваем строке процента это самое число

        QString sliceName = groupToQChart[i][0]; // берём имя сектора

        // превращаем строку в дробное число, которое является процентом
        qreal sliceVal = static_cast<qreal>(procent.toDouble());

        QPieSlice *slice = series->append(sliceName, sliceVal); // и кладем всё в сектор круга

        // функции для лучшего отображения круговой диаграммы
        slice->setLabelVisible(); // чтобы сектор был видимым
        slice->setExploded(); // чтобы сектора расходились от центра круга, по мере их количества
    }
    // далее идут функции которые просто устанавливают настройки размера и масштабируемости курговой диаграммы
    qreal pieSize = 0.5;
    qreal hPos = (pieSize / 0.98) + (0.1 / (qreal)2);
    series->setPieSize(pieSize);
    series->setHorizontalPosition(hPos);
    series->setVerticalPosition(0.5);
    qChart->addSeries(series);

    return qChart;
}
