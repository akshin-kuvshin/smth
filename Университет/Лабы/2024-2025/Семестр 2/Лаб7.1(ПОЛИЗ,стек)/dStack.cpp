// author: Danila "akshin_" Axyonov

#include "dStack.hpp"

#include <iostream>
// #include <cstdlib>

using namespace std;






dNode::dNode(double __val, dNode* __next) {
    this->val = __val;
    this->next = __next;
    return;
}





dStack::dStack() {
    this->head = nullptr;
    this->size = 0;
    return;
}

dStack::~dStack() {
    this->clear();
    return;
}

void dStack::push(double val) {
    this->head = new dNode(val, this->head);
    ++(this->size);
    return;
}

void dStack::pop() {
    if (this->empty()) {
        cerr << "\t(!) Ошибка: была вызвана функция pop() на пустом стеке." << endl;
        exit(1);
    }
    dNode* last = this->head;
    this->head = this->head->next;
    delete last;
    --(this->size);
    return;
}

double dStack::top() {
    if (this->empty()) {
        cerr << "\t(!) Ошибка: была вызвана функция top() на пустом стеке." << endl;
        exit(1);
    }
    return this->head->val;
}

bool dStack::empty() {
    return (this->size == 0);
}

void dStack::clear() {
    while (not this->empty())
        this->pop();
    return;
}
