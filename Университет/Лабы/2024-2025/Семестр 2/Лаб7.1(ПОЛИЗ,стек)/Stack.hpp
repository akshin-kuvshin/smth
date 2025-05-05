// author: Danila "akshin_" Axyonov

#ifndef __STACK
#define __STACK

template<typename T>
struct Node {
    T val;
    Node* next;

    Node(T __val, Node* __next);
};

template<typename T>
struct Stack {
    Node<T>* head;
    int size;

    Stack();
    ~Stack();
    void push(T val);
    void pop();
    T top();
    bool empty();
    void clear(); // TODO
};





#include <iostream>
// #include <cstdlib>

using namespace std;





template<typename T>
Node<T>::Node(T __val, Node* __next) {
    this->val = __val;
    this->next = __next;
    return;
}





template<typename T>
Stack<T>::Stack() {
    this->head = nullptr;
    this->size = 0;
    return;
}

template<typename T>
Stack<T>::~Stack() {
    this->clear();
    return;
}

template<typename T>
void Stack<T>::push(T val) {
    this->head = new Node<T>(val, this->head);
    ++(this->size);
    return;
}

template<typename T>
void Stack<T>::pop() {
    if (this->empty()) {
        cerr << "\t(!) Ошибка: функция pop() была вызвана на пустом стеке." << endl;
        exit(1);
    }
    Node<T>* last = this->head;
    this->head = this->head->next;
    delete last;
    --(this->size);
    return;
}

template<typename T>
T Stack<T>::top() {
    if (this->empty()) {
        cerr << "\t(!) Ошибка: функция top() была вызвана на пустом стеке." << endl;
        exit(1);
    }
    return this->head->val;
}

template<typename T>
bool Stack<T>::empty() {
    return (this->size == 0);
}

template<typename T>
void Stack<T>::clear() {
    while (not this->empty())
        this->pop();
    return;
}





#endif
