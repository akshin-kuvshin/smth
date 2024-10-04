#include <iostream>
#include <vector>
#define vertex first
#define weight second
using namespace std;

typedef vector<pair<int, int>>::iterator it;

const int N_max = 1e6;

int V;
vector<pair<int, int>> G[N_max + 5];
int E,
	v1,
	v2,
	w;
int start,
	finish;

int lengthes[N_max + 5];
bool used[N_max + 5];

int q[N_max + 5],
	l,
	r;

int main() {
	cin >> V;
	cin >> E;
	for (int i = 0; i < E; ++i) {
		cin >> v1 >> v2 >> w;
		G[v1].push_back(make_pair(v2, w));
		G[v2].push_back(make_pair(v1, w));
	}
	cin >> start >> finish;
	
	q[r++] = start;
	used[start] = true;
	lengthes[start] = 0;
	
	int current;
	while (l < r) {
		current = q[l++];
		for (it i = G[current].begin(); i != G[current].end(); ++i) {
			if (!used[i->vertex]) {
				used[i->vertex] = true;
				lengthes[i->vertex] = lengthes[current] + i->weight;
				q[r++] = i->vertex;
			} else if (lengthes[i->vertex] > lengthes[current] + i->weight) { // уже были, но надо проверить: вдруг новый путь будет короче
				lengthes[i->vertex] = lengthes[current] + i->weight;
				q[r++] = i->vertex;
			}
		}
	}
	
	cout << lengthes[finish];
	
	return 0;
}
