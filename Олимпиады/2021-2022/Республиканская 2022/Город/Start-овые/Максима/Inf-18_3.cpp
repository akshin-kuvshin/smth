#include <iostream>
#include <vector>
using namespace std;

const int Max=1e5;
long long N,step,ans,a;
vector <long> Array;
vector <long> Array2;

void input()
{
	cin>>N;
}

int sol()
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N-i;j++)
		{
			if(Array[i]>Array[i+1])
			{
				int bubble=Array[i+1];
				Array2[i+1]=Array[i];
				Array2[i]=bubble;
			}
		}
	}
	for(int i;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(Array[i]==Array2[j])
			{
				step=j-i;
				i+=step;
				ans++;
			}
		}
	}
	return ans;
}

int main() 
{
	input();
	for(int i=1;i<=N;i++)
	{
		cin>>a;
		Array[i]=a;
	}
	Array2=Array;
	cout<<sol();
	return 0;
}