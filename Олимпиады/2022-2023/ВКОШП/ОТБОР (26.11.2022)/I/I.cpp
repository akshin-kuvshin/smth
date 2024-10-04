#include <fstream>
#include <string>
#define dot pair<int, int>
#define x first
#define y second
using namespace std;

long long d1_sqr,
		  d2_sqr;
dot A,
	B,
	C,
	D;
bool result;
string ans[] = {"NO", "YES"};

void in() {
	ifstream fin("ring.in");
	fin >> A.x >> A.y >> B.x >> B.y;
	fin >> C.x >> C.y >> D.x >> D.y;
	fin.close();
	return;
}

void sol() {
	d1_sqr = (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
	d2_sqr = (C.x - D.x) * (C.x - D.x) + (C.y - D.y) * (C.y - D.y);
	
	if (d1_sqr == d2_sqr)
		result = true;
	return;
}

void out() {
	ofstream fout("ring.out");
	fout << ans[result] << '\n';
	fout.close();
	return;
}

int main(){
	in();
	sol();
	out();
	return 0;
}

