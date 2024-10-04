#include<iostream>
#include<algorithm>

using namespace std;

const int N_max = 1e5;
long long N, Q;
long long a[2 * N_max + 5], b[2 * N_max + 5];
bool used[2 * N_max + 5];

void in(){
	cin >>N;
	for(int i = 1; i <= N; i++){
		cin >>a[i];
	}
	for(int i = 1; i <= N; i++){
		cin >>b[i];
	}
	cin >>Q;
}

void sol(){
	while(Q--){
		long long l, r;
		cin >>l >>r;
		if(a[1] == b[1] && a[N] == b[N]){
			for(int i = l; i <= r; i++){
				used[a[i]] = true;
			}
			for(int i = 0; i <= N; i++){
				if(!used[i]){
					cout<<i <<"\n";
					break;
				}
			}
		}
		else{
			bool zero = false;
			bool one  = false;
			for(int i = l; i <= r; i++){
				if(a[i] == 0 || b[i] == 0) zero = true;
				if(a[i] == 1 || b[i] == 1) one = true;
				if(one == true && zero == true) break;
			}
			if(one == true && zero == true) cout<<2 <<"\n";
			else if(one == true && zero == false) cout<<0 <<"\n";
			else cout<<1 <<"\n";
		}
	}	
}

void out(){
	
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
