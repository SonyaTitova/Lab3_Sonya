#include "Folders_GroupFiles.h"

Folders_GroupFiles::Folders_GroupFiles(QString path) : Strat_GroupFiles(path)
{

}

Folders_GroupFiles::~Folders_GroupFiles(){

}

void Folders_GroupFiles::groupFiles(){

    //много static из-за рекурсии

    static int sum = 0; // накапливает размер
    static QString currentPath = path; // содержит актуальный путь
    QFileInfo fileInfo(currentPath); // получает информацию о файле через путь
    static QDir dir = fileInfo.dir(); // актуальная папка

    /*
    Рассмотрим способы обхода содержимого папок на диске.
    Предлагается вариант решения, который может быть применен для более сложных задач.
    Итак, если требуется выполнить анализ содержимого папки, то необходимо организовать обход
    содержимого.
    Например:
    */
    if (fileInfo.isDir()) {
    /*
    Если fileInfo папка, то заходим в нее, чтобы просмотреть находящиеся в ней файлы.
    Если нужно просмотреть все файлы, включая все вложенные папки, то нужно организовать
    рекурсивный обход.
    */
        if (dir.cd(fileInfo.fileName())) {
            /*
            Если зашли в папку, то пройдемся по контейнеру QFileInfoList, полученного методом
            entryInfoList,
            */
            foreach (QFileInfo inf, dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::Hidden | QDir::NoDotAndDotDot, QDir::Type)) {
                if(inf.isDir()){ // если при пробежке обнаружили папку, то включается рекурсия
                    currentPath = inf.filePath(); // сохраняем актуальный путь
                    groupFiles(); // рекурсия
                }
                sum += inf.size();
                // а если файлы, то находим его в group, и добавляем накапливаемый вес
                // иначе, добавляем в group новый ключ расширение файла
                if (inf.isFile()) {
                    QString completeSuffix = inf.completeSuffix(); // сохраняем расширение
                    if(group.contains(completeSuffix)){ // проверяем, есть ли уже такое расширение в group
                        QHash<QString, int>::const_iterator iter = group.find(completeSuffix); // нужен итератор, чтобы изменить значение веса
                        group[completeSuffix] = iter.value() + inf.size(); // добавляем вес
                    }else{
                        group[completeSuffix] = inf.size(); // добавляем расширение
                    }
                }
            }
            dir.cdUp();//выходим из папки
        }
    }
    weight = sum; // сохранили размер всей папки
}
