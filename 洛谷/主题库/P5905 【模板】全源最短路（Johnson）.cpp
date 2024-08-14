#include<bits/stdc++.h>
#define int long long
#define INF 1000000000
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
inline void write(int x)
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
int m,n,tot,hd[300010],dis[300010],cnt[300010],Dis[300010];
bool vis[300010];
struct edge
{
	int to,nxt,val;
}edge[300010];
struct node
{
	int dis,id;
	bool operator<(const node& b)const{return dis>b.dis;}
	node(int _dis,int _id){dis=_dis,id=_id;}
};
void addedge(int u,int v,int w)
{
	edge[++tot].nxt=hd[u];
	edge[tot].to=v;
	edge[tot].val=w;
	hd[u]=tot;
}
bool SPFA(int s)
{
	queue<int>q;
	memset(dis,0x3f3f3f3f,sizeof dis);
	dis[s]=0,vis[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		vis[top]=0;
		for(int i=hd[top];i;i=edge[i].nxt)
		{
			int v=edge[i].to;
			if(dis[v]>dis[top]+edge[i].val)
			{
				dis[v]=dis[top]+edge[i].val;
				if(!vis[v])
				{
					vis[v]=1;
					q.push(v);
					cnt[v]++;
					if(cnt[v]>n)return 0;
				}
			}
		}
	}
	return 1;
}
void dijkstra(int s)
{
	priority_queue<node>q;
	for(int i=1;i<=300000;++i)Dis[i]=INF;
	memset(vis,0,sizeof(vis));
	Dis[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		node top=q.top();
		q.pop();
		if(vis[top.id])continue;
		vis[top.id]=1;
		for(int i=hd[top.id];i;i=edge[i].nxt)
		{
			int v=edge[i].to;
			if(Dis[v]>Dis[top.id]+edge[i].val)
			{
				Dis[v]=Dis[top.id]+edge[i].val;
				if(!vis[v])q.push({Dis[v],v});
			}
		}
	}
}
signed main()
{
	memset(hd,0,sizeof hd);
	n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
        int u=read(),v=read(),w=read();
        addedge(u,v,w);
    }
    for(int i=1;i<=n;++i)addedge(0,i,0);
    if(!SPFA(0))
    {
    	puts("-1");
    	return 0;
	}
	for(int pos=1;pos<=n;++pos)
    	for(int i=hd[pos];i;i=edge[i].nxt)edge[i].val+=dis[pos]-dis[edge[i].to];
    for(int i=1;i<=n;++i)
	{
		dijkstra(i);
		int ans=0;
		for(int j=1;j<=n;++j)
		{
			if(Dis[j]==INF)ans+=j*INF;
			else ans+=j*(Dis[j]+dis[j]-dis[i]);
		}
		write(ans);
		puts("");
	}
	return 0;
}
