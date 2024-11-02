#include<bits/stdc++.h>
#define M 1145141
using namespace std;
int n,m,u[M],v[M],w[M],head1[M],head2[M],dfn[M],low[M],scc[M],dis[M],ans,sccnum,tot,tim,cnt;
stack<int>st;
bool inst[M];
struct edge
{
	int to,nxt,val;
}edge1[M],edge2[M];
void add_edge1(int x,int y,int z)
{
	edge1[++tot].to=y;
	edge1[tot].nxt=head1[x];
	edge1[tot].val=z;
	head1[x]=tot;
}
void add_edge2(int x,int y,int z)
{
	edge2[++cnt].to=y;
	edge2[cnt].nxt=head2[x];
	edge2[cnt].val=z;
	head2[x]=cnt;
}
void tarjan(int x)
{
	dfn[x]=low[x]=++tim;
	st.push(x);
	inst[x]=1;
	for(int i=head1[x];i;i=edge1[i].nxt)
	{
		if(!dfn[edge1[i].to])
		{
			tarjan(edge1[i].to);
			low[x]=min(low[x],low[edge1[i].to]);
		}
		else if(inst[edge1[i].to])
			low[x]=min(low[x],dfn[edge1[i].to]);
	}
	if(dfn[x]==low[x])
	{
		sccnum++;
		while(true)
		{
			int t=st.top();
			st.pop();
			inst[t]=0;
			scc[t]=sccnum;
			if(x==t)break;
		}
	}
}
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		add_edge1(u[i],v[i],w[i]);
	}
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	for(int i=1;i<=m;i++)
		if(scc[u[i]]!=scc[v[i]])
			add_edge2(scc[u[i]],scc[v[i]],w[i]);
	memset(dis,0x3f,sizeof dis);
	int s=scc[1];
	dis[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		auto top=q.top();
		q.pop();
		int val=top.first,tp=top.second;
		if(val!=dis[tp])continue;
		for(int i=head2[tp];i;i=edge2[i].nxt)
		{
			int to=edge2[i].to;
			if(dis[to]>val+edge2[i].val)
			{
				dis[to]=val+edge2[i].val;
				q.push({dis[to],to});
			}
		}
	}
	printf("%d",dis[scc[n]]);
	return 0;
}
