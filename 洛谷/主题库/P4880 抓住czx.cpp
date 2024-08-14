#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 1145141
using namespace std;
int n,m,b,e,T,tot,hd[M],dis[M];
bool vis[M];
struct edgenode
{
	int to,v,nxt;
}edge[M];
struct timenode
{
	int start,end,node;
}t[M];
void add_edge(int u,int v,int w)
{
	edge[++tot].nxt=hd[u];
	edge[tot].to=v;
	edge[tot].v=w;
	hd[u]=tot;
}
void spfa(int s)
{
	queue<int>q;
	memset(dis,INF,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[s]=0;
	q.push(s);
	vis[s]=1;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=hd[u];i;i=edge[i].nxt) 
		{
			int v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].v)
			{
				dis[v]=dis[u]+edge[i].v;
				if(!vis[v])
				{
					q.push(v);
					vis[v]=1;
				}
			}
		}
			
	}
}
bool cmp(timenode a,timenode b){return a.start<b.start;}
int main()
{
	scanf("%d%d%d%d",&n,&m,&b,&e);
	t[1].start=1;t[1].node=e;
	for(int i=1,u,v,w;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w); 
		add_edge(u,v,w);add_edge(v,u,w);
	}
	scanf("%d",&T);
	T++;
	spfa(b);
	for(int i=2,time,place;i<=T;i++)
	{
		scanf("%d%d",&time,&place);
		t[i].start=time;
		t[i].node=place;
	}
	sort(t+1,t+T+1,cmp) ;
	for(int i=2;i<=T;i++)t[i-1].end=t[i].start-1;
	t[T].end=INF;
	for(int i=1;i<=T;i++) 
		if(dis[t[i].node]<=t[i].end){printf("%d\n",max(dis[t[i].node],t[i].start));break;}
	return 0;
}
