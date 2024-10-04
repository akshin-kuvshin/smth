#include <fstream>
#include <string>
using namespace std;

ifstream fin("money.in");
ofstream fout("money.out");

int tests_number;
string ans[] = {"NO", "YES"};

int sum,
	coins_number,
	coins_sum,
	n1,
	n2,
	n3;

int pofig(int s, int a, int b, int c) {
	s -= c * 3;
	c = 0;
	
	s -= (b / 3) * 6;
	b %= 3;
	
	int tmp = min(a, b);
	s -= tmp * 3;
	a -= tmp;
	b -= tmp;
	
	s -= (a / 3) * 3;
	a %= 3;
	
	return s;
}

void in() {
	fin >> sum >> coins_number;
	
	int tmp;
	for (int i = 0; i < coins_number; ++i) {
		fin >> tmp;
		coins_sum += tmp;
		
		if (tmp == 1)
			++n1;
		else if (tmp == 2)
			++n2;
		else // tmp == 3
			++n3;
	}
	
	return;
}

bool sol() {
	if (coins_sum < sum)
		return false;
	
	if (sum % 3 == 1) {
		if (n1 >= 1) {
			int s = sum,
				a = n1,
				b = n2,
				c = n3;
			
			--a;
			--s;
			
			s = pofig(s, a, b, c);
			
			if (s <= 0)
				return true;
		}
		
		if (n2 >= 2 and sum != 1) {
			int s = sum,
				a = n1,
				b = n2,
				c = n3;
			
			b -= 2;
			s -= 4;
			
			s = pofig(s, a, b, c);
			
			if (s <= 0)
				return true;
		}
	} else if (sum % 3 == 2) {
		if (n2 >= 1) {
			int s = sum,
				a = n1,
				b = n2,
				c = n3;
			
			--b;
			s -= 2;
			
			s = pofig(s, a, b, c);
			
			if (s <= 0)
				return true;
		}
		
		if (n1 >= 2) {
			int s = sum,
				a = n1,
				b = n2,
				c = n3;
			
			a -= 2;
			s -= 2;
			
			s = pofig(s, a, b, c);
			
			if (s <= 0)
				return true;
		}
	} else { // sum % 3 == 0
		int s = sum,
			a = n1,
			b = n2,
			c = n3;
		
		s = pofig(s, a, b, c);
		
		if (s <= 0)
			return true;
	}
	
	return false;
}

int main(){
	fin >> tests_number;
	for (int t = 0; t < tests_number; ++t) {
		sum = coins_number = coins_sum = 0;
		n1 = n2 = n3 = 0;
		
		in();
		fout << ans[sol()] << '\n';
	}
	return 0;
}
