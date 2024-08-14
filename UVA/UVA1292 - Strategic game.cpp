#include<bits/stdc++.h>
#define M 1514
using namespace std;
int n,cnt,rt,f[M][2],head[M],ind[M];
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
	f[x][0]=0,f[x][1]=1;
	for(int i=head[x];~i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==fa)continue;
		dfs(v,x);
		f[x][1]+=min(f[v][0],f[v][1]);
		f[x][0]+=f[v][1];
	}
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		memset(f,0x3f3f3f3f,sizeof f);
		memset(head,-1,sizeof head);
		memset(ind,0,sizeof ind);
		cnt=0;
		memset(edge,0,sizeof edge);
		for(int i=1,id,k;i<=n;++i)
		{
			scanf("%d:(%d)",&id,&k);
			for(int j=1,x;j<=k;++j)
			{
				scanf("%d",&x);
				addedge(id,x);addedge(x,id);
				++ind[x];
			}
		}
		for(int i=0;i<n;++i)
			if(!ind[i])
			{
				rt=i;
				break;
			}
		dfs(rt,-1);
		printf("%d\n",min(f[rt][0],f[rt][1]));
	}
	return 0;
}
