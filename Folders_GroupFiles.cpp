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
    QFileInfo fileInfo = currentPath; // получает информацию о файле через путь
    static QDir dir = fileInfo.dir(); // актуальная папка
    static int level = 0; // слежение за уровнем углубления в файловую систему
    static int oldSize = 0; // нужен чтобы считать размер верхнего уровня

    if(level == 0){
        group.clear(); // очистить данные
        sum = 0; // накапливает размер
        currentPath = path; // содержит актуальный путь
        fileInfo = currentPath; // получает информацию о файле через путь
        dir = fileInfo.dir(); // актуальная папка
        oldSize = 0; // нужен чтобы считать размер верхнего уровня
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
                // а если файлы, то если они на первом уровне, то фиксируем собранный размер
                if (inf.isFile() && level == 1) {
                    qDebug() << inf.fileName() << "---" << sum - oldSize;
                    group[inf.fileName()] = sum - oldSize;
                    oldSize = sum;
                }
            }
            level--;
            /*
            если произошло много пробежек по уровням,
            но мы вернулись на самый первый, то фиксируем собранный размер
            */
            if(level == 1) {
                qDebug() << dir.dirName() << "---" << sum - oldSize;
                group[dir.dirName()] = sum - oldSize;
                oldSize = sum;
            }
            dir.cdUp();//выходим из папки
        }
    }
    weight = sum; // сохранили размер всей папки
}
