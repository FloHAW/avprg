#ifndef APPLICATION_H
#define APPLICATION_H

#include "parent.h"


class Application
{
public:
    Application();
    ~Application();
    void activateChild();
    void show();
private:
    Parent parent;
    Example *example;
};

#endif // APPLICATION_H
