// author: Danila "akshin_" Axyonov

#include <iostream>
#include <string>
#include <vector>
using namespace std;
using lli = long long int;

const string letters = "abcde";

void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	lli Q;
	cin >> Q;
	while (Q--)
		solve();
	
	return 0;
}

void solve() {
	string S;
	cin >> S;
    lli sz = (lli)S.size();
    for (int i = 0; i < (int)sz; ++i)
        S[i] = letters[((int)(S[i] - 'a') + (i + 1)) % 5];
    cout << S << '\n';
	return;
}
