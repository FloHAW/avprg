#include <QDebug>
#include "example.h"
#include "parenta.h"
#include <memory>



void callByReference(Example& example){
    qDebug() << "passed by reference: " << example.info();
}

void testCallByReference(){
    Example example("E1");
    qDebug() << example.info();
    callByReference(example);
}


void callByPointer(Example* example){
    qDebug() << "passed by pointer: " << example->info();
}

void testCallByPointer(){
    Example example("E2");
    qDebug() << example.info();
    callByPointer(&example);
}


void callByValue(Example example){
    qDebug() << "passed by value: " << example.info();
}

void testCallByValue(){
    Example example("E3");
    qDebug() << example.info();
    callByValue(example);
}

int main(int argc, char *argv[])
{
//    testCallByReference();
//    testCallByValue();
      testCallByPointer();
}

