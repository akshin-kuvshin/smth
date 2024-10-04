// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

string S;
string vowels = "aeiou";
lli ans;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    getline(cin, S);
    for (char c : S)
        for (char vowel : vowels)
            if (c == vowel) {
                ++ans;
                break;
            }
    cout << ans << '\n';
    return;
}
