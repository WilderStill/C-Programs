#include<bits/stdc++.h>
#define ll long long
#define M 1145141
using namespace std;
ll n,cnt,rt,ans=0x3f3f3f3f,val[M],f[M],depth[M],head[M],size[M];
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
void dfs1(ll x,ll fa,ll depth)
{
	size[x]=val[x];
	for(ll i=head[x];~i;i=edge[i].nxt)
	{
		ll v=edge[i].to;
		if(v==fa)continue;
        dfs1(v,x,depth+1);
        size[x]+=size[v];
	}
	f[1]+=val[x]*depth;
}
void dfs2(ll x,ll fa)
{
	for(ll i=head[x];~i;i=edge[i].nxt)
	{
		ll v=edge[i].to;
		if(v==fa)continue;
		f[v]=f[x]+size[1]-2*size[v];
		dfs2(v,x);
	}
	ans=min(ans,f[x]);
}
int main()
{
	memset(head,-1,sizeof head);
	scanf("%lld",&n);
	rt=1;
	for(ll i=1,x,y;i<=n;++i)
	{
		scanf("%lld%lld%lld",&val[i],&x,&y);
		if(x)addedge(i,x),addedge(x,i);
        if(y)addedge(i,y),addedge(y,i);
	}
	depth[rt]=1;
	dfs1(rt,-1,0);
	dfs2(rt,-1);
	//for(ll i=1;i<=n;++i)if(f[i]<ans)ans=f[i];
	printf("%lld",ans);
	return 0;
}
