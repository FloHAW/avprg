#include <QDebug>
#include "example.h"
#include "parenta.h"
#include "point.h"
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

Point addOffsetByValue(Point point, int offset){
    point.x += offset;
    point.y += offset;
    return point;
}
void addOffsetByReference(Point& point, int offset){
    point.x += offset;
    point.y += offset;
}
void testPoint(){
    // call by value
    Point pt1(10, 20);
    Point pt2 = addOffsetByValue(pt1, 5);
    qDebug() <<"pt1: " << pt1.x << " " << pt1.y;
    qDebug() <<"pt2: " << pt2.x << " " << pt2.y;

    // call by reference
    Point pt3(10, 20);
    addOffsetByReference(pt3, 7);
    qDebug() <<"pt3: " << pt3.x << " " << pt3.y;
}

int main(int argc, char *argv[])
{
//    testCallByReference();
    testCallByValue();
//      testCallByPointer();
    testPoint();
}

