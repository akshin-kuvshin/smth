#include <iostream>
using namespace std;

// Constants
const int T_max = 1e2,
		  N_max = 1e5;

// Variables
long long T,
		  N,
		  h[N_max + 5],
		  _ans,
		  answers[T_max + 5],
		  d;

// Functions
void input();
void solution();
void output(int);

int main() {
	// Input
	cin >> T;
	
	// Solution
	for (int _t = 0; _t < T; ++_t) {
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
	for (int i = 0; i < N; ++i)
		cin >> h[i];
	return;
}

void solution() {
	_ans = 0;
	
	if (N == 1) {
		_ans = 0;
		return;
	}
	
	for (int i = 1; i <= N - 2; ++i) { // от второго до предпоследнего
		if (h[i - 1] < h[i]) {
			d = h[i] - h[i - 1];
			
			_ans += 2 * d;
			h[i] = h[i - 1];
			h[i + 1] -= d;
		}
	}
	
	if (h[N - 2] < h[N - 1]) {
		_ans = -1;
		return;
	}
	
	for (int i = N - 2; i >= 1; --i) { // в обратном пор€дке
		if (h[i + 1] < h[i]) {
			d = h[i] - h[i + 1];
			
			_ans += 2 * d;
			h[i] = h[i + 1];
			h[i - 1] -= d;
		}
	}
	
	if ( (h[0] < 0) or (h[1] < h[0]) )
		_ans = -1;
	
	return;
}

void output(int index) {
	answers[index] = _ans;
	return;
}
