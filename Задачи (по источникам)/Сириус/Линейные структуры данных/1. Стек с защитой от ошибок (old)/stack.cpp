#include <iostream>
#include <string>
using namespace std;

class stack {
private:
    int data[1000000];
    int sz;

public:
    void push(int);
    void pop();
    int back();
    int size();
    void clear();
};

int tmp;
string S;

stack myStack;

int main() {
    while (true) {
        cin >> S;

        if (S == "push") {
            cin >> tmp;
            myStack.push(tmp);
            cout << "ok\n";
        } else if (S == "pop") {
            if (!myStack.size()) cout << "error\n";
            else {
                cout << myStack.back() << '\n';
                myStack.pop();
            }
        } else if (S == "back") {
            if (!myStack.size()) cout << "error\n";
            else cout << myStack.back() << '\n';
        } else if (S == "size") {
            cout << myStack.size() << '\n';
        } else if (S == "clear") {
            myStack.clear();
            cout << "ok\n";
        } else { // S == "exit"
            cout << "bye\n";
            break;
        }
    }

    return 0;
}

void stack::push(int num) {
    data[sz++] = num;
    return;
}

void stack::pop() {
    --sz;
    return;
}

int stack::back() {
    return data[sz - 1];
}

int stack::size() {
    return sz;
}

void stack::clear() {
    sz = 0;
    return;
}
