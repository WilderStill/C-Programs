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
	size[x]=1;
	for(ll i=head[x];~i;i=edge[i].nxt)
	{
		ll v=edge[i].to;
		if(depth[v])continue;
		depth[v]=depth[x]+1;
        dfs1(v,x);
        size[x]+=size[v];
	}
}
void dfs2(ll x,ll fa)
{
	f[x]=f[fa]+n-2*size[x];
	for(ll i=head[x];~i;i=edge[i].nxt)
	{
		ll v=edge[i].to;
		if(v==fa)continue;
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
	depth[rt]=1;
	dfs1(rt,-1);
	for(ll i=1;i<=n;++i)ans+=depth[i];
	ans-=n;
	f[1]=ans;
	for(int i=head[1];i;i=edge[i].nxt)
	{
        int to=edge[i].to;
        dfs2(to,1);
    }
	for(ll i=2;i<=n;++i)if(f[i]<ans)ans=f[i],pos=i;
	printf("%lld %lld",pos,ans);
	return 0;
}
