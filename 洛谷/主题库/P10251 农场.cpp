#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x1,x2,y12,y2,a=1e9,b=1e9,c,d,n;
int main()
{
	cin>>n;
	while(n--)
	{
		cin>>x1>>y12>>x2>>y2;
		a=min(a,min(x1,x2));
		b=min(b,min(y12,y2));
		c=max(c,max(x1,x2));
		d=max(d,max(y12,y2));
	}
	cout<<abs(c-a)*abs(d-b);
	return 0;
}
