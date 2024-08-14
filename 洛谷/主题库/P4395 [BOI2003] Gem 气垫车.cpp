#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 11451
using namespace std;
int n,q,cnt,head[M],size[M],f[M][114];
struct node
{
	int nxt,to;
}edge[M<<2];
void addedge(int u,int v)
{
	edge[++cnt].to=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
void dfs(int x,int fa)
{
	for(int i=1;i<=15;++i)f[x][i]=i;
	for(int i=head[x];~i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==fa)continue;
		dfs(v,x);
		for(int j=1,ans;j<=15;++j)
		{
			ans=INF;
			for(int k=1;k<=15;++k)if(j!=k)ans=min(f[v][k],ans);
			f[x][j]+=ans;
		}
	}
}
int main()
{
	memset(head,-1,sizeof head);
	memset(f,INF,sizeof f);
	scanf("%d",&n);
	for(int i=1,x,y;i<n;++i)
	{
		scanf("%d%d",&x,&y);
		addedge(x,y);addedge(y,x);
	}
	dfs(1,-1);
	for(int i=1;i<=15;++i)f[0][0]=min(f[0][0],f[1][i]);
	printf("%d",f[0][0]);
	return 0;
}
