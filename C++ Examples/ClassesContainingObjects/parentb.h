#ifndef PARENTB_H
#define PARENTB_H
#include "example.h"
class ParentB
{
public:
    ParentB(const QString& partentName, const QString& childName);
    ~ParentB();

    void method();
    void childMethod();
    QString info() const;
private:
    QString name;
    Example child;
};
#endif // PARENTB_H
