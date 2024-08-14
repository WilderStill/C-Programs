#include<bits/stdc++.h>
#define M 511451 
using namespace std;
struct node
{
    int data,nxt;
}e[M*2];
int head[500010],t;
void add(int x,int y)
{
	e[++t].data=y;
	e[t].nxt=head[x];
	head[x]=t;
}
int d[M],f[M][22],lg[M];
void dfs(int now,int fa)
{
	f[now][0]=fa;
	d[now]=d[fa]+1;
	for(int i=1;i<=lg[d[now]];i++)
		f[now][i] = f[f[now][i-1]][i-1];
	for(int i=head[now];i;i=e[i].nxt)
		if(e[i].data!=fa)
			dfs(e[i].data,now);
}
int LCA(int x, int y)
{
	if(d[x]<d[y]) swap(x,y);
	while(d[x]>d[y])
		x=f[x][lg[d[x]-d[y]]-1];
	if(x==y) return x;
	for(int k=lg[d[x]]-1;k>=0;k--)
		if(f[x][k]!=f[y][k])
			x=f[x][k],y=f[y][k];
	return f[x][0];
}
int main()
{
	int n,m,s,x,y;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++)
		lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	dfs(s,0);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",LCA(x,y));
	}
	return 0;
}
