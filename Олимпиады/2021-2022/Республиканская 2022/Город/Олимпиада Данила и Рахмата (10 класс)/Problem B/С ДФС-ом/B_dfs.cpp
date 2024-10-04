#include <iostream>
using namespace std;

// Constants
const int MAX_DIVIDERS_AMOUNT = 50;

// Variables
long long V,
		  dividers[MAX_DIVIDERS_AMOUNT + 5],
		  answer = -1;
int sz;
// Переменные для ДФС-а
int stack[MAX_DIVIDERS_AMOUNT + 5];
bool used[MAX_DIVIDERS_AMOUNT + 5];

// Functions
void input();
void solution();
void output();
void factorization(long long, long long*, int&);
void DFS(int);

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
	while (sz < 3)
		dividers[sz++] = 1;
	
	for (int i = 0; i < sz; ++i) {
		used[i] = true;
		for (int j = i + 1; j < sz; ++j) {
			used[j] = true;
			for (int m = j + 1; m < sz; ++m) {
				used[m] = true;
				
				stack[i] = 0;
				stack[j] = 1;
				stack[m] = 2;
				
				DFS(0);
				
				used[m] = false;
			}
			used[j] = false;
		}
		used[i] = false;
	}
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

void DFS(int k) {
	if (used[k]) {
		DFS(k + 1);
		return;
	}
	
	if (k == sz) {		
		long long nums[3] = {1, 1, 1};
		for (int i = 0; i < sz; ++i) {
			nums[stack[i]] *= dividers[i];
		}
		
		long long tmp = 2 * (nums[0] * nums[1] + nums[1] * nums[2] + nums[0] * nums[2]);
		answer = ( (answer == -1) ? tmp : min(answer, tmp));
		
		return;
	}
	
	for (int i = 0; i < 3; ++i) {
		stack[k] = i;
		DFS(k + 1);
	}
	
	return;
}
