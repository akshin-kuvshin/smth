#include <iostream>
#include <set>
using namespace std;

// Constants
const int N_max = 1e2;

// Variables
int N,
	A[N_max + 5];
set<int> my_set;

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	
	for (int i = 0; i < N; ++i)
		my_set.insert(A[i]);
	
	for (auto it = my_set.begin(); it != my_set.end(); ++it) {
		cout << *it << ' ';
		my_set.erase(it);
	}
	cout << '\n';
	
	return 0;
}
