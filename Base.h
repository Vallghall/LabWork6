#ifndef LABWORK5_QUEUE_H
#define LABWORK5_QUEUE_H
#include <iostream>
using namespace std;

template<typename T>
struct thing {
    T num;
    thing<T> *Prev;
    thing<T> *Next;
};

template<typename T>
class BaseClass {
protected:
    thing<T> *Head, *Tail;
public:
    virtual int GetSize() = 0;
    virtual void push(const T &num) = 0;
    virtual T pop() = 0;
    virtual T peek() = 0;
};
#endif
