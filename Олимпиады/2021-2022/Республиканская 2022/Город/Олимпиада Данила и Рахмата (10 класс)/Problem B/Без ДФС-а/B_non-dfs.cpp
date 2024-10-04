#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Constants
const int MAX_DIVIDERS_AMOUNT = 50;

// Variables
long long V,
		  dividers[MAX_DIVIDERS_AMOUNT + 5],
		  A,
		  B,
		  C,
		  answer;
int sz,
	q_size;
priority_queue<long long, vector<long long>, greater<long long>> q;

// Functions
void input();
void solution();
void output();
void factorization(long long, long long*, int&);

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	cin >> V;
	return;
}

void solution() {
	factorization(V, dividers, sz);
	for (int i = 0; i < sz; ++i)
		q.push(dividers[i]);
	
	q_size = q.size();
	
	while (q_size < 3) {
		q.push(1);
		++q_size;
	}
	
	while (q_size > 3) {
		long long div1 = q.top();
		q.pop();
		
		long long div2 = q.top();
		q.pop();
		
		q.push(div1 * div2);
		
		--q_size;
	}
	
	A = q.top();
	q.pop();
	B = q.top();
	q.pop();
	C = q.top();
	q.pop();
	
	answer = 2 * (A * B + B * C + A * C);
	
	return;
}

void output() {
	cout << answer << '\n';
	return;
}

void factorization(long long number, long long *divs, int &_size) {
	long long divider = 2;
	while (divider * divider <= number) {
		while (number % divider == 0) {
			divs[_size++] = divider;
			number /= divider;
		}
		++divider;
	}
	
	if (number != 1)
		divs[_size++] = number;
	return;
}
