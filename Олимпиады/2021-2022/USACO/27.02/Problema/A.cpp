#include <iostream>
using namespace std;

// Constants
const int T_max = 1e1,
		  N_max = 1e5;

// Variables
int T,
	N,
	A[N_max + 5],
	_sum,
	goal,
	_ans,
	answers[T_max + 5];

// Functions
void input();
void solution();
void output(int);
bool check();

int main() {
	// Input
	cin >> T;
	
	// Solution
	for (int _t = 0; _t < T; ++_t) {
		_sum = 0;
		_ans = 0;
		
		input();
		solution();
		output(_t);
	}
	
	// Output
	for (int _t = 0; _t < T; ++_t)
		cout << answers[_t] << '\n';
	
	return 0;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		_sum += A[i];
	}
	return;
}

void solution() {
	for (int i = N; i > 1; --i) {
		if (_sum % i)
			continue;
		
		goal = _sum / i;
		if (check()) {
			_ans = N - i;
			return;
		}
	}
	
	_ans = N - 1;
	return;
}

void output(int index) {
	answers[index] = _ans;
	return;
}

bool check() {
	int num = 0;
	for (int i = 0; i < N; ++i) {
		if (!num) {
			if (A[i] == goal)
				continue;
			else
				num = A[i];
		} else num += A[i];
		
		if (num > goal)
			return false;
		else if (num == goal)
			num = 0;
	}
	
	if (num) return false;
	return true;
}
