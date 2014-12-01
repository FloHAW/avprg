#include "parentb.h"
#include <QDebug>

ParentB::ParentB(const QString &parentName, const QString &childName)
    :name(parentName)
    , child(childName)
{
}
ParentB::~ParentB(){
    qDebug() << info() << " destructor";
}

QString ParentB::info() const{
    return "ParentB[" + name + "]+" + child.info();
}
void ParentB::method(){
}

void ParentB::childMethod(){
    child.method();
}
