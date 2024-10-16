// author: Danila "akshin_" Axyonov
// Идея неверная, не допёр(

#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const lli N = 11LL;
vector<lli> query[N];

lli Q;
vector<vector<lli>> A;

void solve(vector<lli>);
lli recover(vector<lli>);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int ptr = 0; ptr < (int)N; ++ptr)
        for (lli num = 0LL; num <= 2024LL; ++num)
            if (num & (1LL << ptr))
                query[ptr].pb(num);
    
    cin >> Q;
    for (int _ = 0; _ < (int)Q; ++_) {
        cout << N << endl;
        for (const vector<lli> &query_row : query) {
            for (lli query_elem : query_row)
                cout << query_elem << ' ';
            cout << endl;
        }
    }

    A.assign(Q, vector<lli>(N));
    for (int i = 0; i < (int)Q; ++i)
        for (int j = 0; j < (int)N; ++j) {
            cin >> A[i][j];
            if (A[i][j] == -1LL)
                return 0;
        }
    
    for (const vector<lli> &res : A)
        solve(res);
    
    return 0;
}

void solve(vector<lli> res) {
    lli X = recover(res);
    if (X > 2024LL)
        for (int i = (int)N - 1; i >= 0; --i)
            if (res[i]) {
                res[i] = 0LL;
                break;
            }
    X = recover(res);
    cout << X << endl;
    return;
}

lli recover(vector<lli> res) {
    lli R = 0LL;
    for (int ptr = 0; ptr < (int)N; ++ptr)
        if (res[ptr])
            R += (1LL << ptr);
    return R;
}
