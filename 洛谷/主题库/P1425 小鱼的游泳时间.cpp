#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[2],b[2];
	cin>>a[0]>>a[1]>>b[0]>>b[1];
	b[0]-=a[0];
	b[1]-=a[1];
	while(b[1]<0)
	{
		b[0]-=1;
		b[1]+=60;
	}
	while(a[0]<0)
	{
		b[0]+=24;
	}
	cout<<b[0]<<" "<<b[1];
	return 0;
}
