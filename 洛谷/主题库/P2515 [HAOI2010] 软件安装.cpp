#include<bits/stdc++.h>
#define M 1145
using namespace std;
int dot[M],val[M],cost[M],sccval[M],scccost[M],scc[M],dfn[M],low[M],stk[M],hd[M],in[M],f[M][M],cnt,top,n,m,tim,scccnt;
bool instk[M];
struct node
{
	int to,nxt;
}edge[M];
void addedge(int u,int v)
{
	edge[++cnt].to=v;
	edge[cnt].nxt=hd[u];
	hd[u]=cnt;
}
void tarjan(int x)
{
    dfn[x]=low[x]=++tim;
	stk[++top]=x;
	instk[x]=1;
    for(int i=hd[x];i;i=edge[i].nxt)
	{
        int v=edge[i].to;
        if(!dfn[v])
		{
            tarjan(v); 
            low[x]=min(low[x],low[v]);
        }
		else if(instk[v])low[x]=min(low[x],dfn[v]);
    }
    if(dfn[x]==low[x])
	{
        ++scccnt;
        while(stk[top+1]!=x)
		{
            scc[stk[top]]=scccnt;
            scccost[scccnt]+=cost[stk[top]]; 
            sccval[scccnt]+=val[stk[top]];
            instk[stk[top]]=0;
            --top;
        }
    }
}
void dfs(int x)
{
	for(int i=scccost[x];i<=m;++i)f[x][i]=sccval[x];
    for(int i=hd[x];i;i=edge[i].nxt)
    {
        int v=edge[i].to;
        dfs(v);
        for(int i=m-scccost[x];i>=0;--i) 
            for(int j=0;j<=i;++j)
                f[x][i+scccost[x]]=max(f[x][i+scccost[x]],f[v][j]+f[x][i+scccost[x]-j]);
    }
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&cost[i]);
	for(int i=1;i<=n;++i)scanf("%d",&val[i]);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&dot[i]);
		if(dot[i])addedge(dot[i],i);
	}
	for(int i=1;i<=n;++i)if(!dfn[i])tarjan(i);
	cnt=0;
	memset(hd,0,sizeof hd);
	for(int i=1;i<=n;++i)
    	if(scc[dot[i]]!=scc[i])
		{
    		addedge(scc[dot[i]],scc[i]);
    		++in[scc[i]];
        }
    for(int i=1;i<=scccnt;++i)if(!in[i])addedge(0,i);
	dfs(0);
	printf("%d",f[0][m]);
	return 0;
}
