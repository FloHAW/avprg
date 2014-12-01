#include <QDebug>
#include "example.h"
#include "parenta.h"
#include "parentb.h"
#include <memory>



void testCopyOfObject(){
    qDebug() << "======================";
    Example example("E1");
    qDebug() << example.info();

    Example copyOfExample(example);
    qDebug() << copyOfExample.info();
}

void crashCopyOfObject(){
    qDebug() << "======================";
    ParentA parentA("P1", "C1");
    qDebug() << parentA.info();

    ParentA copyOfParentA(parentA);
    qDebug() << copyOfParentA.info();
}





void callByValue(ParentA parent){
    qDebug() << "passed by value: " << parent.info();
}

void crashCallByValue(){
    qDebug() << "======================";
    ParentA parent("P1", "C1");
    qDebug() << parent.info();
    callByValue(parent);
}

void testCopyConstructor(){
    qDebug() << "======================";
    ParentB parentB("P1", "C1");
    qDebug() << parentB.info();

    ParentB copyOfParentB(parentB);
    qDebug() << copyOfParentB.info();

}

void callByValueB(ParentB parent){
    qDebug() << "passed by value: " << parent.info();
}

void testCallByValue(){
    qDebug() << "======================";
    ParentB parentB("P1", "C1");
    qDebug() << parentB.info();

    callByValueB(parentB);
}
int main(int argc, char *argv[])
{
    testCopyOfObject();
//    crashCopyOfObject();
//    crashCallByValue();

    testCopyConstructor();
    testCallByValue();


}

