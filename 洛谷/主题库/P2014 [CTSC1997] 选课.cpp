#include<bits/stdc++.h>
#define M 1145
using namespace std;
int val[M],head[M],f[M][M],cnt,n,m;
struct node
{
	int to,nxt;
}edge[M];
void addedge(int u,int v)
{
	edge[++cnt].to=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
void dfs(int x)
{
	f[x][1]=val[x];
	for(int i=head[x];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		dfs(v);
		for(int j=m+1;j>=1;--j)
			for(int k=1;k<j;++k)
				f[x][j]=max(f[x][j],f[x][j-k]+f[v][k]);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=n;++i)
	{
		scanf("%d%d",&x,&y);
		addedge(x,i);
		val[i]=y;
	}
	dfs(0);
	printf("%d",f[0][m+1]);
	return 0;
}
