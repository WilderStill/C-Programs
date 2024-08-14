#include<bits/stdc++.h>
#define MAXN 114514
using namespace std;
struct node
{
	int u;
	int v;
}nd[MAXN];
int h[MAXN],fa[MAXN],w[MAXN],n,s,t=0,ans=0;
void addEdge(int x,int y)
{
	nd[++t].u=h[x];
	nd[t].v=y;
	h[x]=t;
}
void dfs(int x,int d)
{
	if(d>s) return;
	if(d==s)
	{
		ans++;
		return;
	}
	for(int i=h[x];i;i=nd[i].u)
	{
		int nxt=nd[i].v;
		if(fa[x]!=nxt)
		    dfs(nxt,d+w[nxt]);
	}
}

int main()
{
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		addEdge(x,y);
		fa[y]=x;
	}
	for(int i=1;i<=n;i++) dfs(i,w[i]);	
	printf("%d",ans);
	return 0;
}
