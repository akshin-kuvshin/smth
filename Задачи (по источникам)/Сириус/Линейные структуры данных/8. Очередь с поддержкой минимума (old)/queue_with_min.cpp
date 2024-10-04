#include <iostream>
#include <queue>
using namespace std;

// Вариант реализации при ограничении на положительность входящих в очередь значений
class pro_queue {
private:
    int data[1000000];
    int sz;
    int *first = data;
    int *last = data;

public:
    void push(int);
    void pop();
    int size();
    int min();
};

int N,
    a;
pro_queue super;

int minimum_in_array(int*, int*);

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a;
        
        if (a)
            super.push(a);
        else { /* a == 0 */
            if (!super.size()) {
                cout << -1 << '\n';
                continue;
            }

            // else
            cout << super.min() << '\n';
            super.pop();
        }
    }
    return 0;
}

void pro_queue::push(int number) {
    *(last++) = number;
    ++sz;
    return;
}

void pro_queue::pop() {
    ++first;
    --sz;
    return;
}

int pro_queue::size() {
    return sz;
}

int pro_queue::min() {
    return minimum_in_array(first, last);
}

int minimum_in_array(int *x, int *y) {
    int result = 10000 + 5;
    for (int *i = x; i != y; ++i)
        if (*i < result)
            result = *i;
    return result;
}
