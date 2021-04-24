#ifndef LABWORK6_A_QUEUEDOUBLELIST_H
#define LABWORK6_A_QUEUEDOUBLELIST_H
#include "Base.h"
template<typename T>
struct thing {
    T num;
    thing<T> *Prev;
    thing<T> *Next;
};
template<typename T>
class Queue : public BaseClass<T> {
    thing<T> *Head, *Tail;
public:
    Queue();
    Queue(Queue &stuff);
    Queue(Queue&& other)noexcept;
    ~Queue();
    int GetSize();
    void push(const T &num);
    T pop() override;
    T peek() override;
    Queue &operator=(const Queue &other)noexcept;
    Queue &operator=(Queue &&other)noexcept;
    template<typename T> friend ostream &operator<<(ostream &stream, const Queue<T> &garbage)
    {
        if (garbage.Head == nullptr) return stream << "Your queue's empty \n";
        thing<T> *temp = garbage.Head;
        while (temp != nullptr)
        {
            stream << temp->num<< " ";
            temp = temp->Next;
        }
        cout << endl;
        return stream;
    }
};



template<typename T>
Queue<T>::Queue()
{
    Head = nullptr;
    Tail = nullptr;
}
template<typename T>
Queue<T>::Queue(Queue &stuff) {
    Head = nullptr;
    Tail = nullptr;
    if (stuff.Head == nullptr)
    {
        Head = Tail = nullptr;
        return;
    }
    thing<T> *temp = stuff.Head;
    while (temp != nullptr)
    {
        push(temp->num);
        temp = temp->Next;
    }
}
template<typename T>
Queue<T>::Queue(Queue&& other)noexcept
{
    if (other.Head == nullptr)
    {
        Head = Tail = nullptr;
        return;
    }
    Head = other.Head;
    Tail = other.Tail;
    other.Head = other.Tail = nullptr;
}
template<typename T>
Queue<T>::~Queue() {
    thing<T> *temp = Head;
    while (temp != nullptr)
    {
        temp = Head->Next;
        delete Head;
        Head = temp;
    }
}
template<typename T>
void Queue<T>::push(const T &num) {
    auto *temp = new thing<T>;
    temp->Next = nullptr;
    temp->num = num;
    if(Head != nullptr)
    {
        temp->Prev = Tail;
        Tail->Next = temp;
        Tail = temp;
    }
    else {
        temp->Prev = nullptr;
        Head = Tail = temp;
    }
}

template<typename T>
T Queue<T>::peek() {
    thing<T> *temp = Head;
    return temp->num;
}

template<typename T>
int Queue<T>::GetSize() {
    if (Head == nullptr) return 0;
    thing<T> *temp = Head;
    int size = 0;
    while (temp != nullptr)
    {
        size += 1;
        temp = temp->Next;
    }
    return size;
}

template<typename T>
T Queue<T>::pop() {
    T rst;
    if ((Head != nullptr) && (Head->Next))
    {
        rst = Head->num;
        thing<T> *temp = Head;
        Head = Head->Next;
        Head->Prev = nullptr;
        delete temp;
        return rst;
    }
    else if ((Head != nullptr) && (Head == Tail))
    {
        rst = Head->num;
        Head->Next = nullptr;
        Head = nullptr;
        delete Head;
        return rst;
    }
}
template<typename T>
Queue<T> &Queue<T>::operator=(const Queue &other)noexcept {
    Head = nullptr;
    Tail = nullptr;
    if (other.Head == nullptr)
    {
        Head = Tail = nullptr;
        return *this;
    }
    thing<T> *temp = other.Head;
    while (temp != nullptr)
    {
        push(temp->num);
        temp = temp->Next;
    }
    return *this;
}
template<typename T>
Queue<T> &Queue<T>::operator=(Queue &&other)noexcept {
    if (this == &other || other.Head == nullptr) {
        return *this;
    }
    Head = other.Head;
    Tail = other.Tail;
    other.Head = other.Tail = nullptr;
    return *this;
}
template<typename T> ostream &operator<<(ostream &stream, const BaseClass<T> &garbage)
{
    if (garbage.Head == nullptr) return stream << "Your queue's empty \n";
    thing<T> *temp = garbage.Head;
    while (temp != nullptr)
    {
        stream << temp->num<< " ";
        temp = temp->Next;
    }
    cout << endl;
    return stream;
}
#endif //LABWORK6_A_QUEUEDOUBLELIST_H
