#include<bits/stdc++.h>
#define ll long long
#define M 1145141
using namespace std;
ll n,cnt,tot,rt,ans=LONG_LONG_MAX,val[M],f[M],depth[M],head[M],Size[M];
struct node
{
	ll nxt,to,val;
}edge[M<<1];
void addedge(ll u,ll v,ll w)
{
	edge[++cnt].to=v;
	edge[cnt].nxt=head[u];
	edge[cnt].val=w;
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
        f[rt]+=(f[v]+Size[v]*edge[i].val);
	}
}
void dfs2(ll x,ll fa)
{
	for(ll i=head[x];~i;i=edge[i].nxt)
	{
		ll v=edge[i].to;
		if(v==fa)continue;
		f[v]=f[x]-Size[v]*edge[i].val+(tot-Size[v])*edge[i].val;
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
		scanf("%lld%lld%lld",&x,&y,&z);
		addedge(x,y,z);addedge(y,x,z);
	}
	dfs1(rt,-1);
	dfs2(rt,-1);
	for(ll i=1;i<=n;++i)ans=min(ans,f[i]);
	printf("%lld",ans);
	return 0;
}
