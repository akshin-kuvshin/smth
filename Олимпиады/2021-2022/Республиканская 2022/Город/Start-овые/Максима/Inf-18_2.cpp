#include <iostream>
#include <cmath>
using namespace std;

int x,y,z,a,b,c,ans;

int NOD(int i,int j)
{
	while(abs(i-j)!=0)
	{
		ans=abs(i-j);
		if(i>j) i=ans;
		else j=ans;
	}
	return ans;
}

void input()
{
	cin>>x>>y>>z;
}

int main()
{
	input();
	a=NOD(x,y);
	b=NOD(x,z);
	c=NOD(y,z);
	cout<<a<<" "<<b<<" "<<c<<'\n';
}