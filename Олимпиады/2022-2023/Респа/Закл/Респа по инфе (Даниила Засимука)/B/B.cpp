#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

const int N_max = 1e5;
long long N, M, ans;
struct mas{
	long long l;
	long long r;
	long long h;
	long long c;
};
mas arr[N_max * 5];

void in(){
	cin >>N >>M;
	for(int i = 0; i < N; i++){
		cin>>arr[i].l >>arr[i].r >>arr[i].h >>arr[i].c;
	}
}

void sol(){
	if(N == 1){
		ans = arr[0].l + arr[0].h + (arr[0].r - arr[0].l) + arr[0].h + (M - arr[0].r);
	}
	else{
		long long x = 0;
		for(int i = 0; i < N; i++){
			ans += arr[i].l - x;
			ans += arr[i].h;
			ans += arr[i].h;
			ans += arr[i].r - arr[i].l;
			x = arr[i].r;
			if(i == N - 1){
				ans += (M - arr[N - 1].r);
			}
		}
	}
}

void out(){
	cout<<ans <<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	in();
	sol();
	out();
	return 0;
}
