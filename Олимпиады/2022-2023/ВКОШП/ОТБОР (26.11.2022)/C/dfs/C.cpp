#include <iostream>
#define END -1LL
using namespace std;

typedef long long int lli;

// Constants
const lli N_max = 16LL;

// Variables
lli N,
	A[N_max + 5LL],
	_sum,
	answer;

// Functions
void input();
void solution();
void output();
void dfs(lli, lli, lli);

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	cin >> N;
	for (lli i = 0LL; i < N; ++i) {
		cin >> A[i];
		_sum += A[i];
	}
	return;
}

void solution() {
	answer = _sum;
	dfs(N - 1LL, 0LL, 0LL);
	return;
}

void output() {
	cout << answer << '\n';
	return;
}

void dfs(lli current_region, lli b1, lli b2) {
	if (current_region == END) {
		if (b1 == b2)
			answer = min(answer, _sum - b1 - b2);
		return;
	}
	
	dfs(current_region - 1LL, b1, b2);
	dfs(current_region - 1LL, b1 + A[current_region], b2);
	dfs(current_region - 1LL, b1, b2 + A[current_region]);
	return;
}
