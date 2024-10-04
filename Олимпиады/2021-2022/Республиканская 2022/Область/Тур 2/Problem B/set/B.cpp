// DONE
#include <iostream>
#include <vector>
#include <set>

#define conviction first
#define vertex second

using namespace std;

// Constants
const int MAX_SIZE = 2e5;

// Variables
int N,
	M,
	c[MAX_SIZE + 5],
	general_c,
	v1,
	v2,
	answer;
vector<int> graph[MAX_SIZE + 5];
set<pair<int, int>> collection;
set<pair<int, int>>::iterator it;
bool used[MAX_SIZE + 5];

// Functions
void input();
void solution();
void output();
void add_friends_to_set(int);

int main() {
	input();
	solution();
	output();
	
	return 0;
}

void input() {
	cin >> N >> M;
	
	for (int i = 0; i < M; ++i) {
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	
	for (int i = 1; i <= N; ++i)
		cin >> c[i];
	
	return;
}

void solution() {
	/* Отдельно обрабатываем первую вершину,
	   которая у нас есть с начала. */
	general_c = c[1];
	answer = 1;
	used[1] = true;
	add_friends_to_set(1);
	
	while (!collection.empty()) {
		it = collection.begin();
		
		if (it->conviction <= general_c) {
			general_c += it->conviction;
			++answer;
			
			int current = it->vertex;
			collection.erase(it);
			add_friends_to_set(current);
		} else break;
	}
	
	return;
}

void output() {
	cout << answer << '\n';
	return;
}

void add_friends_to_set(int primal) {
	int _sz = graph[primal].size();
	for (int i = 0; i < _sz; ++i) {
		int v = graph[primal][i];
		if (!used[v]) {
			collection.insert(make_pair(c[v], v));
			used[v] = true;
		}
	}
	return;
}
