#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

template  <class T> class SmartPointer
{
public:
    SmartPointer(T* ptr)
        : ptr(ptr){}
    ~SmartPointer(){
        delete ptr;
    }
    T& operator*(){
        return *ptr;
    }
    T* operator->(){
        return ptr;
    }

private:
    T *ptr;
};

#endif // SMARTPOINTER_H
