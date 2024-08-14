#include<bits/stdc++.h>
#define M 4514114
using namespace std;
int n,m,tot,Rr;
vector<int>edge[M];
int dfn[M],low[M],tim,ans,buk[M];
void dfs(int x)
{
	dfn[x]=low[x]=++tim;
	int r=0;
	for(auto i:edge[x])
	{
		if(!dfn[i])
		{
			r++;
			dfs(i);
			low[x]=min(low[x],low[i]);
			if(low[i]>=dfn[x]&&Rr!=x)ans+=(!buk[x]),buk[x]=1;
		}
		else low[x]=min(low[x],dfn[i]);
	}
	if(Rr==x&&r>=2)ans+=(!buk[x]),buk[x]=1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for(int i=1;i<=n;i++)if(!dfn[i])Rr=i,dfs(i);
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	{
		if(buk[i])printf("%d ",i);
	}
    return 0;
}
