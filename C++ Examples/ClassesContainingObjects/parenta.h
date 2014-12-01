#ifndef PARENTA_H
#define PARENTA_H

#include "example.h"
class ParentA
{
public:
    ParentA(const QString& partentName, const QString& childName);
    ~ParentA();
    void method();
    void childMethod();
    QString info() const;
private:
    QString name;
    Example *child;
};

#endif // PARENTA_H
