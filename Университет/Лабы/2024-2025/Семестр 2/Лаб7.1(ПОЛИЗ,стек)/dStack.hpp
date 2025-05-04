// author: Danila "akshin_" Axyonov

#ifndef __DSTACK
#define __DSTACK

struct dNode {
    double val;
    dNode* next;

    dNode(double __val, dNode* __next);
};

struct dStack {
    dNode* head;
    int size;

    dStack();
    ~dStack();
    void push(double val);
    void pop();
    double top();
    bool empty();
    void clear(); // TODO
};

#endif
