#include<bits/stdc++.h>
#define ll long long
#define M 1145141
using namespace std;
ll n,cnt,tot,rt,ans=-1,val[M],f[M],depth[M],head[M],Size[M];
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
	Size[x]=val[x];
	for(ll i=head[x];~i;i=edge[i].nxt)
	{
		ll v=edge[i].to;
		if(v==fa)continue;
        dfs1(v,x);
        Size[x]+=Size[v];
        f[rt]+=(f[v]+Size[v]);
	}
}
void dfs2(ll x,ll fa)
{
	for(ll i=head[x];~i;i=edge[i].nxt)
	{
		ll v=edge[i].to;
		if(v==fa)continue;
		f[v]=f[x]-Size[v]+(tot-Size[v]);
		dfs2(v,x);
	}
}
int main()
{
	memset(head,-1,sizeof head);
	scanf("%lld",&n);
	rt=1;
	for(ll i=1;i<=n;++i)scanf("%lld",&val[i]),tot+=val[i];
	for(ll i=1,x,y,z;i<n;++i)
	{
		scanf("%lld%lld",&x,&y);
		addedge(x,y);addedge(y,x);
	}
	dfs1(rt,-1);
	dfs2(rt,-1);
	for(ll i=1;i<=n;++i)ans=max(ans,f[i]);
	printf("%lld",ans);
	return 0;
}
