#include <iostream>
#include <string>
using namespace std;

class queue {
private:
    int data[1000000];
    int sz;
    int first; // first и last - индексы
    int last;

public:
    void push(int);
    void pop();
    int front();
    int size();
    void clear();
};

int tmp;
string S;
queue my_queue;
bool is_end;

int main() {
    is_end = true;
    while (is_end) {
        cin >> S;

        if (S == "push") {
            cin >> tmp;
            my_queue.push(tmp);
            cout << "ok\n";
        } else if (S == "pop")
            if (my_queue.size()) {
                cout << my_queue.front() << '\n';
                my_queue.pop();
            } else // очередь пуста
                cout << "error\n";
        else if (S == "front")
            if (my_queue.size())
                cout << my_queue.front() << '\n';
            else // очередь пуста
                cout << "error\n";
        else if (S == "size")
            cout << my_queue.size() << '\n';
        else if (S == "clear") {
            my_queue.clear();
            cout << "ok\n";
        } else { /* S == "exit" */
            is_end = false;
            cout << "bye\n";
        }
    }

    return 0;
}

void queue::push(int number) {
    data[last++] = number;
    ++sz;
    return;
}

void queue::pop() {
    ++first;
    --sz;
    return;
}

int queue::front() {
    return data[first];
}

int queue::size() {
    return sz;
}

void queue::clear() {
    first = last = 0;
    sz = 0;
    return;
}
