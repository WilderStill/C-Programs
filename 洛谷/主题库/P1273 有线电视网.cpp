#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 4145
using namespace std;
int f[M][M],val[M],head[M],cnt,n,m;
struct node
{
	int val,to,nxt;
}edge[M*M];
void addedge(int u,int v,int w)
{
	edge[++cnt].to=v;
	edge[cnt].nxt=head[u];
	edge[cnt].val=w;
	head[u]=cnt;
}
int dfs(int x)
{
	if(x>n-m)
	{
		f[x][1]=val[x];
		return 1;
	}
	int sum=0;
	for(int i=head[x];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		int t=dfs(v);sum+=t;
		for(int j=sum;j>=1;--j)
			for(int k=1;k<=t;++k)
				if(j-k>=0)
					f[x][j]=max(f[x][j],f[x][j-k]+f[v][k]-edge[i].val);
	}
	return sum;
}
int main()
{
	memset(f,-INF,sizeof f);
	scanf("%d%d",&n,&m);
	for(int i=1,k;i<=n-m;++i)
	{
		scanf("%d",&k);
		for(int j=1,x,y;j<=k;++j)
		{
			scanf("%d%d",&x,&y);
			addedge(i,x,y);
		}
	}
	for(int i=1;i<=m;++i)scanf("%d",&val[n-m+i]);
	for(int i=1;i<=n;++i)f[i][0]=0;
	dfs(1);
	for(int i=m;i>=1;--i)
		if(f[1][i]>=0)
		{
			printf("%d",i);
			return 0;
		}
	return 0;
}
