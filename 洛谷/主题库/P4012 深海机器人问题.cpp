#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll int
using namespace std;
ll n,m,a,b,s,t,maxflow,maxcost,dis[5011],tot=1,now[5011],hd[5011],pre[5011],flow[5011],id[501][501],cnt; 
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
	memset(dis,-0x3f,sizeof(dis));
	memset(flow,0,sizeof(flow));
	queue<ll>q;
	q.push(s);dis[s]=0;vis[s]=1;
	flow[s]=INF;
	while(q.size())
	{
		ll top=q.front();
		q.pop();
		vis[top]=0;
		for(ll i=hd[top];i;i=edge[i].nxt)
		{
			ll v=edge[i].to;
			if(edge[i].val&&dis[v]<dis[top]+edge[i].cost)
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
	return flow[t]>0;
}
int main()
{
	scanf("%d%d",&a,&b);
	scanf("%d%d",&n,&m);
	s=++cnt;t=++cnt;
	for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            id[i][j]=++cnt;
	for(int i=0;i<=n;i++)
        for(int j=0,w;j<m;j++)
        {
            scanf("%d",&w);
            addedge(id[i][j],id[i][j+1],1,w);
			addedge(id[i][j],id[i][j+1],INF,0);
        }
    for(int j=0;j<=m;j++)
        for(int i=0,w;i<n;i++)
        {
            scanf("%d",&w);
            addedge(id[i][j],id[i+1][j],1,w);
			addedge(id[i][j],id[i+1][j],INF,0);
        }
    for(int i=1,w,ma,mb;i<=a;i++)
    {
        scanf("%d%d%d",&w,&ma,&mb);
        addedge(s,id[ma][mb],w,0);
    }
    for(int i=1,w,ma,mb;i<=b;i++)
    {
        scanf("%d%d%d",&w,&ma,&mb);
        addedge(id[ma][mb],t,w,0);
    }
	while(SPFA())
	{
		int w=flow[t];
		maxcost+=w*dis[t];
		for(int i=t;i!=s;i=edge[pre[i]^1].to)
		{
			edge[pre[i]].val-=w;
			edge[pre[i]^1].val+=w;
		}
	}
	printf("%d",maxcost);
	return 0;
}
