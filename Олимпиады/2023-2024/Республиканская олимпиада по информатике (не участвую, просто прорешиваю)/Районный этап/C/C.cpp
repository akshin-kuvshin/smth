// author: Danila "akshin_" Axyonov

#include <iostream>
using namespace std;
typedef long long int lli;

const lli MAX_SIZE = (lli)1e5 + 5LL;

lli N1,
	S1[MAX_SIZE],
	pref1[MAX_SIZE],
	N2,
	S2[MAX_SIZE],
	pref2[MAX_SIZE],
	N3,
	S3[MAX_SIZE],
	pref3[MAX_SIZE];
bool flag;
lli ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N1 >> N2 >> N3;
	for (int i = 0; i < (int)N1; ++i) {
		cin >> S1[i];
		pref1[i + 1] = pref1[i] + S1[i];
	}
	for (int i = 0; i < (int)N2; ++i) {
		cin >> S2[i];
		pref2[i + 1] = pref2[i] + S2[i];
	}
	for (int i = 0; i < (int)N3; ++i) {
		cin >> S3[i];
		pref3[i + 1] = pref3[i] + S3[i];
	}
	
	while (!flag) {
		if (pref1[N1] == pref2[N2] and pref2[N2] == pref3[N3]) {
			ans = pref1[N1];
			flag = true;
			continue;
		}
		
		lli m = max(pref1[N1], max(pref2[N2], pref3[N3]));
		if (pref1[N1] == m) --N1;
		else if (pref2[N2] == m) --N2;
		else /* pref3[N3] == m */ --N3;
	}
	
	cout << ans << '\n';
	return 0;
}
