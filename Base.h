#ifndef LABWORK5_QUEUE_H
#define LABWORK5_QUEUE_H
#include <iostream>
using namespace std;


template<typename T>
class BaseClass {
protected:
    virtual int GetSize() = 0;
    virtual void push(const T &num) = 0;
    virtual T pop() = 0;
    virtual T peek() = 0;
};
#endif
