#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll int
using namespace std;
ll n,m,s,t,T,maxflow,mincost,dis[5011],tot=1,now[5011],hd[5011],pre[5011],flow[5011],num[5011],ave; 
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
	scanf("%d",&T);
	while(T--)
	{
		maxflow=mincost=0;
		memset(hd,0,sizeof hd);
		memset(pre,0,sizeof pre);
		for(ll i=0;i<=114513;++i)edge[i]={0,0,0,0};
		scanf("%d",&n);s=0,t=n+1;
		for(ll i=1;i<=n;++i)scanf("%d",&num[i]);
		for(int i=1;i<=n;++i)if(num[i])addedge(s,i,num[i],0),addedge(i,s,0,0);
		for(int i=1;i<=n;++i)addedge(i,t,1,0),addedge(t,i,0,0);
		for(int i=1;i<=n;++i)
		{
			addedge(i,(i==n?1:i+1),n,1);addedge((i==n?1:i+1),i,0,-1);
			addedge(i,(i==1?n:i-1),n,1);addedge((i==1?n:i-1),i,0,-1);
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
		printf("%d\n",mincost);
	} 
	return 0;
}
