#include<iostream>
#include<set>
#include<cmath>

using namespace std;

const int N_max = 1e5 * 5;
const long long mod = 1e9 + 7;
long long n, m, t;
long long arr[N_max + 5];
long long ans;
set <long long> st;

void un_max(int l_i, int r_j){
	st.insert(arr[l_i]);
	long long cur_max = arr[l_i];
	l_i++;
	for(int i = l_i; i <= r_j; i++){
		if(arr[i] > cur_max){
			st.insert(arr[i]);
			cur_max = arr[i];
		}
	}
}

void in(){
	cin >>n >>m >>t;
	for(int i = 1; i <= n; i++){
			cin >>arr[i];
	}
}

void sol(){
	/*bool f = true;
	for(int i = 1; i <= n; i++){
		if(arr[i] != i){
			f = false;
			break;
		}
	}
	if(f){*/
		while(m--){
			long long l, r;
			cin >>l >>r;
			ans = 0;
			for(int i = l; i <= r; i++){
				st.clear();
				for(int j = i; j <= r; j++){
					un_max(i, j);
					//cout<<i <<" " <<j <<" ";
					//cout<<st.size() <<"\n";
					ans += pow(st.size(), t);
				}
			}
			cout<<ans % mod <<"\n";
		}	
	//}
	/*else{
		while(m--){
			long long l, r;
			cin >>l >>r;
			long long num = r - l + 1;
			long long num2 = num;
			ans = 0;
			for(int i = 1; i <= num2; i++){
				ans += pow(i * num, 2);
				num--;
			}
			cout<<ans % mod <<"\n";
		}
	}*/
}

void out(){
	
}

int main(){
	in();
	sol();
	out();
	return 0;
}
