#ifndef PARENTC_H
#define PARENTC_H

#include "example.h"
class ParentC
{
public:
    ParentC(const QString& parentName);
    ~ParentC();
    void setChild(Example* example);
    void method();
    void childMethod();
    QString info() const;
private:
    QString name;
    Example *child;
};

#endif // PARENTC_H
