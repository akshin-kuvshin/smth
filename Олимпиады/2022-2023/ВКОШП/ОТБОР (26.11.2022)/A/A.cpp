#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

ifstream fin("test.in");
ofstream fout("test.out");

bool used[1000 + 5];
int N, K;
string s;
int ans, arr[1000 + 5];

void in(){
	fin >>N;
}


void sol(){
	K = N;
	K--;
	while(N--){
		fin >>s;
		int sz = s.size();
		fill(used, used + 1000, 0);
		ans = 0;
		for(int i = 0; i < sz; i++){
			char a = s[i];
			if((used[int(a)] == false) && a!=' '){
				ans ++;
				used[int(a)] = true;
			}
		}
		arr[N] = ans;
	}
}

void out(){
	for(int i = (K--); i >= 0; i--){
		fout<<arr[i] <<"\n";
	}
}

int main(){
	in();
	sol();
	out();
	return 0;
}

