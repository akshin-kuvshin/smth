#include <iostream>
using namespace std;

// Variables
int N;

// Functions
void input();
void solution();
void output();

int main() {
	// Input
	cin >> N;
	
	// Output
	for (int i = 0; i < N; ++i)
		cout << ' ' << i + 1 << "  ";
	cout << '\n';
	
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < N; ++j)
			cout << "/_\\ ";
		cout << '\n';
	}
	
	for (int i = 0; i < N; ++i)
		cout << "| | ";
	cout << '\n';
	
	return 0;
}
