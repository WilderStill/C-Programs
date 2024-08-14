#include<bits/stdc++.h>
#define M 1145
using namespace std;
int mp[M][M],vis[M],match[M],n,m,T,ans;
bool found(int x)
{
	for(int i=1;i<=n;i++)
		if(mp[x][i])
		{
			if(vis[i])continue;
			vis[i]=1;
			if(!match[i]||found(match[i]))
			{ 
				match[i]=x; 
				return 1;
			}
		} 
	return 0;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		memset(mp,0,sizeof(mp));
		memset(match,0,sizeof(match));
		scanf("%d%d",&n,&m);
		for(int i=1,u,v;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			mp[u][v]=1;
		}
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(found(i))ans++;
		}
		printf("%d\n",n-ans);	
	}
	return 0;
}
