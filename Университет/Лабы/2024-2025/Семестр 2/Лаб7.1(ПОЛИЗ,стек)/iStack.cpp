// author: Danila "akshin_" Axyonov

#include "iStack.hpp"

#include <iostream>
#include <cstdlib>

using namespace std;






iNode::iNode(int __val, iNode* __next) {
    this->val = __val;
    this->next = __next;
    return;
}





iStack::iStack() {
    this->head = nullptr;
    return;
}

iStack::~iStack() {
    this->clear();
    return;
}

void iStack::push(int val) {
    this->head = new iNode(val, this->head);
    return;
}

void iStack::pop() {
    if (this->empty()) {
        cerr << "\t(!) Ошибка: была вызвана функция pop() на пустом стеке." << endl;
        exit(1);
    }
    iNode* last = this->head;
    this->head = this->head->next;
    delete last;
    return;
}

int iStack::top() {
    if (this->empty()) {
        cerr << "\t(!) Ошибка: была вызвана функция top() на пустом стеке." << endl;
        exit(1);
    }
    return this->head->val;
}

bool iStack::empty() {
    return not (bool)(this->head);
}

void iStack::clear() {
    while (not this->empty())
        this->pop();
    return;
}
