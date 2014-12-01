#include <QDebug>
#include "example.h"
#include "parenta.h"
#include "parentb.h"
#include "parentc.h"
#include <memory>

void testParentA()
{
    ParentA * parentA = new ParentA("P1", "C1");
    qDebug() << parentA->info();
    parentA->childMethod();
    delete parentA;
}

void testParentB(){
    ParentB * parentB = new ParentB("P2", "C2")   ;
    qDebug() << parentB->info();
    parentB->childMethod();
    delete parentB;
}

void testParentC(){
    ParentC parentC("P3");
    qDebug() << parentC.info();
    parentC.childMethod();

    Example example("C3");
    parentC.setChild(&example);
    qDebug() << parentC.info();

    parentC.childMethod();
}

int main(int argc, char *argv[])
{
    testParentA();
    testParentB();
    testParentC();
}

