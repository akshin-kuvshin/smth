#include <iostream>
using namespace std;

int a, b, c, d, res;

void input() {
	cin >> a >> b >> c >> d;
}

void sol() {
	res = min(a, c) * min(b, d);
}

void output() {
	cout << res << "\n";
}

int main() {
	input();
	sol();
	output();
	return 0;
}