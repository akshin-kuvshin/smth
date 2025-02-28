// author: Danila "akshin_" Axyonov

#include <iostream>
#include <deque>
#include <unordered_map>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    deque<lli> d;
    unordered_map<lli, lli> front_cnt;
    lli leaved = 0LL;

    lli _q;
    cin >> _q;
    while (_q--) {
        lli cmd;
        cin >> cmd;
        switch (cmd) {
        case 1LL:
            lli id;
            cin >> id;
            front_cnt[id] = (lli)d.size() + leaved;
            d.push_back(id);
            break;
        
        case 2LL:
            d.pop_front();
            ++leaved;
            break;
        
        case 3LL:
            d.pop_back();
            break;
        
        case 4LL:
            lli q;
            cin >> q;
            cout << (front_cnt[q] - leaved) << '\n';
            break;
        
        case 5LL:
            cout << d.front() << '\n';
            break;
        
        default:
            cout << "error, mazafaka\n";
        }
    }
    return;
}
