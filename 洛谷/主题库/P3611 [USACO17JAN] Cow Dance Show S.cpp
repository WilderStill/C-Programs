#include <bits/stdc++.h>
using namespace std;
int n,m,q[1145140];
bool check(int x)
{
	int y=0,a=0;
	priority_queue <int,vector<int>,greater<int> >fuck;
	for(int i=1;i<=x;i++)fuck.push(q[i]);
	for(int i=x+1;i<=n;i++)
	{
		a+=fuck.top()-y;
		y=fuck.top();
		fuck.pop();
		fuck.push(q[i]+y);
		if(a>m)return false;
	}
	while(x--)
	{
		a+=fuck.top()-y;
		y=fuck.top();
		fuck.pop();
		if(a>m)return false;
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&q[i]);
	int l=0,r=114514,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	printf("%d",ans);
	return 0;
}
