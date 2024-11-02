#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct node
{
	ll u,v,w;
	bool operator<(const node&b)const
	{
		return w<b.w;
	}
}edge[200010];
ll fa[200010],size[200010],sum[200010];
inline ll findfa(ll x)
{
	return fa[x]==x?x:fa[x]=findfa(fa[x]);
}
int main()
{
	ll n=1;
	while(~scanf("%lld",&n)&&n)
	{
		for(int i=1;i<=n;++i)fa[i]=i,size[i]=1,sum[i]=0;
		for(int i=1;i<n;++i)scanf("%lld%lld%lld",&edge[i].u,&edge[i].v,&edge[i].w);
		sort(edge+1,edge+n);
		reverse(edge+1,edge+n);
		for(int i=1;i<n;++i)
		{
			ll u=findfa(edge[i].u),v=findfa(edge[i].v),w=edge[i].w;
			if(u==v)continue;
			ll sumu=sum[u]+size[v]*w,sumv=sum[v]+size[u]*w;
			if(sumu>sumv)
			{
				fa[v]=u;
				size[u]+=size[v];
				sum[u]=sumu;
			}
			else
			{
				fa[u]=v;
				size[v]+=size[u];
				sum[v]=sumv;
			}
		}
		printf("%lld\n",sum[findfa(1)]);
	}
    return cerr<<'\n'<<1.0*clock()/CLOCKS_PER_SEC<<'\n',0;
}
