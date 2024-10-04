#include <iostream>
using namespace std;

// Variables
int N,
	answer = 0,
	_pow = 1;

int main() {
	cin >> N;
	for (; _pow < N; answer++, _pow *= 2);
	cout << answer;
	
	return 0;
}
