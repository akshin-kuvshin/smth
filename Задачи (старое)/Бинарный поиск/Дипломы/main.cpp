#include <iostream>
using namespace std;

// Variables
long long w,
		  h,
		  n,
		  answer,
		  L,
		  R,
		  mid;

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
	cin >> w >> h >> n;
	return;
}

void solution() {
	L = 1LL;
	R = max(w, h) * n;
	
	while (L != R) {
		mid = (L + R) / 2LL;
		
		if ( (mid / w) * (mid / h) >= n)
			R = mid;
		else
			L = mid + 1;
	}
	
	answer = L;
	
	return;
}

void output() {
	cout << answer << '\n';
	return;
}
