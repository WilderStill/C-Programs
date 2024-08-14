#include<bits/stdc++.h>
#define ll long long
#define M 11514511
#define INF 0x3f3f3f3f
using namespace std;
int n,m,s,t,tfast,tslow,mfast,mslow,tot=1,vis[M],now[M],dis[M],hd[M],pp[M];
ll mincost;
struct node
{
	int to,nxt,val,cost;
}edge[M];
inline void addedge(int u,int v,int w,int c)
{
	edge[++tot].to=v;edge[tot].val=w;edge[tot].nxt=hd[u];edge[tot].cost=c;hd[u]=tot;
	edge[++tot].to=u;edge[tot].val=0;edge[tot].nxt=hd[v];edge[tot].cost=-c;hd[v]=tot;
}
inline bool spfa()
{
	for(int i=s;i<=t;++i){dis[i]=INF;vis[i]=0;}
	queue<int>q;
	q.push(s);
	dis[s]=0;vis[s]=1;
	while(q.size())
	{
		int top=q.front();
		q.pop();
		vis[top]=0;
		for(int i=hd[top];i;i=edge[i].nxt)
		{
			int v=edge[i].to;
			vis[v]=0;
			if(edge[i].val&&dis[v]>dis[top]+edge[i].cost)
			{
				dis[v]=dis[top]+edge[i].cost;
				if(!vis[v])
				{
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return (dis[t]!=INF);
}
inline int dfs(int x,int flow)
{
	if(x==t)return flow;
	int res=flow;
	vis[x]=1;
	for(int i=now[x];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		now[x]=i;
		if(dis[v]==dis[x]+edge[i].cost&&!vis[v]&&edge[i].val)
		{
			int tmp=dfs(v,min(flow,edge[i].val));
			edge[i].val-=tmp;
			edge[i^1].val+=tmp;
			flow-=tmp;
			mincost+=1ll*tmp*edge[i].cost;
			if(!flow)break;
		}
	}
	vis[x]=0;
	return res-flow;
}
int main()
{
    scanf("%d",&n);
	scanf("%d%d%d%d%d",&tfast,&tslow,&mfast,&mslow,&m);
    s=0,t=2*n+1;
    for(int i=1;i<=n;++i)
	{
    	scanf("%d",&pp[i]);
    	addedge(i+n,t,pp[i],0);
    	addedge(s,i,pp[i],0);
    }
    for(int i=1;i<=n;++i)
	{
    	if(i+1<=n)addedge(i,i+1,INF,0);
    	if(i+tfast<=n)addedge(i,i+n+tfast,INF,mfast);
    	if(i+tslow<=n)addedge(i,i+n+tslow,INF,mslow);
		addedge(s,i+n,INF,m);
    }
	while(spfa())
	{
		for(int i=s;i<=t;++i)now[i]=hd[i];
		dfs(s,INF);
	}
	printf("%lld",mincost);
}
