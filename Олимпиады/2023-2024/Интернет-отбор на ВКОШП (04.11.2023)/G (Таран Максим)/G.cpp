#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Max=1e6;
long long k;

void input_sol()
{
	cin>>k;
	vector <int> number; 
	while(k)
	{
		int ch=k%10;
		if(ch==2) number.push_back(5);
		else if(ch==5) number.push_back(2);
		else number.push_back(ch);
		k/=10;
	}
	bool was_num=0;
	int sz=number.size();
	for(int i=0;i<sz;i++)
	{
		if(number[i]>0 || (number[i]==0 && was_num==1))
		{
			was_num=1;
			cout<<number[i];
		}
	}
	return;
}

int main()
{
	input_sol();
	return 0;
}

