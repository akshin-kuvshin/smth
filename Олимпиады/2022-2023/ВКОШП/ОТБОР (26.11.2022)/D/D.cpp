#include <fstream>
#include <string>
using namespace std;

ifstream fin("money.in");
ofstream fout("money.out");

int tests_amount;
bool result;
string ans[] = {"NO", "YES"};

int sum,
	coins_number;
int need[10],
	pockets[10];

bool check() {
	if ( (need[1] <= pockets[1]) and (need[2] <= pockets[2]) and (need[3] <= pockets[3]) )
		return true;
	return false;
}

void in() {
	fin >> sum >> coins_number;
	
	int tmp;
	for (int i = 0; i < coins_number; ++i) {
		fin >> tmp;
		++pockets[tmp];
	}
	
	return;
}

void sol() {
	need[3] = sum / 3;
	sum %= 3;
	need[sum] = 1;
	sum = 0; // не обязательно
	
	if (check()) {
		result = true;
		return;
	}
	
	while (need[3] > pockets[3]) {
		if ( (need[2] < pockets[2]) and (need[1] < pockets[1]) ) {
			need[3] -= 1;
			
			need[1] += 1;
			need[2] += 1;
		} else
			break;
	}
	
	if (need[3] > pockets[3])
		return;
	
	if (check()) {
		result = true;
		return;
	}
	
	while (need[2] > pockets[2]) {
		if ( (need[3] < pockets[3]) and (need[1] != 0) ) {
			need[2] -= 1;
			need[1] -= 1;
			
			need[3] += 1;
		} else if (pockets[1] - need[1] >= 2) {
			need[2] -= 1;
			
			need[1] += 2;
		} else
			break;
	}
	
	if (need[2] > pockets[2])
		return;
	
	if (check()) {
		result = true;
		return;
	}
	
	while (need[1] > pockets[1]) {
		if ( (need[3] < pockets[3]) and (need[2] != 0) ) {
			need[1] -= 1;
			need[2] -= 1;
			
			need[3] += 1;
		} else if ( (need[1] >= 2) and (need[2] < pockets[2]) ) {
			need[1] -= 2;
			
			need[2] += 1;
		} else
			break;
	}
	
	if (check())
		result = true;
	return;
}

void out() {
	fout << ans[result] << '\n';
	return;
}

int main() {
	fin >> tests_amount;
	for (int t = 0; t < tests_amount; ++t) {
		result = false;
		sum = coins_number = 0;
		need[1] = need[2] = need[3] = 0;
		pockets[1] = pockets[2] = pockets[3] = 0;
		
		in();
		sol();
		out();
	}
	
	fin.close();
	fout.close();
	return 0;
}

