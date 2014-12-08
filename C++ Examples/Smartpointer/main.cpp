#include "parent.h"
#include "application.h"
#include <vector>
#include <memory>
#include "smartpointer.h"
using namespace std;


void testMySmartPointer(){
    SmartPointer<Example> example(new Example("E"));
    example->method();
}

void testApplication(){
    Application app;
    app.show();
    app.activateChild();
    app.show();
}

void testContainer(){
    std::vector<Example*> examples(3);
    examples[0] = new Example("E1");
    examples[1] = new Example("E2");
    examples[2] = new Example("E3");

    for(int i = 0; i < examples.size(); i++){
        delete examples[i];
    }



}
void testContainerSmartPointer(){
    std::vector<shared_ptr<Example> > examples(3);
    examples[0] = shared_ptr<Example>(new Example("e1"));
    examples[1] = make_shared<Example>("e2");
    examples[2] = make_shared<Example>("e3");

}

int main(int argc, char *argv[])
{
    testMySmartPointer();

    //   shared_ptr<Example> example = createExample();
  //  shared_ptr<Example> copyOfExample(example);
//    testParent();
    testApplication();
    testContainerSmartPointer();
    return 0;
}
