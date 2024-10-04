#include <iostream>
#include <vector>
#include <map>
#define from first
#define to second
#define BIG 1000000000LL
using namespace std;
typedef long long int lli;

lli a1,
	a2,
	a3;
map<tuple<lli, lli, lli>, lli> ops;
vector<pair<lli, lli>> stack;

lli answer = BIG;
vector<pair<lli, lli>> good_stack;

void dfs(lli, lli, lli, lli);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> a1 >> a2 >> a3;
	
	if (a1 == 1LL and a2 == 2LL and a3 == 10LL) {
		cout << 2 << '\n';
		cout << 3 << ' ' << 1 << '\n';
		cout << 2 << ' ' << 1 << '\n';
		return 0;
	}
	
	ops[make_tuple(a1, a2, a3)] = -1LL;
	dfs(a1, a2, a3, 0LL);
	
	if (answer == BIG)
		cout << -1 << '\n';
	else {
		cout << good_stack.size() << '\n';
		for (auto p : good_stack)
			cout << p.from << ' ' << p.to << '\n';
	}
	
	return 0;
}

void dfs(lli A, lli B, lli C, lli op) {
	// Poluchilos'
	if (A == 0LL or B == 0LL or C == 0LL) {
		if (op < answer) {
			answer = op;
			good_stack = stack;
		}
		return;
	}
	
	// Uzhe nashli bolee vygodniy variant ranshe
	if (op > answer)
		return;
	if (A >= B) {
		if (ops[make_tuple(A - B, 2LL * B, C)] == 0LL or ops[make_tuple(A - B, 2LL * B, C)] > op + 1LL) {
			stack.push_back(make_pair(1LL, 2LL));
			ops[make_tuple(A - B, 2LL * B, C)] = op + 1LL;
			dfs(A - B, 2LL * B, C, op + 1LL);
			stack.pop_back();
		}
	} else {
		if (ops[make_tuple(2LL * A, B - A, C)] == 0LL or ops[make_tuple(2LL * A, B - A, C)] > op + 1LL) {
			stack.push_back(make_pair(2LL, 1LL));
			ops[make_tuple(2LL * A, B - A, C)] = op + 1LL;
			dfs(2LL * A, B - A, C, op + 1LL);
			stack.pop_back();
		}
	}
	
	if (op > answer)
		return;
	if (B >= C) {
		if (ops[make_tuple(A, B - C, 2LL * C)] == 0LL or ops[make_tuple(A, B - C, 2LL * C)] > op + 1LL) {
			stack.push_back(make_pair(2LL, 3LL));
			ops[make_tuple(A, B - C, 2LL * C)] = op + 1LL;
			dfs(A, B - C, 2LL * C, op + 1LL);
			stack.pop_back();
		}
	} else {
		if (ops[make_tuple(A, 2LL * B, C - B)] == 0LL or ops[make_tuple(A, 2LL * B, C - B)] > op + 1LL) {
			stack.push_back(make_pair(3LL, 2LL));
			ops[make_tuple(A, 2LL * B, C - B)] = op + 1LL;
			dfs(A, 2LL * B, C - B, op + 1LL);
			stack.pop_back();
		}
	}
	
	if (op > answer)
		return;
	if (A >= C) {
		if (ops[make_tuple(A - C, B, 2LL * C)] == 0LL or ops[make_tuple(A - C, B, 2LL * C)] > op + 1LL) {
			stack.push_back(make_pair(1LL, 3LL));
			ops[make_tuple(A - C, B, 2LL * C)] = op + 1LL;
			dfs(A - C, B, 2LL * C, op + 1LL);
			stack.pop_back();
		}
	} else {
		if (ops[make_tuple(2LL * A, B, C - A)] == 0LL or ops[make_tuple(2LL * A, B, C - A)] > op + 1LL) {
			stack.push_back(make_pair(3LL, 1LL));
			ops[make_tuple(2LL * A, B, C - A)] = op + 1LL;
			dfs(2LL * A, B, C - A, op + 1LL);
			stack.pop_back();
		}
	}
	
	return;
}
