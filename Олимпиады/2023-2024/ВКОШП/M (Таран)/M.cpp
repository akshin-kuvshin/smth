#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long int lli;
int x,y,z,a,b,c;
int sum_e,x_,y_,z_,xy,yz,xz;
int arr[3],min_all,sum_all;
int ans;

int check(int S)
{
    if(S<5) return a;
    if(S>=5 && S<10) return b;
    if(S>=10) return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>x>>y>>z>>a>>b>>c;
    min_all=check(x+y+z);
    xy=check(x+y);
    xz=check(x+z);
    yz=check(y+z);
    x_=check(x);
    y_=check(y);
    z_=check(z);
    cout<<min({xy+z_, xz+y_, yz+x_, x_+y_+z_,min_all})<<'\n';
    return 0;
}
