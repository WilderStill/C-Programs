#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll int
using namespace std;
ll n,m,s,t,maxflow,mincost,dis[5011],tot=1,now[5011],hd[5011],pre[5011],flow[5011]; 
bool vis[5011];
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
inline bool SPFA()
{
	memset(dis,INF,sizeof(dis));
	memset(vis,0,sizeof(vis));
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
	scanf("%d%d",&n,&m);s=1,t=n;
	for(ll i=1,u,v,w,c;i<=m;++i)
	{
		scanf("%d%d%d%d",&u,&v,&w,&c);
		addedge(u,v,w,c);
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
	printf("%d %d",maxflow,mincost);
	return 0;
}
