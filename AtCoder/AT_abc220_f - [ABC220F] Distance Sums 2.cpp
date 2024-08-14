#include<bits/stdc++.h>
#define ll long long
#define M 1145141
using namespace std;
ll n,cnt,rt,ans=LONG_LONG_MAX,val[M],f[M],depth[M],head[M],Size[M];
struct node
{
	ll nxt,to;
}edge[M<<1];
void addedge(ll u,ll v)
{
	edge[++cnt].to=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
void dfs1(ll x,ll fa)
{
	f[rt]+=depth[x];
	Size[x]=1;
	for(ll i=head[x];~i;i=edge[i].nxt)
	{
		ll v=edge[i].to;
		if(v==fa)continue;
		depth[v]+=(depth[x]+1);
        dfs1(v,x);
        Size[x]+=Size[v];
	}
}
void dfs2(ll x,ll fa)
{
	for(ll i=head[x];~i;i=edge[i].nxt)
	{
		ll v=edge[i].to;
		if(v==fa)continue;
		f[v]=f[x]+Size[rt]-2*Size[v];
		dfs2(v,x);
	}
}
int main()
{
	memset(head,-1,sizeof head);
	scanf("%lld",&n);
	rt=1;
	for(ll i=1,x,y;i<n;++i)
	{
		scanf("%lld%lld",&x,&y);
		addedge(x,y);addedge(y,x);
	}
	dfs1(rt,1);
	dfs2(rt,1);
	for(ll i=1;i<=n;++i)printf("%lld\n",f[i]);
	return 0;
}
