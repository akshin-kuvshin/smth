#include <iostream>
#include <fstream>


using namespace std;

char inname [15] = "volume.in";
char outname [15] = "volume.out";

long long A, B, C, ans;

long long gcd(long long a, long long b){
	if(b == 0) return a;
	else gcd(b, a%b);
}

void in(){
	ifstream cin(inname);
	cin >>A >>B >>C;
}

void sol(){
	A--;
	B--;
	C--;
	long long num1 = gcd(A, B);
	ans = gcd(num1, C);
}

void out(){
	ofstream cout(outname);
	cout<<ans <<"\n";
}

int main(){
	in();
	sol();
	out();
	return 0;
}

