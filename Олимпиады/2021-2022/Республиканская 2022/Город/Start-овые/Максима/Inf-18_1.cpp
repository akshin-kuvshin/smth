#include <iostream>
using namespace std;

int a,b,c,d,S;

int main() 
{
	cin>>a;
	cin>>b;
	cin>>c;
	cin>>d;
	if(a<c)
	{
		swap(a,c);
	}
	if(d<b)
	{
		swap(d,b);
	}
	S=c*b;
	cout<<S;
	return 0;
}