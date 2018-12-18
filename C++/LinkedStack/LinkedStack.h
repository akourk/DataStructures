// Author       :   Alex Kourkoumelis
// Date         :   11/10/2017
// Title        :   LinkedStack
// Description  :   Creates a LinkedStack header file, combining ideas of LinkedList and Stack
//              :   A stack that accepts data for nodes, each node points to the next
//              :   functions: push, pop, isEmpty, destroyList
//              :   main does a simple demonstration.

#ifndef LINKEDSTACK_LINKEDSTACK_H
#define LINKEDSTACK_LINKEDSTACK_H

#include <iostream>
using namespace std;

template <class T>
struct node{
    T data;
    node<T>* next;
};

template <class T>
class LinkedStack{
    node<T> *top;

public:
    LinkedStack();
    void push(T&);
    T pop();
    bool isEmpty();
    void destroyList();
    ~LinkedStack();
};

template <class T>
LinkedStack<T>::LinkedStack(){
    top = NULL;
}

template <class T>
void LinkedStack<T>::push(T& item){
    node<T> *p = new node<T>;
    p->data = item;
    p->next = top;
    top = p;
}

template <class T>
T LinkedStack<T>::pop(){
    node<T> *p = top;
    top = top->next;
    T data = p->data;
    delete p;
    return data;
}

template <class T>
bool LinkedStack<T>::isEmpty(){
    return top == NULL;
}

template <class T>
void LinkedStack<T>::destroyList(){
    node<T> *p;
    while(top != NULL){
        p = top;
        top = top->next;
        delete p;
    }
}

template <class T>
LinkedStack<T>::~LinkedStack(){
    destroyList();
}

#endif //LINKEDSTACK_LINKEDSTACK_H
