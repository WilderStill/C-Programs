#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 114514
using namespace std;
int n,k,cnt,rt,ans=INF,val[M],dp[M][45],f[M][45],head[M];
struct node
{
	int nxt,to;
}edge[M<<1];
void addedge(int u,int v)
{
	edge[++cnt].to=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
void dfs1(int x,int fa)
{
	for(int i=0;i<=k;++i)dp[x][i]=val[x];
	for(int i=head[x];~i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==fa)continue;
		dfs1(v,x);
		for(int i=1;i<=k;i++)dp[x][i]+=dp[v][i-1];
	}
}
void dfs2(int x,int fa)
{
	for(int i=head[x];~i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==fa)continue;
		f[v][1]+=dp[x][0];
		for(int i=2;i<=k;++i)f[v][i]+=f[x][i-1]-dp[v][i-2];
		dfs2(v,x);
	}
}
int main()
{
	memset(head,-1,sizeof head);
	scanf("%d%d",&n,&k);
	rt=1;
	for(int i=1,x,y;i<n;++i)
	{
		scanf("%d%d",&x,&y);
		addedge(x,y);addedge(y,x);
	}
	for(int i=1;i<=n;++i)scanf("%d",&val[i]);
	dfs1(rt,-1);
	memcpy(f,dp,sizeof(f));
	dfs2(rt,-1);
	for(int i=1;i<=n;++i)printf("%d\n",f[i][k]);
	return 0;
}
