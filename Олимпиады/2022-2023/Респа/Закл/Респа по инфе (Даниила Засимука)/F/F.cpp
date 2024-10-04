#include<iostream>

using namespace std;

const int N_max = 1e5 * 2;
long long N, a[N_max + 5], b[N_max + 5];
bool check = true;
long long zero = 0;
bool used[N_max + 5];

/*void DFS(int s){
	if(s == zero){
		for(int i = 0; i < N; i++)
			cout<<a[i] <<" ";
		cout<<"\n";
		for(int i = 0; i < N; i++){
			cout<<b[i] <<" ";
		}
		cout<<"\n";
		cout<<"----\n";
		return ;
	}
	for(int i = 0; i < N; i++){
		if(a[i] == 0){
			for(int c = 1; c <= 2 * N; c++){
				if(!used[c]){
					a[i] = c;
					used[c] = true;
					DFS(s + 1);
					a[i] = 0;
					used[c] = false;
				}
				
			}
		}
	}
	for(int i = 0; i < N; i++){
		if(b[i] == 0){
			for(int c = 1; c <= 2 * N; c++){
				if(!used[c]){
					b[i] = c;
					used[c] = true;
					DFS(s + 1);
					b[i] = 0;
					used[c] = false;
				}
			}
		}
	}
}*/

void in(){
	cin >>N;
	for(int i = 0; i < N; i++){
		cin >>a[i];
		if(a[i] == 0){
			zero++;
		}
		else used[a[i]] = true;
	}
	
	for(int i = 0; i < N; i++){
		cin >>b[i];
		if(b[i] == 0)
			zero++;
		else used[b[i]] = true;
	}
}

void sol(){
	if(zero == 0){
		N--;
		for(int i = 0; i < N; i++){
			if(a[i] < a[i + 1] && a[i] < b[i] && b[i] < b[i + 1]){
				continue;
			}
			else{
				check = false;
				break;
			}
		}
		if(check) cout<<1;
		else cout<<0;
	}
	else{
		/*long long ans = 0;
		if(zero == 1){
			bool a_ = false;
			bool b_ = false;
			long long index = 0;
			for(int i = 0; i < N; i++){
				if(a[i] == 0){
					index = i;
					a_ = true;
					break;
				}
			}
			for(int i = 0; i < N; i++){
				if(b[i] == 0){
					index = i;
					b_ = true;
					break;
				}
			}
			if(a_ == true && b_ == false){
				for(int i = 1; i <= 2 * N; i++){
					if(index != 0 && index != N - 1){
						if(!used[i]){
							if(i < a[index + 1] && i > a[index - 1] && i < b[index]){
								ans++;
							}
						}
					}
					else{
						if(index == 0){
							if(!used[i]){
								if(i < a[index + 1] && i < b[index]){
									ans++;
								}
							}
						}
						else{
							if(!used[i]){
								if(i > a[index - 1] && i < b[index]) ans++;
							}
						}
					}
				}	
			}
			else{
				for(int i = 1; i <= 2 * N; i++){
					if(index != 0 && index != N - 1){
						if(!used[i]){
							if(i < b[index + 1] && i > b[index - 1] && i > a[index]){
								ans++;
							}
						}
					}
					else{
						if(index == 0){
							if(!used[i]){
								if(i < b[index + 1] && i > a[index]){
									ans++;
								}
							}
						}
						else{
							if(!used[i]){
								if(i > b[index - 1] && i > a[index]) ans++;
							}	
						}
					}
				}
			}
		}
		cout<<ans;*/
		cout<<N <<"\n";
	}
}

void out(){
	
}

int main(){
	in();
	sol();
	out();
	return 0;
}
