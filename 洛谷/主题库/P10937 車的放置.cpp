#include<bits/stdc++.h>
#define M 1145
using namespace std;
int mp[M][M],vis[M],match[M],n,m,e,ans;
vector<int>g[M];
bool found(int x)
{
	for(auto v:g[x])
		if(!vis[v])
		{
			vis[v]=1;
			if(!match[v]||found(match[v]))
			{
				match[v]=x;
				return 1;
			}
		}
	return 0;
}
int main()
{
	scanf("%d%d%d",&n,&m,&e);
	for(int i=1,u,v;i<=e;i++)
	{
		scanf("%d%d",&u,&v);
		mp[u][v]=1;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(!mp[i][j])
				g[i].push_back(j+n);
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(found(i))ans++;
	}
	printf("%d",ans);
	return 0;
}
