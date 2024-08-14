#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define db double
#define pdi pair<double,int>
using namespace std;
struct Node
{
	db x,y,dis;
	int hd,pre;
}node[114514];
struct Edge
{
	int nxt,to; 
	db len;
}edge[114514];
int n,m,tot;
db ans=INF<<1;
void addEdge(int u,int v,db w)
{
	edge[++tot].len=w;
	edge[tot].to=v;
	edge[tot].nxt=node[u].hd;
	node[u].hd=tot;
}
void Dijkstra(int x,int y)
{
	for(int i=1;i<=n;i++)node[i].dis=INF;
	node[1].dis=0;
	priority_queue<pdi,vector<pdi>,greater<pdi> >q;
	q.push({0,1});
	while(!q.empty())
	{
		pdi tmp=q.top();
		q.pop();
		db d=tmp.first;
		int u=tmp.second;
		if(node[u].dis!=d)continue;
		for(int e=node[u].hd;e;e=edge[e].nxt)
		{
			int v=edge[e].to;
			if((u==x&&v==y)||(u==y&&v==x))continue;
			if(node[v].dis<=d+edge[e].len)continue;
			if(x==-1&&y==-1)node[v].pre=u;
			node[v].dis=d+edge[e].len;
			q.push({node[v].dis,v});
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lf%lf",&node[i].x,&node[i].y);
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		db w=sqrt((node[u].x-node[v].x)*(node[u].x-node[v].x)+(node[u].y-node[v].y)*(node[u].y-node[v].y));
		addEdge(u,v,w),addEdge(v,u,w);
	}
	Dijkstra(-1,-1);
	for(int i=n;i!=1;i=node[i].pre)
	{
		Dijkstra(i,node[i].pre);
		ans=min(ans,node[n].dis);
	}
	if(ans>=INF)printf("-1");
	else printf("%.2lf",ans);
	return 0;
}
