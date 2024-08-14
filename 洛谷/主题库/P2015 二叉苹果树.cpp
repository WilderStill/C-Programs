#include<bits/stdc++.h>
#define M 4154
using namespace std;
int n,q,cnt,head[M],size[M],f[M][M];
struct node
{
	int nxt,to,val;
}edge[M<<2];
void addedge(int u,int v,int w)
{
	edge[++cnt].to=v;
	edge[cnt].nxt=head[u];
	edge[cnt].val=w;
	head[u]=cnt;
}
void dfs(int x,int fa)
{
	for(int i=head[x];~i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==fa)continue;
		dfs(v,x);
		size[x]+=(size[v]+1);
		for(int j=min(size[x],q);j>0;--j)
			for(int k=0;k<=min(size[v],j-1);++k)
				f[x][j]=max(f[x][j],f[x][j-k-1]+f[v][k]+edge[i].val);
	}
}
int main()
{
	memset(head,-1,sizeof head);
	scanf("%d%d",&n,&q);
	for(int i=1,x,y,z;i<n;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z);addedge(y,x,z);
	}
	dfs(1,-1);
	printf("%d",f[1][q]);
	return 0;
}
