#include <iostream>
#define A first
#define B second
using namespace std;
typedef long long int lli;

lli N,
	K;
pair<lli, lli> arr[50 + 5];
lli answer;

lli bs();
bool f(lli);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N >> K; ++K;
	for (int i = 0; i < (int)N; ++i)
		cin >> arr[i].A >> arr[i].B;
	
	answer = bs();
	cout << answer << '\n';
	return 0;
}

lli bs() {
	lli l = (lli)-2e9 - 1LL,
		r = (lli)2e9 + 1LL;
	
	while (l + 1LL < r) {
		lli mid = (l + r) / 2;
		
		if (f(mid))
			l = mid;
		else
			r = mid;
	}
	
	return l;
}

bool f(lli x) {
	lli cnt = 0LL; // кол-во элементов строго меньше (x)
	for (int i = 0; i < (int)N; ++i) {
		if (x < arr[i].A)
			cnt += 0LL;
		else if (x <= arr[i].B)
			cnt += x - arr[i].A;
		else
			cnt += arr[i].B - arr[i].A + 1LL;
	}
	return (cnt < K);
}
