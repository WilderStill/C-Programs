#include<bits/stdc++.h>
#define M 1145
using namespace std;
struct edge
{
	int nxt,to;
}edge[M<<1];
int n,m,maxdep=0,cnt,hd[M<<1];
bool vis[M];
void addedge(int u,int v)
{
	edge[++cnt].nxt=hd[u];
	edge[cnt].to=v;
	hd[u]=cnt;
}	
void dfs(int x,int depth)
{
	vis[x]=1;
    maxdep=max(maxdep,depth);
	for(int i=hd[x];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(vis[v])continue;
		dfs(v,depth+1);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);addedge(v,u);
	}
	dfs(0,1);
	if(m<maxdep)printf("%d",m+1);
	else printf("%d",min(n,maxdep+(m-maxdep+1)/2));
	return 0;
}
