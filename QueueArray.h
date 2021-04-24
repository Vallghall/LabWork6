#ifndef LABWORK6_A_QUEUEARRAY_H
#define LABWORK6_A_QUEUEARRAY_H
#include "Base.h"

template<typename T>
class QArray : public BaseClass<T>{
    int count = 0;
    T* arr;
public:
    QArray();
    QArray(QArray &obj);
    QArray(QArray&& obj)noexcept;
    ~QArray();
    int GetSize() override;
    void push(const T &item) override;
    T pop() override;
    T peek() override;
    QArray &operator=(const QArray &obj)noexcept;
    QArray &operator=(QArray &&obj)noexcept;
    template<typename T> friend ostream &operator<<(ostream &stream, const QArray<T> &garbage);
};

template<typename T>
QArray<T> :: QArray() {
    count = 0;
}

template<typename T>
QArray<T> :: QArray(QArray &obj) {
    count = obj.count;
    arr = new T[count];
    for (int i = 0; i < count; i++)
        arr[i] = obj.arr[i];
}

template<typename T>
QArray<T> :: QArray(QArray &&obj)noexcept {

    arr = obj.arr;
    count = obj.count;
    obj.arr = nullptr;
}

template<typename T>
QArray<T> :: ~QArray() {
    if (count > 1)
        delete[] arr;
}

template<typename T>
void QArray<T>::push(const T &item) {
    T* temp;
    temp = arr;
    arr = new T[count + 1];

    for (int i = 0; i < count; i++)
        arr[i] = temp[i];
    arr[count] = item;
    count++;
    if (count > 1)
        delete[] temp;
}

template<typename T>
T QArray<T>::peek() {
    if (count > 0)
        return arr[0];
    else
        return 0;
}

template<typename T>
int QArray<T>::GetSize() {
    return count;
}

template<typename T>
T QArray<T>::pop() {
    if (count == 0)
        return 0;
    T item;
    item = arr[0];
    T* temp;
    temp = new T[count - 1];
    count--;
    for (int i = 0; i < count; i++)
        temp[i] = arr[i + 1];
    if (count > 0)
        delete[] arr;
    arr = temp;
    return item;
}

template<typename T>
QArray<T> &QArray<T>::operator=(const QArray &obj)noexcept {
    if (this == &obj)
        return *this;
    count = obj.count;
    arr = new T[count];
    for (int i = 0; i < count; i++)
        arr[i] = obj.arr[i];
}

template<typename T>
QArray<T> &QArray<T>::operator=(QArray &&obj)noexcept {
    if (this == &obj)
        return *this;

    arr = obj.arr;
    count = obj.count;
    obj.arr = nullptr;
}

template<typename T> ostream &operator<<(ostream &stream, const QArray<T> &garbage)
{
    if (garbage.arr == nullptr) return stream << "Your queue's empty \n";
    for (int i = 0; i < garbage.count; i++){
        stream << garbage.arr[i] << " ";
    }
    return stream << endl;
}

#endif //LABWORK6_A_QUEUEARRAY_H
