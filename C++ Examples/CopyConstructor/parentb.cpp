#include "parentb.h"
#include <QDebug>

ParentB::ParentB(const QString &parentName, const QString &childName)
    :name(parentName)
    , child(new Example(childName))
{
}
ParentB::ParentB(const ParentB& other)
    :name(other.name)
    , child(new Example(*other.child))
{
    qDebug() << "copied " << other.info();
    qDebug() << "   --> " << info();
}
ParentB::~ParentB(){
    delete child;
}
QString ParentB::info() const{
    return "ParentB (address: " + QString::number((qulonglong) this, 16) + ") "
            + child->info();
}
void ParentB::method(){
}
void ParentB::childMethod(){
    child->method();
}

