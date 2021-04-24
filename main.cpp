#include <iostream>
#include "QueueDoubleList.h"
#include "QueueArray.h"
template<typename T>
void testPoint(BaseClass<T> *point) {
    point->push("\nOh, I'm sorry\n");
    point->push("Sorry about what ?..\n");
    cout << "The size is " <<  point->GetSize();
    cout << point->pop() << "-- Steve" << endl;
    cout << point->pop() << "-- Bald guy" << endl;
}

template<typename T>
void testLink(BaseClass<T> &link) {
    link.push("\nLink? ");
    link.push("Link! ");
    cout << "The size is " << link.GetSize();
    cout << link.pop() << "is out" << endl;
    cout << link.pop() << "is out" << endl;
}
int main() {
    Queue<string> list;
    list.push("Van");
    list.push("Performance");
    list.push("Artist");
    cout << "The lenghth os the queue is " << list.GetSize() << endl;
    cout << "The top element in queue is " << list.peek() << endl;
    cout << "The first list is: " << list;
    Queue<string> fist = list;
    cout << "The copied list is: " << fist;
    for (int i = 0; i <= 2; i++)
    {
        cout  << list.pop() << " is out\n";
    }
    list.push("Gym");
    list.push("LeatherStuff");
    list.push("Chains");
    cout << list;
    Queue<string> mist = move(list);
    cout << "The first list after removal: "<< list;
    cout << "The moved list is: " << mist;
    cout << "_____________________________________\n";
    QArray<string> list2;
    list2.push("Billy");
    list2.push("Herrington");
    list2.push("Aniki");
    cout << "The lenghth os the queue is " << list2.GetSize() << endl;
    cout << "The top element in queue is " << list2.peek() << endl;
    cout << "The first list is: " << list2;
    QArray<string> fist2 = list2;
    cout << "The copied list is: " << fist2;
    for (int i = 0; i <= 2; i++)
    {
        cout  << list2.pop() << " is out\n";
    }
    list2.push("LeatherClub");
    list2.push("LockerRoom");
    list2.push("Two blocks down");
    cout << list2;
    QArray<string> mist2 = move(list2);
    cout << "The first list after removal: "<< list2;
    cout << "The moved list is: " << mist2;

    Queue<string> object;
    BaseClass<string> *point_you = &object;
    cout << "test pointer" << endl;
    testPoint(point_you);

    QArray<string> subject;
    BaseClass<string> &link_you = object;
    cout << "test link" << endl;
    testLink(link_you);
}
