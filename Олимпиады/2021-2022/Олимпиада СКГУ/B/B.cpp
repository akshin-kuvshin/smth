#include <iostream>
using namespace std;

// Variables
int N,
	A,
	B,
	three_packs_amount,
	d,
	answer;

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
	cin >> N >> A >> B;
	return;
}

void solution() {
	three_packs_amount = N / 3;
	
	int counter;
	while (A or B) {
		counter = 0;
		
		if (B < three_packs_amount) {
			counter += 3 * B;
			B = 0;
		} else {
			counter += 3 * three_packs_amount;
			B -= three_packs_amount;
		}
		
		if (counter == N) {
			++answer;
			continue;
		}
		
		d = N - counter;
		if (A < d) {
			counter += A;
			A = 0;
		} else {
			counter += d;
			A -= d;
			++answer;
			continue;
		}
		
		if (counter != N)
			break;
	}
	
	return;
}

void output() {
	cout << answer << '\n';
	return;
}

