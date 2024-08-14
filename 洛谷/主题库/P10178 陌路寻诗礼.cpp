#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define M 411514
#define ll long long
using namespace std;
ll t,n,m,k,tot=0,hd[M],dis[M],id[M],change[M];
bool vis[M];
struct edge
{
	ll to,nxt;
}edge[M];
struct node
{
	ll pos,dis;
	bool operator<(const node b)const
	{
		return dis>b.dis;
	}
};
void add(ll x,ll y)
{
	edge[++tot].to=y;
	edge[tot].nxt=hd[x];
	hd[x]=tot;
}
priority_queue<node>q;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&m,&k);
		{//init
			while(!q.empty())q.pop();
			for(int i=1;i<=n;i++)hd[i]=vis[i]=id[i]=0,dis[i]=INF;
			for(int i=1;i<=m;i++)change[i]=2;
			tot=0;
		}
		for(ll i=1,u,v;i<=m;i++)
		{
			scanf("%lld%lld",&u,&v);
			add(u,v);
		}
		if(m==n-1)
		{
			printf("Yes\n");
			for(int i=1;i<=m;i++)printf("1 ");
			printf("\n");
			continue;
		}
		dis[1]=0;
		q.push({1,0});
		while(!q.empty())
		{
			ll v=q.top().pos;
			q.pop();
			if(vis[v])continue;
			vis[v]=1;
			for(int i=hd[v];i;i=edge[i].nxt)
			{
				ll u=edge[i].to;
				if(dis[v]+1==dis[u])change[i]=2;
				else if(dis[v]+1>dis[u])change[i]=1;
				if(dis[v]+1<dis[u])
				{
					dis[u]=dis[v]+1;
					change[id[u]]=2;
					change[i]=1;
					id[u]=i;
					q.push({u,dis[u]});
				}
			}
		}
		bool fg=0;
		for(int i=1;i<=m;i++)
			if(change[i]>1)
			{
				fg=1;break;
			}
		if(k==1&&fg)printf("No");
		else
		{
			printf("Yes\n");
			for(int i=1;i<=m;i++)printf("%lld ",change[i]);
		}
		printf("\n");
	}
	return 0;	
}
