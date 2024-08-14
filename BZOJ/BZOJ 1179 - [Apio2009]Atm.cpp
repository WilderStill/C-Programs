#include<bits/stdc++.h>
#define M 5145141
using namespace std;
int n,m,val[M],u[M],v[M],head1[M],head2[M],dfn[M],low[M],scc[M],scclen[M],dp[M],ans,sccnum,tot,tim,cnt,s;
stack<int>st;
bool inst[M];
struct edge
{
	int to,nxt;
}edge1[M],edge2[M];
void add_edge1(int x,int y)
{
	edge1[++tot].to=y;
	edge1[tot].nxt=head1[x];
	head1[x]=tot;
}
void add_edge2(int x,int y)
{
	edge2[++cnt].to=y;
	edge2[cnt].nxt=head2[x];
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
			scclen[sccnum]+=val[t];
			if(x==t)break;
		}
	}
}
queue<int>q;
int in[M];
void dfs(int s)
{
 	for(int i=1;i<=sccnum;i++)if(!in[i])q.push(i);
	dp[s]=val[s];
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int i=head2[u];i;i=edge2[i].nxt)
		{
			int v=edge2[i].to;
			dp[v]=max(dp[v],dp[u]+val[v]);
			if(--in[v]==0)q.push(v);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		add_edge1(u[i],v[i]);
	}
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	for(int i=1,tmp;i<=n;i++)scanf("%d",&tmp),val[scc[i]]+=tmp;;
	for(int i=1;i<=m;i++)
		if(scc[u[i]]!=scc[v[i]])
		{
			add_edge2(scc[u[i]],scc[v[i]]);
			in[scc[v[i]]]++;
		}
	memset(dp,-0x3f3f3f3f,sizeof(dp));
	scanf("%d",&s);
	dfs(scc[s]);
	int p,x;
	scanf("%d",&p);
	while(p--)
	{
		scanf("%d",&x);
		ans=max(ans,dp[scc[x]]);
	}
	printf("%d",ans);
}
