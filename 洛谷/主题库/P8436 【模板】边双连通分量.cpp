#include<bits/stdc++.h>
#define M 4514114
using namespace std;
int n,m,tot=1,ans,tim;
int dfn[M],low[M],hd[M],dcc[M];
struct Edge
{
	int to,nxt;
}edge[M];
bool vis[M];
vector<vector<int> >Ans;
void add(int x,int y)
{
	edge[++tot].to=y;
	edge[tot].nxt=hd[x];
	hd[x]=tot;
}
void tarjan(int x,int eg)
{
	dfn[x]=low[x]=++tim;
	for(int i=hd[x];i;i=edge[i].nxt)
	{
		if(!dfn[edge[i].to])
		{
			tarjan(edge[i].to,i);
			if(dfn[x]<low[edge[i].to])vis[i]=vis[i^1]=1;
			low[x]=min(low[x],low[edge[i].to]);
		}
		else if(i!=(eg^1))low[x]=min(low[x],dfn[edge[i].to]);
	}
}
void dfs(int x,int eg)
{
	dcc[x]=eg;
	Ans[eg-1].push_back(x);
	for (int i=hd[x];i;i=edge[i].nxt)
	{
		if(dcc[edge[i].to]||vis[i])continue;
		dfs(edge[i].to,eg);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		if(x==y)continue;
		add(x,y);add(y,x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i,0);
	for(int i=1;i<=n;i++)
		if(!dcc[i])
		{
			Ans.push_back(vector<int>());
			dfs(i,++ans);
		}
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++)
	{
		printf("%d",Ans[i-1].size());
		for (int j=0;j<Ans[i-1].size();j++)
			printf(" %d",Ans[i-1][j]);
		printf("\n");
	}
	return 0;
}
