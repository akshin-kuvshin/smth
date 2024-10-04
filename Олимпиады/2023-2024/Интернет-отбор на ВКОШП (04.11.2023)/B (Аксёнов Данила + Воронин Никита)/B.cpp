#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> dot;

const lli N = 10LL;

char field[N + 5LL][N + 5LL];
bool used[N + 5LL][N + 5LL];
vector<vector<dot>> comps;
lli cnt[5];

void solve();
void dfs(lli, lli, lli);
bool check_for_const_x(vector<dot>&);
bool check_for_const_y(vector<dot>&);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve();
	
	return 0;
}

void solve() {
	for (int i = 0; i <= (int)N + 1; ++i)
		for (int j = 0; j <= (int)N + 1; ++j) {
			if (1 <= i and i <= (int)N and 1 <= j and j <= (int)N)
				cin >> field[i][j];
			else
				field[i][j] = '.';
		}
	
	for (int i = 1; i <= (int)N; ++i)
		for (int j = 1; j <= (int)N; ++j) {
			if (field[i][j] == '#' and !used[i][j]) {
				comps.push_back(vector<dot>());
				lli ind = (lli)comps.size() - 1LL;
				dfs((lli)i, (lli)j, ind);
			}
		}
	
	// Первое условие
	if ((lli)comps.size() != 10LL) {
		cout << "NO\n";
		return;
	}
	
	// Второе условие
	for (vector<dot> comp : comps) {
		lli sz = (lli)comp.size();
		if (sz > 4LL) {
			cout << "NO\n";
			return;
		}
		++cnt[sz];
	}
	if (cnt[1] != 4LL or cnt[2] != 3LL or cnt[3] != 2LL or cnt[4] != 1LL) {
		cout << "NO\n";
		return;
	}
	
	// Третье условие
	for (vector<dot> comp : comps)
		if (!check_for_const_x(comp) and !check_for_const_y(comp)) {
			cout << "NO\n";
			return;
		}
	
	// Четвёртое условие
	for (int i = 2; i <= (int)N - 1; ++i)
		for (int j = 2; j <= (int)N - 1; ++j) {
			if (field[i][j] != '#')
				continue;
			
			if (field[i - 1][j - 1] == '#' or field[i - 1][j + 1] == '#' or field[i + 1][j - 1] == '#' or field[i + 1][j + 1] == '#') {
				cout << "NO\n";
				return;
			}
		}
	
	cout << "YES\n";
	return;
}

void dfs(lli x, lli y, lli ind) {
	comps[ind].push_back(make_pair(x, y));
	used[x][y] = true;
	
	if (field[x - 1LL][y] == '#' and !used[x - 1LL][y])
		dfs(x - 1LL, y, ind);
	else if (field[x + 1LL][y] == '#' and !used[x + 1LL][y])
		dfs(x + 1LL, y, ind);
	else if (field[x][y - 1LL] == '#' and !used[x][y - 1LL])
		dfs(x, y - 1LL, ind);
	else if (field[x][y + 1LL] == '#' and !used[x][y + 1LL])
		dfs(x, y + 1LL, ind);
	
	return;
}

bool check_for_const_x(vector<dot> &comp) {
	lli x = comp[0].first;
	for (dot cur : comp)
		if (cur.first != x)
			return false;
	return true;
}

bool check_for_const_y(vector<dot> &comp) {
	lli y = comp[0].second;
	for (dot cur : comp)
		if (cur.second != y)
			return false;
	return true;
}
