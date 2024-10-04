#include <iostream>
#include<cmath>
#include<algorithm>

using namespace std;

const int N_max = 1e5 * 5;

long long N, Q, arr[N_max + 5];
long long k;
bool used[N_max + 5];

void in(){
	cin >>N >>Q;
	for(int i = 1; i <= N; i++)
		cin >>arr[i];
}

void sol(){
	if(N == 2 && Q == 1){
		while(Q--){
			long long l, r;
			cin >>l >>r;
			k = 0;
			for(int i = l; i <= r; i++){
				long long x = arr[i];
				long long cur_max = 0;
				for(int i = l; i <= r; i++){
					if(arr[i] % x == 0 && arr[i] > cur_max){
						cur_max = arr[i];
						long long pow_two = arr[i] / x;
						for(long long j = 0; j <= 19; j++){
							if(pow(2, j) == pow_two){
								k = max(k, j);
								break;
							}
						}
					}
				}
			}
			cout<<k <<"\n";
		}	
	}
	else{
		while(Q--){
			long long l, r;
			cin >>l >>r;
			for(int i = l; i <= r; i++){
				long long k_ = -1;
				fill(used, used + N_max + 5, 0);
				long long x = arr[i];
				for(int j = 0; j <= 10; j++){
					long long chislo = pow(2, j) * x;
					//cout<<chislo <<"\n";
					used[chislo] = true;
				}
				/*cout<<x <<" ";
				for(int c = l; c <= r; c++){
					cout<<used[arr[c]] <<" ";
				}
				cout<<"\n";*/
				for(int c = l; c <= r; c++){
					if(used[arr[c]]){
						k_++;
					}
				}
				k = max(k, k_);
			}
			cout<<k <<"\n";
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
