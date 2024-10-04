// P.S.: дополнил уже после конца контеста. ѕрошло все тесты)))

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Constants
const int MAX_SIZE = 2e5,
		  root = 0; //  орень дерева, за которое мы подвешиваем исходный граф

// Variables
int vertex_number;
vector<int> G[MAX_SIZE + 5];
int bales[MAX_SIZE + 5];

long long full,
		  goal;

long long need[MAX_SIZE + 5];

vector<string> orders(MAX_SIZE + 5);
int top;

// Functions
void input();
void solution();
void output();
void dfs_get_needs(int, int);
void dfs_get_orders(int, int);

int main() {
	input();
	solution();
	output();
	return 0;
}

void input() {
	cin >> vertex_number;
	for (int i = 0; i < vertex_number; ++i) {
		cin >> bales[i];
		full += bales[i];
	}
	
	int u,
		v;
	for (int i = 0; i < vertex_number - 1; ++i) {
		cin >> u >> v;
		--u, --v;
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	return;
}

void solution() {
	goal = full / vertex_number;
	
	dfs_get_needs(root, root);
	dfs_get_orders(root, root);
	
	return;
}

void output() {
	cout << top << '\n';
	for (int i = 0; i < top; ++i)
		cout << orders[i] << '\n';
	return;
}

void dfs_get_needs(int node, int parent) {
	long long answer = goal - bales[node];
	
	for (int child : G[node]) {
		if (child == parent)
			continue;
		
		dfs_get_needs(child, node);
		answer += need[child];
	}
	
	need[node] = answer;
	return;
}

void dfs_get_orders(int node, int parent) {
	for (int child : G[node]) {
		if (child == parent)
			continue;
		
		if (need[child] < 0) { // должна отдать
			dfs_get_orders(child, node);
			orders[top++] = (to_string(child + 1) + " " + to_string(node + 1) + " " + to_string(-need[child]));
		} else if (need[child] == 0) { // ничего не должна
			dfs_get_orders(child, node);
		}
	} for (int child : G[node]) {
		if (child == parent)
			continue;
		
		if (need[child] > 0) { // должна получить
			orders[top++] = (to_string(node + 1) + " " + to_string(child + 1) + " " + to_string(need[child]));
			dfs_get_orders(child, node);
		}
	}
	
	return;
}
