#include<bits/stdc++.h>
#define M 1145
using namespace std;
int mp[M][M],vis[M],match[M],n,m,e,ans;
bool found(int x)
{
	for(int i=1;i<=m;i++)
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
	scanf("%d%d",&n,&m);
	for(int i=1,e;i<=n;i++)
	{
		scanf("%d",&e);
		for(int j=1,u;j<=e;j++)scanf("%d",&u),mp[i][u]=1;
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(found(i))ans++;
	}
	printf("%d",ans);
	return 0;
}
