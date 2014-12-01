#include "parentc.h"
#include <QDebug>

ParentC::ParentC(const QString &parentName)
    :name(parentName)
    , child(0)
{
}
ParentC::~ParentC(){
    qDebug() << "ParentC destructor";
}
void ParentC::setChild(Example *example){
    child = example;
}

QString ParentC::info() const{
    if (child != nullptr){
        return "ParentC[" + name + "]+" + child->info();
    }
    else {
        return "ParentC[" + name + "] no child";
    }
}
void ParentC::method(){
}
void ParentC::childMethod(){
    if (child != nullptr){
        child->method();
    }
}
