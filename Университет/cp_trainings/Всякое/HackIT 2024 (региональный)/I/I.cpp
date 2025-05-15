// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
using lli = long long int;

#define plli                pair<lli, lli>
#define mp(_first, _second) make_pair(_first, _second)
#define pb(_elem)           push_back(_elem)

const string B = "the_most_mazafaka_beginning",
             E = "the_most_mazafaka_end";

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

void solve() {
    unordered_map<string, string> prev,
                                  next;
    prev[B] = ""; next[B] = "Aaron";
    prev["Aaron"] = B; next["Aaron"] = E;
    prev[E] = "Aaron"; next[E] = "";

    lli q;
    cin >> q;
    while (q--) {
        string tmp;
        cin >> tmp;

        if (tmp != "leave") {
            string name1 = tmp,
                   where,
                   name2;
            cin >> where >> name2;

            if (where == "before")
                name2 = prev[name2];
            
            prev[name1] = name2; next[name1] = next[name2];
            next[prev[name1]] = name1; prev[next[name1]] = name1;
        } else {
            string name;
            cin >> name;
            next[prev[name]] = next[name];
            prev[next[name]] = prev[name];
            prev.erase(name); next.erase(name);
        }
    }

    for (string name = next[B]; name != E; name = next[name])
        cout << name << '\n';
        
    return;
}
