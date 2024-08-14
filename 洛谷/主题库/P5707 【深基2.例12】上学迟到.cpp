#include <bits/stdc++.h>
using namespace std;
int main()
{
	int s,v,a[2]={7,50},t;
	cin>>s>>v;
	t=ceil(s*1.0/v*1.0);
	a[1]-=t;
	while(a[1]<0)
	{
		a[0]-=1;
		a[1]+=60;
	}
	while(a[0]<0)
	{
		a[0]+=24;
	}
	if(a[0]<10)cout<<0;
	cout<<a[0]<<":";
	if(a[1]<10)cout<<0;
	cout<<a[1];
	return 0;
}
