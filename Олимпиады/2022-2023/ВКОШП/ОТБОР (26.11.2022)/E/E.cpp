#include <iostream>
#include <fstream>
using namespace std;
long long n, k;

void in(){
	ifstream fin("food.in");
	fin >> n >> k;
	fin.close();
}


void sol(){
	ofstream fout("food.out");
	if (3 * n >= 7 * k) {
		fout << "YES" << "\n";
	} else {
		fout << "NO" << "\n";
	}
	fout.close();
}

int main(){
	in();
	sol();
	return 0;
}

