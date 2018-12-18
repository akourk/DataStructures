// Author       :   Alex Kourkoumelis
// Date         :   11/10/2017
// Title        :   LinkedStack
// Description  :   Creates a LinkedStack header file, combining ideas of LinkedList and Stack
//              :   A stack that accepts data for nodes, each node points to the next
//              :   functions: push, pop, isEmpty, destroyList
//              :   main does a simple demonstration.

#include <iostream>
#include "LinkedStack.h"
using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    LinkedStack<int> ls;
    for (int i = 0; i < 10; i++){
        cout << "Pushing " << i << endl;
        ls.push(i);
    }
    for (int i = 0; i < 10; i++){
        cout << "Popping ";
        cout << ls.pop() << endl;
    }
    if (ls.isEmpty()){
        cout << "Linked Stack is empty." << endl;
    } else {
        cout << "Linked Stack is not empty." << endl;
    }

    return 0;
}