#include <iostream>
#include <string>
using namespace std;
typedef long long int lli;

string S;
lli sz;
bool is_word;
lli counter;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	getline(cin, S);
	sz = (lli)S.size();
	
	for (int i = 0; i < (int)sz; ++i) {
		if (is_word) {
			if (S[i] == ' ') {
				is_word = false;
			}
		} else {
			if (S[i] != ' ') {
				is_word = true;
				++counter;
			}
		}
	}
	
	cout << counter << '\n';
	
	return 0;
}
