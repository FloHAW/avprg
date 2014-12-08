#include <QDebug>
#include "example.h"
#include <memory>


void testExampleNewDelete(){
    Example* example = new Example("#1");

    (*example).method();
    example->method();
    // requires delete!!!
    delete example;
}

void testExampleStack(){
    Example example("#2");
    example.method();
    // no delete!!!!
}

// C++11 version
// see: http://herbsutter.com/2013/05/29/gotw-89-solution-smart-pointers/
// and: http://herbsutter.com/2013/05/30/gotw-90-solution-factories/
// and many other articles...

void testExampleUniquePtr(){
    std::unique_ptr<Example> example(new Example("#3"));
    example->method();

    auto example2 = std::make_unique<Example>("#4");
}



int main(int argc, char *argv[])
{
//    testExampleNewDelete();
    testExampleStack();
//    testExampleUniquePtr();
}

