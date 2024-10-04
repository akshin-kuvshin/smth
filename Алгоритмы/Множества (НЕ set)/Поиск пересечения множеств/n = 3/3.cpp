#include <iostream>
#include <set>
using namespace std;

// Constants
const int MAX_SIZE = 1e5,
		  N = 3;

// Variables
int sz[N + 5],
	_set[N + 5][MAX_SIZE + 5];

set<int> _union;

int _union_size,
	cross_size; // answer

// Functions
void input();
void solution();
void output();
int _union_size_of_2(int*, int, int*, int); // объединение ДВУХ
int _union_size_of_3(int*, int, int*, int, int*, int); // объединение ТРЁХ
int _cross_size_of_2(int*, int, int*, int); // пересечение ДВУХ

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	for (int i = 0; i < N; ++i) {
		cin >> sz[i];
		for (int j = 0; j < sz[i]; ++j)
			cin >> _set[i][j];
	}
	
	return;
}

void solution() {
	cross_size = _union_size_of_3(_set[0], sz[0],
								  _set[1], sz[1],
								  _set[2], sz[2]);
	cross_size -= sz[0] + sz[1] + sz[2];
	cross_size += _cross_size_of_2(_set[0], sz[0],
								   _set[1], sz[1])
				+ _cross_size_of_2(_set[1], sz[1],
								   _set[2], sz[2])
				+ _cross_size_of_2(_set[0], sz[0],
								   _set[2], sz[2]);
	
	return;
}

void output() {
	cout << cross_size << '\n';
	return;
}

int _union_size_of_2(int *_set1, int sz1, int *_set2, int sz2) {
	set<int> _union;
	
	for (int i = 0; i < sz1; ++i)
		_union.insert(_set1[i]);
	for (int j = 0; j < sz2; ++j)
		_union.insert(_set2[j]);
	
	return _union.size();
}

int _union_size_of_3(int *_set1, int sz1, int *_set2, int sz2, int *_set3, int sz3) {
	set<int> _union;
	
	for (int i = 0; i < sz1; ++i)
		_union.insert(_set1[i]);
	for (int j = 0; j < sz2; ++j)
		_union.insert(_set2[j]);
	for (int k = 0; k < sz3; ++k)
		_union.insert(_set3[k]);
	
	return _union.size();
}

int _cross_size_of_2(int *_set1, int sz1, int *_set2, int sz2) {
	return sz1 + sz2 - _union_size_of_2(_set1, sz1, _set2, sz2);
}
