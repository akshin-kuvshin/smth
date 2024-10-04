// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef long long int lli;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const string ascii_lowercase = "abcdefghijklmnopqrstuvwxyz";

string S;

map<char, lli> letters_cnt;
vector<set<char>> odd_letters_on_pref;

map<pair<set<char>, bool>, lli> distinct_prefs_cnt;
set<char> without_c;
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

    odd_letters_on_pref.pb(set<char>());
    for (char c : S) {
        ++letters_cnt[c];
        odd_letters_on_pref.pb(set<char>());
        for (char _c : ascii_lowercase)
            if (letters_cnt[_c] % 2LL == 1LL)
                odd_letters_on_pref.back().insert(_c);
    }

    for (set<char> odd_letters : odd_letters_on_pref) {
        ans += distinct_prefs_cnt[mp(odd_letters, false)] + distinct_prefs_cnt[mp(odd_letters, true)];
        ++distinct_prefs_cnt[mp(odd_letters, false)];

        for (char c : odd_letters) {
            without_c = odd_letters;
            without_c.erase(c);
            ans += distinct_prefs_cnt[mp(without_c, false)];
            ++distinct_prefs_cnt[mp(without_c, true)];
        }
    }
    
    cout << ans << '\n';
    return;
}
