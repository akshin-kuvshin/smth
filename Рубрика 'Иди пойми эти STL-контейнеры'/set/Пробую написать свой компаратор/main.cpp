#include <iostream>
#include <set>
#include <string>
using namespace std;

// Structures
struct Comparator {
	// Обязательно, чтобы принимаемые параметры были константными, в противном
	// случае компилятор начинает сильно ругаться и материться.
	bool operator() (const string &S1, const string &S2) {
		return S1.length() < S2.length();
	}
};

// Constants
const int N_max = 1e2;

// Variables
int N;
string A[N_max + 5];
multiset<string, Comparator> my_set;

// Здесь использую multiset, потому что две разные строки одинаковой длины
// считаются за одну (т.к. сортировка ведётся по длинам строк), и чтобы, например,
// обе строки "yana" и "maks" могли попасть в структуру.
int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	
	for (int i = 0; i < N; ++i)
		my_set.insert(A[i]);
	
	for (multiset<string>::iterator it = my_set.begin(); it != my_set.end(); ++it)
		cout << *it << ' ';
	cout << '\n';
	
	return 0;
}
