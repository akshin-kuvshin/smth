// COMPLETED

#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;

// Constants
const int N_max = 1e5;

// Variables
int N,
	A[N_max + 5],
	maxs_from_begin[N_max + 5],
	edges_size,
	new_edges[N_max + 5],
	new_top,
	_ans;
bool is_first = true;
vector<int> edges;

// Functions
void input();
void solution();
void output();
void get_start_edges();
void delete_wrong_edges();
int subarray_min(int, int);
int subarray_max(int, int);
void get_new_edges(int, int);

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		
		if (is_first) {
			maxs_from_begin[0] = A[0];
			is_first = false;
			continue;
		}
		
		maxs_from_begin[i] = max(maxs_from_begin[i - 1], A[i]);
	}
//	return;
}

void solution() {
	get_start_edges();
	delete_wrong_edges();
	
	edges_size = edges.size();
	
	/* cout << edges_size << '\n';
	for (int i = 0; i < edges_size; ++i)
		cout << edges[i] << ' ';
	cout << "\n\n"; */
	
	new_edges[new_top++] = 0;
	for (int i = 0; i < edges_size - 1; ++i)
		get_new_edges(edges[i], edges[i + 1]);
	
	_ans = new_top - 1;
	
	return;
}

void output() {
	/* cout << new_top << '\n';
	
	sort(new_edges, new_edges + new_top);
	for (int i = 0; i < new_top; ++i)
		cout << new_edges[i] << ' ';
	cout << '\n'; */
	
	cout << _ans << '\n';
	
//	return;
}

void get_start_edges() {
	edges.push_back(0);
	for (int i = 1; i < N; ++i)
		if (maxs_from_begin[i - 1] != maxs_from_begin[i])
			edges.push_back(i);
	edges.push_back(N);
//	return;
}

void delete_wrong_edges() {
	edges_size = edges.size();
	for (int i = 0; i < edges_size - 2;) {
		/* if (edges[i] == -1)
			continue; */
		
		if (subarray_max(edges[i], edges[i + 1]) > subarray_min(edges[i + 1], edges[i + 2])) {
			edges.erase(edges.begin() + i + 1);
			--edges_size;
			
			if (i) --i;
		} else ++i;
	}
	return;
}

int subarray_min(int begin, int end) {
	int _min = A[begin];
	for (int i = begin + 1; i < end; ++i)
		_min = min(_min, A[i]);
	return _min;
}

int subarray_max(int begin, int end) {
	int _max = A[begin];
	for (int i = begin + 1; i < end; ++i)
		_max = max(_max, A[i]);
	return _max;
}

void get_new_edges(int start, int finish) {
	int _max = subarray_max(start, finish);
	
	new_edges[new_top++] = finish;
	for (int i = finish - 1; i > start; --i) {
		if (A[i] != _max)
			return;
		new_edges[new_top++] = i;
	}
	
	return;
}
