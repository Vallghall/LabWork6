#include <iostream>
#include "QueueDoubleList.h"

int main() {
    Queue<string> list;
    list.push("Van");
    list.push("Performance");
    list.push("Artist");
    cout << "The lenghth os the queue is " << list.GetSize() << endl;
    cout << "The top element in queue is " << list.peek() << endl;
    cout << "The first list is:\t" << list;
    Queue<string> fist = list;
    cout << "The copied list is:\t" << fist;
    for (int i = 0; i <= 2; i++)
    {
        cout  << list.pop() << " is out\n";
    }
    list.push("Gym");
    list.push("LeatherStuff");
    list.push("Chains");
    cout << list;
    Queue<string> mist = move(list);
    cout << "THe first list after removal: "<< list;
    cout << "The moved list is:\t" << mist;
}
