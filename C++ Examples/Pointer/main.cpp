#include <QDebug>



void modifyIntValue(int *data){
    *data = 19;
}

void testPointer(){
    // pointer to value
    int intValue = 5;
    int* pointerToInt = &intValue;
    qDebug() << "pointerToInt: " << pointerToInt;

    // de-reference operator
    *pointerToInt = 7;
    qDebug() << "intValue: " << intValue; // 7

    // same value as intValue
    int anotherIntValue = *pointerToInt;
    qDebug() << "anotherIntValue: " << anotherIntValue;

    // copy of pointer
    int* copyOfPointer = pointerToInt;
    *copyOfPointer = 9;
    qDebug() << "intValue: "  << intValue;

    // modify int value inside function
    modifyIntValue(&intValue);
    qDebug() << "intValue: "  << intValue;
}

void crash(){
    int *pointerToInt = (int*)0x1234557;
    *pointerToInt = 0;
}

void copyData(int* src, int *dst, int count){
    for(int i = 0; i < count; i++){
//  entweder so:
//        *dst++ = *src++;
//  oder bsser:
        dst[i] = src[i];
    }
}

void showArray(int *array, int count){
    for(int i = 0; i < count; i++){
        qDebug() << array[i];
    }
}
void fillArray(int *array, int count, int number){
    for(int i = 0; i < count; i++){
        array[i] = number;
    }
}

void testArray(){
    // pointer to array (points to first element)
    int *array = new int[10];
    qDebug() << "array: " << array;
    qDebug() << "address of array[0]: " << &array[0];
    qDebug() << "address of array[1]: " << &array[1];
    showArray(array, 10);

    // copy array
    fillArray(array, 10, 17);
    int *copy = new int[10];
    copyData(array, copy, 10);
    showArray(copy, 10);

    delete[] copy;
    delete[] array;
}

int main(int argc, char *argv[])
{
    testPointer();
    testArray();
}
