#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

ifstream fin("color.in");
ofstream fout("color.out");

int N, ans;
string s;

int sol(){
	int top = -1;
	int sz = s.size();
	int l = 0;
	int r = sz - 1;
	while (l < r) {
		if (l == r)
			break;
		
		if (s[l] == s[r]) {
			++l;
			--r;
		} else {
			++ans;
			++top;
			l = top + 1;
			r = sz - 1;
		}
	}
	return ans;
}

void in(){
	fin >>N;
	fin >>s;
}

void out(){
	fout<<sol() <<"\n";
}

int main(){
	in();
	out();
	return 0;
}

