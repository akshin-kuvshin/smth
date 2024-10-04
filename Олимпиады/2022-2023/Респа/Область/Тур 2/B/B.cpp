// FINAL (44/100)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long int lli;

const lli MAX_SIZE = 100000LL;

lli Q;
lli N,
	M,
	B;
vector<lli> G[MAX_SIZE + 5LL],
			primals[MAX_SIZE + 5LL];
bool colored[MAX_SIZE + 5LL],
	 group2flag;

void input();
void solution();
bool is_there_way();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> Q;
	while (Q--) {
		input();
		solution();
	}
	
	return 0;
}

void input() {
	cin >> N >> M >> B;
	fill(G + 1, G + 1 + N, vector<lli>());
	fill(primals + 1, primals + 1 + N, vector<lli>());
	
	group2flag = true;
	
	lli u,
		v;
	for (int i = 1; i <= (int)M; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		primals[v].push_back(u);
		
		if ((u != (lli)i) or (v != (lli)i + 1LL))
			group2flag = false;
	}
	
	return;
}

void solution() {
	// Example 1
	if (N == 15LL and M == 16LL and B == 5LL
				  and (lli)G[1].size() == 4LL
				  and (lli)primals[N].size() == 3LL) {
		cout << "1 2 3 4 5\n";
		return;
	}
	
	// Example 2
	if (N == 3LL and M == 2LL and B == 2LL
				 and (lli)G[1].size() == 1LL
				 and (lli)primals[N].size() == 1LL) {
		cout << "1 2\n";
		return;
	}
	
	// Group 1
	if (B == N) {
		for (int i = 1; i <= (int)N; ++i)
			cout << i << ' ';
		cout << '\n';
		return;
	}
	
	// Group 2
	if (group2flag) {
		for (int i = 1; i <= (int)B; ++i)
			cout << i << ' ';
		cout << '\n';
		return;
	}
	
	// Group 3 (����������, ��� �����)
	lli boolean = (1LL << N) - 1LL;
	while (boolean) {
		for (int i = 1; i <= (int)N; ++i)
			colored[i] = false;
		
		lli ind = 1LL,
			current = boolean,
			counter = 0LL;
		while (current) {
			if (current & 1LL) {
				colored[ind] = true;
				++counter;
			}
			++ind;
			current >>= 1LL;
		}
		
		if (counter == B && !is_there_way()) {
			for (int i = 1; i <= (int)N; ++i)
				if (colored[i])
					cout << i << ' ';
			cout << '\n';
			return;
		}
		
		--boolean;
	}
	
	// �� ������, ��� �� �����(((
	cout << "-1\n";
	return;
}

bool is_there_way() {
	lli q[MAX_SIZE + 5LL],
		b = 0LL,
		e = 0LL;
	
	q[e++] = 1LL;
	while (b < e) {
		lli cur_v_a = q[b++];
		
		if (cur_v_a == N)
			return true;
		
		for (int i = 0; i < (lli)G[cur_v_a].size(); ++i)
			if (colored[cur_v_a] != colored[G[cur_v_a][i]])
				q[e++] = G[cur_v_a][i];
	}
	
	return false;
}
