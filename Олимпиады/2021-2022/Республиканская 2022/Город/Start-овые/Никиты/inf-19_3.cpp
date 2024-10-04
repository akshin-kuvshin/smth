#include <iostream>
#include <vector>
using namespace std;
 
int n, cnt;
vector<int> a;
 
void input() {
	cin >> n;
	a = vector<int>(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}
 
void sol() {
	for (int i = 0; i < n; i++) {
		if (a[i] <= a[i + 1]) {
			cnt++;
		}
	}
}
 
void output() {
	cout << cnt << "\n";
}
 
int main() {
	input();
	sol();
	output();
	return 0;
}