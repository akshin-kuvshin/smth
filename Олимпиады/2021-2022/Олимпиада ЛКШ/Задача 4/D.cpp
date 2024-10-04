#include <iostream>
using namespace std;

// Constants
const int MAX_SIZE = 1e5;

// Variables
int N,
	A[MAX_SIZE + 5],
	K,
	B[MAX_SIZE + 5];
long long answer;

// Functions
void input();
void solution();
void output();
int comparator(const void*, const void*);

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	cin >> K;
	for (int i = 0; i < K; ++i)
		cin >> B[i];
	return;
}

void solution() {
	qsort(A, N, sizeof(int), comparator);
	qsort(B, K, sizeof(int), comparator);
	
	int i = 0,
		j = 0;
	while ( (i < N) and (j < K) ) {
		if (A[i] < B[j]) {
			++j;
			continue;
		}
		
		answer += B[j];
		++i;
		++j;
	}
	
	return;
}

void output() {
	cout << answer << '\n';
	return;
}

int comparator(const void *p1, const void *p2) {
	int num1 = *(int*)p1,
		num2 = *(int*)p2;
	
	if (num1 < num2) return 1;
	if (num1 == num2) return 0;
	return -1;
}
