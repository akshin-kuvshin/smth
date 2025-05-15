#ifndef __DOUBLE_LIST
#define __DOUBLE_LIST

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;



template<typename T>
struct Node {
    T val;
    Node* prev;
    Node* next;

    Node();
    Node(T __val, Node* __prev, Node* __next);
};

template<typename T>
Node<T>::Node() {
    this->val = T{};
    this->prev = this->next = nullptr;
    return;
}

template<typename T>
Node<T>::Node(T __val, Node* __prev, Node* __next) {
    this->val = __val;
    this->prev = __prev;
    this->next = __next;
    return;
}



template<typename T>
struct DoubleLinkedList {
    Node<T>* head;
    Node<T>* tail;
    int size;

    DoubleLinkedList();
    ~DoubleLinkedList();
    void push_front(T val);
    void push_back(T val);
    void push_before(Node<T>* p, T val);
    void push_after(Node<T>* p, T val);
    void pop_front();
    void pop_back();
    void pop(Node<T>* p);
    Node<T>* find_val(T val);
    Node<T>* find_pos(int pos);
    bool empty();
    void clear();
    void print();
};

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() {
    this->head = new Node<T>();
    this->tail = new Node<T>();
    if (not this->head or not this->tail) {
        cerr << endl
             << "(!) Ошибка: не удалось выделить память под узлы фиктивных головы и хвоста в конструкторе DoubleLinkedList()." << endl;
        exit(1);
    }
    this->head->next = this->tail;
    this->tail->prev = this->head;
    this->size = 0;
    return;
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    this->clear();
    delete this->head;
    delete this->tail;
    return;
}

// в следующих двух методах (а также в методе pop()) отсутствует проверка
// на валидность указателя на узел двусвязного списка,
// т.к. я не знаю, как это эффективно реализовать.
template<typename T>
void DoubleLinkedList<T>::push_front(T val) {
    this->push_after(this->head, val);
    return;
}

template<typename T>
void DoubleLinkedList<T>::push_back(T val) {
    this->push_before(this->tail, val);
    return;
}

template<typename T>
void DoubleLinkedList<T>::push_before(Node<T>* p, T val) {
    Node<T>* q = new Node<T>(val, p->prev, p);
    if (not q) {
        cerr << endl
             << "(!) Ошибка: не удалось выделить память под новый узел в методе push_before(Node<T>* p, T val)." << endl;
        exit(1);
    }
    q->prev->next = q->next->prev = q;
    ++(this->size);
    return;
}

template<typename T>
void DoubleLinkedList<T>::push_after(Node<T>* p, T val) {
    Node<T>* q = new Node<T>(val, p, p->next);
    if (not q) {
        cerr << endl
             << "(!) Ошибка: не удалось выделить память под новый узел в методе push_after(Node<T>* p, T val)." << endl;
        exit(1);
    }
    q->prev->next = q->next->prev = q;
    ++(this->size);
    return;
}

// если вызвать следующие два метода на пустом двусвязном списке,
// то будет напечатано сообщение об ошибке из метода pop(Node<T>* p).
template<typename T>
void DoubleLinkedList<T>::pop_front() {
    this->pop(this->head->next);
    return;
}

template<typename T>
void DoubleLinkedList<T>::pop_back() {
    this->pop(this->tail->prev);
    return;
}

template<typename T>
void DoubleLinkedList<T>::pop(Node<T>* p) {
    if (this->empty()) {
        cerr << endl
             << "(!) Ошибка: метод pop(Node<T>* p) был вызван на пустом двусвязном списке." << endl;
        exit(1);
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    --(this->size);
    return;
}

template<typename T>
Node<T>* DoubleLinkedList<T>::find_val(T val) {
    for (Node<T>* p = this->head->next; p != this->tail; p = p->next)
        if (p->val == val)
            return p;
    return nullptr;
}

template<typename T>
Node<T>* DoubleLinkedList<T>::find_pos(int pos) {
    if (pos < 0) {
        cerr << endl
             << "(!) Ошибка: метод find_pos(int pos) был вызван с отрицательным аргументом." << endl;
        exit(1);
    }
    if (pos >= this->size) {
        cerr << endl
             << "(!) Ошибка: метод find_pos(int pos) был вызван с аргументом, не меньшим размера двусвязного списка." << endl;
        exit(1);
    }
    
    Node<T>* p = this->head->next;
    while (pos--)
        p = p->next;
    return p;
}

template<typename T>
bool DoubleLinkedList<T>::empty() {
    return this->size == 0;
}

template<typename T>
void DoubleLinkedList<T>::clear() {
    while (not this->empty())
        this->pop_back();
    return;    
}

template<typename T>
void DoubleLinkedList<T>::print() {
    for (Node<T>* p = this->head->next; p != this->tail; p = p->next)
        cout << p->val << ' ';
    cout << endl;
}



#endif
