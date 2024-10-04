// FINAL (20/100)

#include <iostream>
#include <vector>
#define dot pair<lli, lli>
#define x first
#define y second
using namespace std;

typedef long long int lli;

const lli MAX_SIZE = 100000LL,
		  d = 1000000007LL;

lli N;
dot A[MAX_SIZE + 5LL];
lli boolean,
	current,
	ind;
vector<lli> indexes;
lli answer;

lli get_ans(const vector<lli>&);
lli _abs(lli);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N;
	for (int i = 0; i < (int)N; ++i)
		cin >> A[i].x >> A[i].y;
	
	boolean = (1LL << N) - 1LL;
	while (boolean) {
		current = boolean;
		ind = 0LL;
		indexes.clear();
		
		while (current) {
			if (current & 1LL)
				indexes.push_back(ind);
			current >>= 1LL;
			++ind;
		}
		
		answer += get_ans(indexes);
		answer %= d;
		
		--boolean;
	}
	
	cout << answer << '\n';
	return 0;
}

lli get_ans(const vector<lli> &_indexes) {
	lli min_x = A[_indexes[0]].x,
		max_x = A[_indexes[0]].x,
		min_y = A[_indexes[0]].y,
		max_y = A[_indexes[0]].y;
	
	for (int i = 1; i < (int)_indexes.size(); ++i) {
		min_x = min(min_x, A[indexes[i]].x);
		max_x = max(max_x, A[indexes[i]].x);
		min_y = min(min_y, A[indexes[i]].y);
		max_y = max(max_y, A[indexes[i]].y);
	}
	
	return _abs((max_x - min_x) * (max_y - min_y)) % d;
}

lli _abs(lli num) {
	if (num < 0LL) return -num;
	return num;
}
