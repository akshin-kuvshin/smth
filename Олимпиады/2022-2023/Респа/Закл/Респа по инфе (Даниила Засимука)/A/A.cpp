#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

struct cor_time{
	long long x;
	long long t;
};

const long long N_max = 1e5;
long long N;
cor_time arr[N_max + 5];
long long used[N_max + 5];
long long ans;
bool f;

bool cmp(cor_time a, cor_time b){
	if(a.x == b.x) return a.t < b.t;
	else return a.x < b.x;
}

void in(){
	cin >>N;
	for(int i = 1; i <= N; i++){
		cin >>arr[i].x >>arr[i].t;
		used[arr[i].x]++;
	}	
}

void sol(){
	sort(arr, arr + N + 1, cmp);
	for(int j = 1; j <= N; j++){
		if(used[j] > 1){
			long long index = 1;
			for(int i = 1; i <= N; i++){
				if(arr[i].x == j){
					index = i;
				}
				if(i <= N - 1 && arr[i].x == j && arr[i].x != arr[i + 1].x){
					break;
				}
			}
			ans = arr[index - 1].t;
			f = true;
			for(int i = 1; i <= N; i++){
				if(arr[i].t > ans && used[j] > 1 && i != j){
					f = false;
					break;
				}
			}
			if(f) break;
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

/*
5
1 6
2 3
4 5
2 7
2 5

5
1 2
2 3
3 4
4 5
4 1
*/
 
