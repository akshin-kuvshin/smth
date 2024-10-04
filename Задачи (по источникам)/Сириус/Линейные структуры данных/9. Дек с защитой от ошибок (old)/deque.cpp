#include <iostream>
#include <string>
using namespace std;

class deque {
private:
    int data[2000000];
    int sz;
    int begin; /* begin и end - индексы */
    int end;

public:
    // конструктор
    deque() {
        begin = end = 1000000;
        sz = 0;
    }

    void push_front(int);
    void push_back(int);
    void pop_front();
    void pop_back();
    int front();
    int back();
    int size();
    void clear();
};

int tmp;
string S;
deque my_deque;
bool is_end;

int main() {
    while (!is_end) {
        cin >> S;

        if (S == "push_front") {
            cin >> tmp;
            my_deque.push_front(tmp);

            cout << "ok\n";
        } else if (S == "push_back") {
            cin >> tmp;
            my_deque.push_back(tmp);

            cout << "ok\n";
        } else if (S == "pop_front") {
            if (!my_deque.size()) {
                cout << "error\n";
                continue;
            }

            cout << my_deque.front() << '\n';
            my_deque.pop_front();
        } else if (S == "pop_back") {
            if (!my_deque.size()) {
                cout << "error\n";
                continue;
            }

            cout << my_deque.back() << '\n';
            my_deque.pop_back();
        } else if (S == "front") {
            if (!my_deque.size()) {
                cout << "error\n";
                continue;
            }

            cout << my_deque.front() << '\n';
        } else if (S == "back") {
            if (!my_deque.size()) {
                cout << "error\n";
                continue;
            }

            cout << my_deque.back() << '\n';
        } else if (S == "size")
            cout << my_deque.size() << '\n';
        else if (S == "clear") {
            my_deque.clear();
            cout << "ok\n";
        } else { // S == "exit"
            cout << "bye\n";
            is_end = true;
        }
    }

    return 0;
}

void deque::push_front(int num) {
    data[--begin] = num;
    ++sz;
    return;
}

void deque::push_back(int num) {
    data[end++] = num;
    ++sz;
    return;
}

void deque::pop_front() {
    ++begin;
    --sz;
    return;
}

void deque::pop_back() {
    --end;
    --sz;
    return;
}

int deque::front() {
    return data[begin];
}

int deque::back() {
    return data[end - 1];
}

int deque::size() {
    return sz;
}

void deque::clear() {
    begin = end = 1000000;
    sz = 0;
    return;
}
