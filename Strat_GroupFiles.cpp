#include "Strat_GroupFiles.h"


Strat_GroupFiles::Strat_GroupFiles(QString path_){
    path = path_;
}

Strat_GroupFiles::~Strat_GroupFiles()
{

}

void Strat_GroupFiles::setPath(QString path_){
    path = path_;
}

QString Strat_GroupFiles::getPath(){
    return path;
}

int Strat_GroupFiles::getWeight(){
    return weight;
}

QHash<QString, int> Strat_GroupFiles::getGroup(){
    return group;
}
