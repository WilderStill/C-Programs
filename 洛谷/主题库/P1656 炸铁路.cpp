#include <bits/stdc++.h>
#define M 1145
using namespace std;
int mp[M][M];
struct Edge
{
    int u,v;
    bool operator < (const Edge &b)const
    {
    	if(u==b.u)return v<b.v;
    	return u<b.u;
	}
}edge[M*5];
int dfn[M],low[M],f[M],n,m,tim,tot;
void add(int x,int y)
{
    edge[++tot].u=x;
    edge[tot].v=y;
}
void tarjan(int x)
{
    dfn[x]=low[x]=++tim;
    for(int i=1;i<=n;i++)
        if(mp[x][i])
        {
        	if(dfn[i]&&i!=f[x])low[x]=min(low[x],dfn[i]);
	        if(!dfn[i])
			{
	            f[i]=x;
	            tarjan(i);
	            low[x]=min(low[x],low[i]);
	            if(low[i]>dfn[x])add(x,i);
	        }
		}
}
int main()
{
	scanf("%d%d",&n,&m);
    for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
        mp[x][y]=mp[y][x]=1;
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
			tarjan(i);
    sort(edge+1,edge+tot+1);
    for(int i=1;i<=tot;i++)
    {
    	if(edge[i].u>edge[i].v)swap(edge[i].u,edge[i].v);
		printf("%d %d\n",edge[i].u,edge[i].v);
	}
    return 0;
}
