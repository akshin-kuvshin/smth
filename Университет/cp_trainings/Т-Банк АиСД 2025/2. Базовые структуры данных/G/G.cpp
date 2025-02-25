// author: Danila "akshin_" Axyonov

#include <iostream>
#include <deque>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

class goblin_queue {
private:
    deque<lli> first_half,
               second_half;
    
    bool is_good() {
        return (
            (first_half.size() == second_half.size()) or
            ((lli)first_half.size() == (lli)second_half.size() + 1LL)
        );
    }

    void update() {
        while (not is_good())
            if (first_half.size() > second_half.size()) {
                lli id = first_half.back();
                first_half.pop_back();
                second_half.push_front(id);
            } else {
                lli id = second_half.front();
                second_half.pop_front();
                first_half.push_back(id);
            }
        return;
    }

public:
    void push(lli id, bool premium) {
        if (premium)
            first_half.push_back(id);
        else // not premium
            second_half.push_back(id);
        update();
        return;
    }

    lli front() {
        return first_half.front();
    }

    void pop() {
        first_half.pop_front();
        update();
        return;
    }
};

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    lli n;
    cin >> n;
    
    goblin_queue q;
    while (n--) {
        char cmd;
        cin >> cmd;
        if (cmd == '+') {
            lli id;
            cin >> id;
            q.push(id, false);
        } else if (cmd == '*') {
            lli id;
            cin >> id;
            q.push(id, true);
        } else { // cmd == '-'
            cout << q.front() << '\n';
            q.pop();
        }
    }
    
    return;
}
