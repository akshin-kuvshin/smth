// author: Danila "akshin_" Axyonov

#ifndef __ISTACK
#define __ISTACK

struct iNode {
    int val;
    iNode* next;

    iNode(int __val, iNode* __next);
};

struct iStack {
    iNode* head;

    iStack();
    ~iStack();
    void push(int val);
    void pop();
    int top();
    bool empty();
    void clear(); // TODO
};

#endif
