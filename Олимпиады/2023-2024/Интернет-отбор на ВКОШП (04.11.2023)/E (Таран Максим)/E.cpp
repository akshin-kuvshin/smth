#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

#define fr first
#define num second
const int Max=3e5;
int N,M,K;
vector<long long> us,us2;
vector <int> ans;
stack <pair<int,long long>> st;

void input()
{
	cin>>N>>M;
	us.resize(M);
	for(int i=0;i<M;i++) cin>>us[i];
	us2=us;//не факт что понадобится второй
	sort(us.begin(),us.end());
	return;
}

void sol()
{
	int i=0;
	while(i<M)
	{
		int cur_num=us[i];
		int cnt=upper_bound(us.begin(),us.end(),us[i])-lower_bound(us.begin(),us.end(),us[i]);
		i+=cnt;
		if(cnt>=N)
		{
			K++;
			ans.push_back(cur_num);	
		}
	}
	return;
}

void output()
{
	cout<<K<<'\n';
	int sz1=ans.size();
	for(int i=0;i<sz1;i++) cout<<ans[i]<<' ';
	return;
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	input();
	sol();
	output();
	return 0;
}

