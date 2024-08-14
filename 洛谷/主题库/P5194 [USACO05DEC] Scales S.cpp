#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll sum[114514],a[114514],ans,n,c;
void dfs(int p,ll x)
{
	if(x>c)return;
	if(sum[p-1]+x<=c)
	{
		ans=max(ans,sum[p-1]+x);
		return;
	}
	ans=max(ans,x);
	for(int i=1;i<p;i++) dfs(i,x+a[i]);
	return;
}
int main()
{
	scanf("%lld%lld",&n,&c);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	dfs(n+1,0);
	printf("%lld",ans);
	return 0;
}
