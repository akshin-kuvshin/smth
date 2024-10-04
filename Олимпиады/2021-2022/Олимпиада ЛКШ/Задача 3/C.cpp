#include <iostream>
#include <vector>
#include <queue>
#define vertex first
#define length second
using namespace std;

// Constants
const int N_max = 1e5;

// Variables
int N,
	M,
	u,
	v,
	f,
	f_lengthes[N_max + 5],
	p,
	p_lengthes[N_max + 5],
	k,
	e[N_max + 5];
vector<int> graph[N_max + 5];
bool answer;

// Functions
void input();
void solution();
void output();
void get_minimal_path_lengthes(int, int*);

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cin >> f >> p >> k;
	for (int i = 0; i < k; ++i)
		cin >> e[i];
	return;
}

void solution() {
	get_minimal_path_lengthes(f, f_lengthes);
	get_minimal_path_lengthes(p, p_lengthes);
	for (int i = 0; i < k; ++i)
		if (f_lengthes[e[i]] > p_lengthes[e[i]]) { 
			answer = true;
			break;
		}
	return;
}

void output() {
	cout << (answer ? "YES" : "NO") << '\n';
	return;
}

void get_minimal_path_lengthes(int start, int *results) {
	queue<pair<int, int>> q;
	vector<bool> used(N, false);
	
	q.push(make_pair(start, 0));
	while (!q.empty()) {
		pair<int, int> from = q.front();
		q.pop();
		
		results[from.vertex] = from.length;
		
		for (int to : graph[from.vertex]) {
			if (used[to])
				continue;
			
			q.push(make_pair(to, from.length + 1));
			used[to] = true;
		}
	}
	
	return;
}
