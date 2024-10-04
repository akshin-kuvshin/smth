#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef long long int lli;

// Constants
const lli MAX_SETS_NUMBER = 100LL,
		  MAX_SET_POWER = 1000LL;

// Variables
lli N,
	sizes[MAX_SETS_NUMBER + 5LL],
	sets[MAX_SETS_NUMBER + 5LL][MAX_SET_POWER + 5LL],
	answer;

// Functions
void input();
lli get_cross_size(const vector<lli>&);
lli get_union_size(const vector<lli>&);

int main() {
	input();

	vector<lli> indexes;
	for (lli i = 0LL; i < N; ++i)
		indexes.push_back(i);
	answer = get_cross_size(indexes);

	cout << answer << '\n';
	return 0;
}

void input() {
	cin >> N;
	for (lli s = 0LL; s < N; ++s) {
		cin >> sizes[s];
		for (lli i = 0LL; i < sizes[s]; ++i)
			cin >> sets[s][i];
	}
	return;
}

lli get_cross_size(const vector<lli> &indexes) {
    if ((lli)indexes.size() == 0LL)
		return 0LL;
	if ((lli)indexes.size() == 1LL)
		return sizes[indexes[0LL]];

	// Решаем задачу для случая indexes.size() % 2 == 1 (нечётное кол-во).
	// В противном случае в конце умножим всё на -1.
	lli cross_size = 0LL;
	cross_size += get_union_size(indexes);

	vector<lli> new_indexes;
	lli max_boolean = ((1LL << indexes.size()) - 1LL);
	for (lli boolean = 1LL; boolean < max_boolean; ++boolean) {
		new_indexes.clear();

		lli current = boolean,
			ind = 0LL;
		while (current) {
			if (current & 1LL)
				new_indexes.push_back(ind);
			current >>= 1LL;
			++ind;
		}

		if (new_indexes.size() % 2LL == 0LL)
			cross_size += get_cross_size(new_indexes);
		else
			cross_size -= get_cross_size(new_indexes);
	}

	if (indexes.size() % 2LL == 0LL)
		cross_size = -cross_size;
	return cross_size;
}

lli get_union_size(const vector<lli> &indexes) {
	set<lli> _union;
	for (lli s : indexes) {
		for (lli i = 0LL; i < sizes[s]; ++i)
			_union.insert(sets[s][i]);
	}
	return _union.size();
}
