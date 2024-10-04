#include <fstream>
#include <string>
using namespace std;

ifstream fin("money.in");
ofstream fout("money.out");

int tests_number;
string ans[] = {"NO", "YES"};

int sum,
	coins_number,
	x,
	y,
	z;

void in() {
	fin >> sum >> coins_number;
	
	int tmp;
	for (int i = 0; i < coins_number; ++i) {
		fin >> tmp;
		
		if (tmp == 1)
			++x;
		else if (tmp == 2)
			++y;
		else // tmp == 3
			++z;
	}
	
	return;
}

bool sol() {
	for (int n3 = 0; (n3 <= z) and (3 * n3 <= sum); ++n3)
		for (int n2 = 0; (n2 <= y) and (2 * n2 + 3 * n3 <= sum); ++n2) {
			int n1 = sum - 2 * n2 - 3 * n3;
			
			if (n1 < 0)
				continue;
			
			if (n1 <= x)
				return true;
		}
	return false;
}

int main(){
	fin >> tests_number;
	for (int t = 0; t < tests_number; ++t) {
		sum = coins_number = 0;
		x = y = z = 0;
		
		in();
		fout << ans[sol()] << '\n';
	}
	return 0;
}
