#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
ll n,m,tfast,mfast,tslow,mslow,s,t,maxflow,mincost,dis[5544],tot=1,now[5544],hd[5544],pre[5544],flow[5544],pp[5544]; 
bool vis[5544];
struct node
{
	ll to,nxt,val,cost;
}edge[114514];
void addedge(ll u,ll v,ll w,ll c)
{
	edge[++tot].to=v;
	edge[tot].val=w;
	edge[tot].cost=c;
	edge[tot].nxt=hd[u];
	hd[u]=tot;
	edge[++tot].to=u;
	edge[tot].val=0;
	edge[tot].cost=-c;
	edge[tot].nxt=hd[v];
	hd[v]=tot;
}
bool SPFA()
{
	for(int i=0;i<5141;i++)dis[i]=INF;
	for(int i=0;i<5141;i++)vis[i]=0;
	queue<ll>q;
	q.push(s);
	dis[s]=0;
	vis[s]=1;
	flow[s]=INF;
	while(q.size())
	{
		ll top=q.front();
		q.pop();
		vis[top]=0;
		for(ll i=hd[top];i;i=edge[i].nxt)
		{
			ll v=edge[i].to;
			if(edge[i].val&&dis[v]>dis[top]+edge[i].cost)
			{
				dis[v]=dis[top]+edge[i].cost;
				flow[v]=min(flow[top],edge[i].val);
				pre[v]=i;
				if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
			}
		}
	}
	return dis[t]!=INF;
}
int main()
{
	scanf("%lld",&n);scanf("%lld%lld%lld%lld%lld",&tfast,&tslow,&m,&mfast,&mslow);
	s=0,t=2*n+1;
	for(ll i=1;i<=n;++i)
	{
		scanf("%lld",&pp[i]);
		addedge(s,i,pp[i],0); 
		addedge(i+n,t,pp[i],0);
	}
	for(ll i=1;i<=n;++i)
	{
		if(i+1<=n)addedge(i,i+1,INF,0);
		if(i+tfast+1<=n)addedge(i,i+n+tfast+1,INF,mfast); 
		if(i+tslow+1<=n)addedge(i,i+n+tslow+1,INF,mslow);
		addedge(s,i+n,INF,m);
	}
	while(SPFA())
	{
		maxflow+=flow[t];
		mincost+=flow[t]*dis[t];
		for(int i=t;i!=s;i=edge[pre[i]^1].to)
		{
			edge[pre[i]].val-=flow[t];
			edge[pre[i]^1].val+=flow[t];
		}
	}
	printf("%lld",mincost);
	return 0;
}
