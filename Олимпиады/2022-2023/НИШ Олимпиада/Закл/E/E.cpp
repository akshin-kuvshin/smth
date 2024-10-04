#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef long long int lli;

string S;
lli sz;
map<string, lli> ops;
lli answer = 1000000000LL;

void dfs(string, lli, lli);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> S;
	sz = S.size();
	
	dfs("", 0LL, 0LL);
	
	cout << answer << '\n';
	
	return 0;
}

void dfs(string str, lli _size, lli op) {
	if (_size == sz)
		if (str == S)
			answer = min(answer, op);
	
	if (_size == 0) {
		string _s = "A";
		ops[_s] = op + 1LL;
		dfs(_s, _size + 1LL, op + 1LL);
	} else if (_size == 1) {
		string _s = "AB";
		ops[_s] = op + 1LL;
		dfs(_s, _size + 1LL, op + 1LL);
	} else {
		if (op > answer) return;
		string _s = str + (char)('A' + str.size());
		if (_size + 1LL <= sz)
			if (ops[_s] == 0LL or ops[_s] > op + 1LL) {
				ops[_s] = op + 1LL;
				dfs(_s, _size + 1LL, op + 1LL);
			}
		
		if (op > answer) return;
		_s = str;
		swap(_s[0], _s[1]);
		if (ops[_s] == 0LL or ops[_s] > op + 1LL) {
			ops[_s] = op + 1LL;
			dfs(_s, _size, op + 1LL);
		}
		
		if (op > answer) return;
		_s = str;
		char c = _s[0];
		_s.erase(0, 1);
		_s.push_back(c);
		if (ops[_s] == 0LL or ops[_s] > op + 1LL) {
			ops[_s] = op + 1LL;
			dfs(_s, _size, op + 1LL);
		}
	}
	
	return;
}
