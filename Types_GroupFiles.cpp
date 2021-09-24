#include "Types_GroupFiles.h"


Types_GroupFiles::Types_GroupFiles(QString path): Strat_GroupFiles(path){

}

Types_GroupFiles::~Types_GroupFiles(){

}

void Types_GroupFiles::groupFiles(){

    //много static из-за рекурсии

    static int sum = 0; // накапливает размер
    static QString currentPath = path; // содержит актуальный путь
    QFileInfo fileInfo(currentPath); // получает информацию о файле через путь
    static QDir dir = fileInfo.dir(); // актуальная папка
    static int level = 0; // слежение за уровнем углубления в файловую систему


    if(level == 0){ // если функцию вызывается в первый раз, то все статические значения обнуляем
        group.clear(); // очистить данные
        sum = 0; // накапливает размер
        currentPath = path; // содержит актуальный путь
        fileInfo = currentPath; // получает информацию о файле через путь
        dir = fileInfo.dir(); // актуальная папка
    }

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
            level++;

            foreach (QFileInfo inf, dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::Hidden | QDir::NoDotAndDotDot, QDir::Type)) {
                if(inf.isDir()){ // если при пробежке обнаружили папку, то включается рекурсия
                    currentPath = inf.filePath(); // сохраняем актуальный путь
                    groupFiles(); // рекурсия
                }
                sum += inf.size();
                // а если файлы, то находим его в group, и добавляем накапливаемый вес
                // иначе, добавляем в group новый ключ расширение файла
                if (inf.isFile()) {
                    QString suffix = inf.suffix(); // сохраняем расширение
                    if(group.contains(suffix)){ // проверяем, есть ли уже такое расширение в group
                        QHash<QString, int>::const_iterator iter = group.find(suffix); // нужен итератор, чтобы изменить значение веса
                        group[suffix] = iter.value() + inf.size(); // добавляем вес
                    }else{
                        group[suffix] = inf.size(); // добавляем расширение
                    }
                }
            }
            level--;

            dir.cdUp();//выходим из папки
        }
    }
    weight = sum; // сохранили размер всей папки
}

