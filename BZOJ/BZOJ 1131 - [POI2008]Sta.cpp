#include<bits/stdc++.h>
#define ll long long
#define M 1145141
using namespace std;
ll n,cnt,rt,ans,pos,f[M],depth[M],head[M],size[M];
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
	depth[x]+=(depth[fa]+1);
	size[x]=1;
	for(ll i=head[x];~i;i=edge[i].nxt)
	{
		ll v=edge[i].to;
		if(v==fa)continue;
        dfs1(v,x);
        size[x]+=size[v];
	}
}
void dfs2(ll x,ll fa)
{
	for(ll i=head[x];~i;i=edge[i].nxt)
	{
		ll v=edge[i].to;
		if(v==fa)continue;
		f[v]=f[x]+size[rt]-2*size[v];
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
	dfs1(rt,-1);
	for(ll i=1;i<=n;++i)f[rt]+=depth[i];
	dfs2(rt,-1);
	for(ll i=1;i<=n;++i)if(ans<f[i])ans=f[i],pos=i;
	printf("%lld",pos);
	return 0;
}
