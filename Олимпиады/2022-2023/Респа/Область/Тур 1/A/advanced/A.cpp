#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

const lli N_max = 200000LL;

lli N,
	A[N_max + 5LL];
vector<lli> d[N_max + 5LL];
lli Q,
	x;
lli used[N_max + 5LL];
bool bad_case;
string ans[] = {"NO\n", "YES\n"};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	/*
		d[2] = {2}
		d[3] = {3}
		d[4] = {2}
		d[5] = {5}
		d[6] = {2, 3}
		d[7] = {7}
		d[8] = {2}
		d[9] = {3}
		d[10] = {2, 5}
	*/
	
	// Заполняем массив d.
	// d[x] содержит в себе простые делители числа x.
	// Если x - простое число, то единственный элемент d[x] - это само число x.
	// d[x].empty() означает, что x - простое число, т.к. не было затронуто ранее.
	for (int i = 2; i < (int)N_max; ++i)
		if (d[i].empty())
			for (int j = i; j <= (int)N_max; j += i)
				d[j].push_back(i);
	
	cin >> N >> Q;
	for (int i = 0; i < (int)N; ++i)
		cin >> A[i];
	
	for (int it = 1; it <= (int)Q; ++it) {
		cin >> x;
		
		bad_case = false;
		for (int i = 0; i < (int)N and !bad_case; ++i)
			for (int p : d[A[i] + x]) {
				if (used[p] == it) { // used[p] == it означает, что простой делитель p уже был ранее встречен => найдётся плохая пара чисел.
					bad_case = true;
					break;
				}
				used[p] = it;
			}
		
		cout << ans[!bad_case];
	}
	
	return 0;
}
