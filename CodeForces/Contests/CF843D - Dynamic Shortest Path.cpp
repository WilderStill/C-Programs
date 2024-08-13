#include<bits/stdc++.h>
#define ll long long
const ll INF=0x3f3f3f3f3f3f3f3f;
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void write(ll x)
{
    if(x<0)
	{
        putchar('-');
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
int m,n,q,tot,hd[100010];
ll dis[100010],Dis[100010];
bool vis[100010];
struct edge
{
	int to,nxt,val;
}edge[100010];
void addedge(int u,int v,int w)
{
	edge[++tot].nxt=hd[u];
	edge[tot].to=v;
	edge[tot].val=w;
	hd[u]=tot;
}
void dijkstra(int s)
{
	priority_queue<pair<long long,int>>qe;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	qe.push({0,s});
	while(!qe.empty())
	{
		int top=qe.top().second;
		qe.pop();
		if(vis[top])continue;
		vis[top]=1;
		for(int i=hd[top];i;i=edge[i].nxt)
		{
			int v=edge[i].to;
			if(dis[v]>dis[top]+edge[i].val)
			{
				dis[v]=dis[top]+edge[i].val;
				qe.push({-dis[v],v});
			}
		}
	}
}
queue<int>qs[100010];
ll maxs;
void search(int s)
{
	maxs=0;
	for(int i=0;i<=maxs;++i)
	{
		while(!qs[i].empty())
		{
			int top=qs[i].front();
			qs[i].pop();
			if(Dis[top]<i)continue;
			for(int i=hd[top];i;i=edge[i].nxt)
			{
				int v=edge[i].to,val=dis[top]+edge[i].val-dis[v];
				if(Dis[v]>Dis[top]+val)
				{
					Dis[v]=Dis[top]+val;
					if(Dis[v]<=min(s,n-1))
					{
						qs[Dis[v]].push(v);
						maxs=max(maxs,Dis[v]);
					}
				}
			}
		}
	}
}
signed main()
{
	n=read();m=read();q=read();
	for(int i=1;i<=m;++i)
	{
        int u=read(),v=read(),w=read();
        addedge(u,v,w);
    }
    dijkstra(1);
    for(int i=1;i<=q;++i)
    {
    	int op=read(),x=read();
    	if(op==1)
    	{
    		if(dis[x]==INF)puts("-1");
    		else printf("%lld\n",dis[x]);
		}
		else
		{
			for(int i=1;i<=x;++i)edge[read()].val++;
			memset(Dis,0x3f,sizeof Dis);
			Dis[1]=0;
			qs[0].push(1); 
			search(x);
			for(int i=1;i<=n;i++)dis[i]=min(INF,Dis[i]+dis[i]);
		}
	}
	return 0;
}
