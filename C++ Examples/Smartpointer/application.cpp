#include "application.h"
#include <QDebug>

using namespace std;

Application::Application()
    : parent("P")
    , example(nullptr)
{
}

Application::~Application(){
    delete example;
}

void Application::activateChild(){
// the following will not work;
// example becomes invalid when leaving the function
// while parent continues using it:
//    Example example("E");
//    parent.setChild(&example);

// the following works, but leads to a memory leak, since
// example cannot be deleted outside this function:
//    Example* example = new Example("E");
//    parent.setChild(example);

// only valid solution: Example becomes member of application
      example = new Example("E");
      parent.setChild(example);

}

void Application::show(){
    qDebug() << parent.info();
}
