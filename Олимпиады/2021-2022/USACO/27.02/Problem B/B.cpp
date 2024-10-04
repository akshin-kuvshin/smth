#include <iostream>
using namespace std;

// Variables
int N,
	i,
	j,
	tmp,
	_ans;
bool flag;

// Functions
void del(int);

int main() {
	// Input begin
	cin >> N;
	
	int have[N + 5],
		need[N + 5];
	
	for (int i = 0; i < N; ++i)
		cin >> have[i];
	for (int i = 0; i < N; ++i)
		cin >> need[i];
	// Input end
	
	
	// Solution begin
	while (i != N) {
		flag = false;
		for (tmp = j; tmp < N; ++tmp)
			if (have[i] == need[tmp]) {
				flag = true;
				break;
			}
		
		if (flag) {
			++i;
			j = tmp + 1;
		} else {
			++i;
			++_ans;
		}
	}
	// Solution end
	
	
	// Output begin
	cout << _ans << '\n';
	// Output end
	
	return 0;
}
