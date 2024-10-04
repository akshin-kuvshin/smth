#include <iostream>
using namespace std;

// Variables
int s,
	d,
	k;

// Functions
void input();
void solution();
void output();

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	cin >> s >> d >> k;
	return;
}

void solution() {
	for (int i = 0; i < k; ++i) {
		if (i == k - 1) {
			if (s % d)
				s += s % d;
			else
				++s;
			continue;
		}
		
		if (s % d == d - 1)
			s += s % d;
		else
			++s;
	}
	return;
}

void output() {
	cout << s << '\n';
	return;
}
