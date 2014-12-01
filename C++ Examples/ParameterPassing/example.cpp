#include "example.h"
#include <QDebug>
using namespace std;
Example::Example(const QString& name)
    : name(name)
{
    qDebug() << info() <<  " constructor";
}
Example::~Example(){
    qDebug() << info() << " destructor";
}
QString Example::info() const{
    return "Example address: " + QString::number((qulonglong) this, 16);
}
void Example::method(){
    qDebug() << info() << " calling method";
}
