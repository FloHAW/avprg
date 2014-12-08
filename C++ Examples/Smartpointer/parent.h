#ifndef PARENT_H
#define PARENT_H
#include <memory>
#include "example.h"
class Parent
{
public:
    Parent(const QString& parentName);
    ~Parent();
//    void setChild(std::shared_ptr<Example> example);
    void setChild(Example*example);
    void method();
    void childMethod();
    QString info() const;
private:
    QString name;
//    std::shared_ptr<Example>child;
    Example*child;
};

#endif // PARENT_H
