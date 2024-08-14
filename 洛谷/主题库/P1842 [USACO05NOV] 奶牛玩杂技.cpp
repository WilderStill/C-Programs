#include<bits/stdc++.h>
using namespace std;
int n,w[100000009],s[100000099],ans=-10000000;
struct person
{
	int v;
	int w;
	int s;
}p[100000099];
bool cmp(person a,person b)
{
	return a.v<b.v;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>s[i];
		p[i].v=w[i]+s[i];
		p[i].w=w[i];
		p[i].s=s[i];
	}
	sort(p+1,p+n+1,cmp);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		w[i]=p[i].w;
		s[i]=p[i].s;
		ans=max(ans,sum-s[i]);
		sum+=w[i];
	}
	cout<<ans;
	return 0;
}
