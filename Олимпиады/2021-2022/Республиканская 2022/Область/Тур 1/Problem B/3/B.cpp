#include <iostream>
#define UNDEFINED -1LL
using namespace std;

typedef long long int lli;

const lli MAX_SIZE = 500000LL,
		  d = 998244353LL;

lli N,
	M,
	A[MAX_SIZE + 5LL],
	B[MAX_SIZE + 5LL];
lli answer;

void input();
void solution();
void output();
lli get_answer(lli, lli);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	input();
	solution();
	output();
	
	return 0;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < (int)N; ++i)
		cin >> A[i];
	for (int j = 0; j < (int)M; ++j)
		cin >> B[j];
	return;
}

void solution() {
	answer = get_answer(0LL, 0LL);
	return;
}

void output() {
	cout << answer << '\n';
	return;
}

lli get_answer(lli _a, lli _b) {
	if ((_a >= N) || (_b >= M))
		return 0LL;
	if (_b == M - 1LL) { // остался единственный отрезок
		lli counter = 0LL;
		for (int i = (int)_a; i < (int)N; ++i)
			if (A[i] == B[_b])
				++counter;
		if (counter == 1LL) return 1LL;
		return 0LL;
	}
	
	lli elem = B[_b],
		first_appearance = UNDEFINED,
		next_elem = B[_b + 1LL];
	for (int i = (int)_a; i < (int)N; ++i)
		if (A[i] == elem) {
			first_appearance = i;
			break;
		}
	
	if (first_appearance == UNDEFINED)
		return 0LL;
	
	lli mini_ans = 0LL,
		length = 0LL;
	for (int i = (int)first_appearance + 1; i < (int)N; ++i) {
		++length;
		
		if (A[i] == elem) { // второе появление elem
			mini_ans += (length * get_answer((lli)i, _b + 1LL)) % d;
			mini_ans %= d;
			break;
		}
		
		if (A[i] == next_elem) { // появление next_elem
			mini_ans += (length * get_answer((lli)i, _b + 1LL)) % d;
			mini_ans %= d;
			length = 0LL;
		}
	}
	
	return mini_ans;
}
