#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// Structures
struct Comparator {
	bool operator() (const string &S1, const string &S2) {
		return S1.size() > S2.size();
	}
};

// Constants
const int N_max = 1e2;

// Variables
int N;
string A[N_max + 5];
priority_queue<string, vector<string>, Comparator> q;

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	
	for (int i = 0; i < N; ++i)
		q.push(A[i]);
	cout << '\n';
	
	while (!q.empty()) {
		cout << q.top() << '\n';
		q.pop();
	}
	
	return 0;
}
