#include "parenta.h"
#include <QDebug>

ParentA::ParentA(const QString &parentName, const QString &childName)
    :name(parentName)
    , child(new Example(childName))
{
}

ParentA::~ParentA(){
    delete child;
}
QString ParentA::info() const{
    return "ParentA (address: " + QString::number((qulonglong) this, 16) + ") "
            + child->info();
}
void ParentA::method(){
}
void ParentA::childMethod(){
    child->method();
}

