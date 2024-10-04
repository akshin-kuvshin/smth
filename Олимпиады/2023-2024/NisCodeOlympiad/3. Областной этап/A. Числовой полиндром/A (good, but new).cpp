// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

string A,
       ans;
lli len;
bool flag;

void solve();
bool is_all_nines(const string&);
bool simple_check(const string&, lli);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> A;
    len = (lli)A.size();

    if (is_all_nines(A)) {
        ans = '1';
        for (lli _ = 0LL; _ < len; ++_)
            ans += '0';
        ans += '1';
    } else if (len % 2LL == 0LL) {
        if (not simple_check(A, len)) {
            for (lli i = len / 2LL - 1LL; i >= 0LL; --i)
                if (A[i] == '9')
                    A[i] = '0';
                else { // A[i] != '9'
                    ++A[i];
                    break;
                }
        }
        
        for (lli i = 0LL; i < len / 2LL; ++i)
            ans += A[i];
        for (lli i = len / 2LL - 1LL; i >= 0LL; --i)
            ans += A[i];
    } else { // len % 2LL == 1LL
        if (not simple_check(A, len)) {
            for (lli i = len / 2LL; i >= 0LL; --i)
                if (A[i] == '9')
                    A[i] = '0';
                else { // A[i] != '9'
                    ++A[i];
                    break;
                }
        }
        
        for (lli i = 0LL; i <= len / 2LL; ++i)
            ans += A[i];
        for (lli i = len / 2LL - 1LL; i >= 0LL; --i)
            ans += A[i];
    }
    
    cout << ans << '\n';
    return;
}

bool is_all_nines(const string &S) {
    unordered_set<char> digits;
    for (char c : S)
        digits.insert(c);
    return ((lli)digits.size() == 1LL and *digits.begin() == '9');
}

bool simple_check(const string &S, lli length) {
    for (lli i = length / 2LL - 1LL; i >= 0LL; --i)
        if (S[i] > S[length - 1LL - i])
            return true;
        else if (S[i] < S[length - 1LL - i])
            return false;
    return false; // S is palindrome
}
