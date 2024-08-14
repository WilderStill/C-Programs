#include<bits/stdc++.h>
#define M 4514114
using namespace std;
int n,m,hd[M],tot;
struct Edge
{
	int from,to,nxt;
}edge[M];
void add(int x,int y)
{
	edge[++tot].nxt=hd[x];
	hd[x]=tot;
	edge[tot].from=x;
	edge[tot].to=y;
}
int dfn[M],low[M],tim,ans;
set<int>Ans[M];
stack<int>st;
void dfs(int x,int eg)
{
	dfn[x]=low[x]=++tim;
	int r=0;
	for(int i=hd[x];i;i=edge[i].nxt)
	{
		if(!dfn[edge[i].to])
		{
			r++;
			st.push(i);
			dfs(edge[i].to,x);
			low[x]=min(low[x],low[edge[i].to]);
			if(low[edge[i].to]>=dfn[x])
			{
				ans++;
				while(1)
				{
					int t=st.top();
					st.pop();
					Ans[ans].insert(edge[t].from);
					Ans[ans].insert(edge[t].to);
					if(t==i)break;
				}
			}
		}
		else if(dfn[edge[i].to]<low[x]&&edge[i].to!=eg)
		{
			st.push(i);
			low[x]=min(low[x],dfn[edge[i].to]);
		}
	}
	if(!eg&&!r)Ans[++ans].insert(x);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		if(x-y)add(x,y),add(y,x);
	}
	for(int i=1;i<=n;i++)if(!dfn[i])dfs(i,0);
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++)
	{
		printf("%d ",Ans[i].size());
		for(auto it:Ans[i])printf("%d ",it);
		printf("\n");
	}
    return 0;
}
