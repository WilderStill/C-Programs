#include<bits/stdc++.h>
using namespace std;
long long a[1100000],n,m,p;
bool check(long long x)
{
	int tot=0;
	for(int i=1;i<=n;i++)tot+=a[i]/x;
	if(tot>=m)return true;
	else return false;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		p+=a[i];
	}
	long long l=0,r=p,mid;
	while(l+1<r)
	{
		mid=(l+r)/2;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
}
