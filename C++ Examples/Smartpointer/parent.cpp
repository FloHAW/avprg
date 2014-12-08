#include "parent.h"
#include <QDebug>

Parent::Parent(const QString &parentName)
    :name(parentName)
    , child(nullptr)
{
}
Parent::~Parent(){
    qDebug() << "Parent destructor";
}
//void Parent::setChild(std::shared_ptr<Example>example){
void Parent::setChild(Example* example){
    child = example;
}

QString Parent::info() const{
    if (child != nullptr){
        return "Parent[" + name + "]+" + child->info();
    }
    else {
        return "Parent[" + name + "] no child";
    }
}
void Parent::method(){
}
void Parent::childMethod(){
    if (child != nullptr){
        child->method();
    }
}
